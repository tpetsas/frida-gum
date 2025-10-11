cc ./test/test-sync-script.c \
  -I./build/bindings/gumjs/devkit \
  ./build/bindings/gumjs/devkit/libfrida-gumjs.a \
  -lresolv \
  -o test-sync-script


cc ./test/test-try-gum-init-embedded-normal.c \
  -I./build/bindings/gumjs/devkit \
  ./build/bindings/gumjs/devkit/libfrida-gumjs.a \
  -lresolv \
  -o test-try-gum-init-embedded-normal

cc ./test/test-try-gum-init-embedded-tls-exhaustion.c \
  -I./build/bindings/gumjs/devkit \
  ./build/bindings/gumjs/devkit/libfrida-gumjs.a \
  -lresolv \
  -o test-try-gum-init-embedded-tls-exhaustion


