{
  description = "An over-engineered Hello World in C";

  # Nixpkgs / NixOS version to use.
  inputs.nixpkgs.url = "nixpkgs/nixos-21.05";

  outputs = { self, nixpkgs }:
    let

      # Generate a user-friendly version number.
      version = builtins.substring 0 8 self.lastModifiedDate;

      # System types to support.
      supportedSystems = [ "x86_64-linux" "x86_64-darwin" "aarch64-linux" "aarch64-darwin" ];

      # Helper function to generate an attrset '{ x86_64-linux = f "x86_64-linux"; ... }'.
      forAllSystems = nixpkgs.lib.genAttrs supportedSystems;

      # Nixpkgs instantiated for supported system types.
      nixpkgsFor = forAllSystems (system: import nixpkgs { inherit system; overlays = [ self.overlay ]; });

    in

    {

      # A Nixpkgs overlay.
      overlay = final: prev: {

        hello = with final; stdenv.mkDerivation rec {
          name = "hello-${version}";

          src = lib.cleanSource ./.;

          nativeBuildInputs = [ cmake ];
          buildInputs = [
            gbenchmark
          ];
          buildPhase = "make -j $NIX_BUILD_CORES";
          installPhase = ''
            mkdir -p $out/bin
            mv gsw_bench $out/bin
          '';
        };

      };

      # Provide some binary packages for selected system types.
      packages = forAllSystems (system:
        {
          inherit (nixpkgsFor.${system}) hello;
        });

      # The default package for 'nix build'. This makes sense if the
      # flake provides only one package or there is a clear "main"
      # package.
      defaultPackage = forAllSystems (system: self.packages.${system}.hello);

      defaultApp = forAllSystems (system: {
        type = "app";
        program = "${self.packages.${system}.hello}/bin/gsw_bench";
      });

      # Tests run by 'nix flake check' and by Hydra.
      checks = forAllSystems
        (system:
          with nixpkgsFor.${system};

          {
            inherit (self.packages.${system}) hello;

            # Additional tests, if applicable.
            test = stdenv.mkDerivation {
              name = "hello-test-${version}";

              buildInputs = [ hello ];

              unpackPhase = "true";

              buildPhase = ''
                echo 'running some integration tests'
                [[ $(hello) = 'Hello Nixers!' ]]
              '';

              installPhase = "mkdir -p $out";
            };
          }

        );

    };
}
