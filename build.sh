# for testing on macOS
export CFLAGS="-DHAVE_FDOPEN -Dfdopen=fdopen -Wno-macro-redefined"

source .venv/bin/activate

rm -rf deps

python releng/deps.py build -v --only glib

rm -rf build
./configure --enable-gumjs --with-devkits=gumjs,gum --disable-v8 --enable-fallible-gprivate
make
