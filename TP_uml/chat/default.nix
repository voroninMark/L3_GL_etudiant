{ stdenv, cmake, pkgconfig, sfml, gnome, boost }:

stdenv.mkDerivation {
    name = "chat";
    src = ./.;
    nativeBuildInputs = [ cmake pkgconfig ];
    buildInputs = [ sfml gnome.gtkmm boost ];
} 
