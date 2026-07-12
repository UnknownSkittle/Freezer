# Maintainer: Unknown_Skittle SkittleAlt@proton.me
pkgname=freezer
pkgver=0.1.0
pkgrel=1
pkgdesc="Deezer Web wrapper with US proxy and adblock"
arch=('x86_64')
url="https://github.com/yourname/freezer"
license=('MIT')
depends=('qt6-base' 'qt6-webengine' 'wireproxy')
makedepends=('cmake' 'ninja' 'base-devel')
source=("git+https://github.com/yourname/freezer.git")
md5sums=('SKIP')

build() {
  cd "$srcdir/freezer"
  cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
  cmake --build build
}

package() {
  cd "$srcdir/freezer"
  DESTDIR="$pkgdir" cmake --install build

  # install launcher script
  install -Dm755 scripts/freezer-launch.sh "$pkgdir/usr/bin/freezer"
}
