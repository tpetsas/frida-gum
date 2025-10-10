# for testing on macOS
export CFLAGS="-DHAVE_FDOPEN -Dfdopen=fdopen -Wno-macro-redefined"

source .venv/bin/activate

rm -rf deps

python releng/deps.py build -v --only glib

