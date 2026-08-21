# Freezer

Freezer is a lightweight Deezer Web wrapper for Arch Linux:

- US SOCKS5 proxy via WireProxy
- Adblock list for Deezer domains
- Persistent login (QtWebEngine profile)
- Wayland-friendly, X11 fallback
- Packaged as an Arch package (PKGBUILD)

## Build

```bash
sudo pacman -S --needed base-devel cmake ninja qt6-base qt6-webengine wireproxy
git clone https://github.com/UnknownSkittle/freezer.git
cd freezer
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build
sudo cmake --install build
