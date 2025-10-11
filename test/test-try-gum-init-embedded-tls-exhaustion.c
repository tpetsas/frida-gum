/*
 * Compile with:
 *
 * clang++ -DHAVE_FDOPEN -Dfdopen=fdopen -Wno-macro-redefined frida-gumjs-example.c -o frida-gumjs-example -L. -lfrida-gumjs -ldl -lm -lresolv
 *
 * Visit https://frida.re to learn more about Frida.
 */

#include "frida-gumjs.h"

#include <fcntl.h>

extern gboolean glib_is_available (void);


static void exhaust_tls_keys (gboolean release_after) {
  // macOS TLS key limit is 512 (NOTE: the actual limit measured as 501)
  long max_keys = sysconf(_SC_THREAD_KEYS_MAX);
  printf("max keys: %ld\n", max_keys);
  size_t ok = 0;
  pthread_key_t keys[max_keys]; // cap what you probe
  while (ok < sizeof(keys)/sizeof(keys[0])) {
    int r = pthread_key_create(&keys[ok], NULL);
    if (r != 0) {
      printf("TLS key limit reached!\n");
      break; // EAGAIN or ENOMEM
    }
    ok++;
  }
  if (release_after) {
    for (size_t i = 0; i < ok; i++)
      pthread_key_delete(keys[i]);
  }
}

int
main (int argc,
      char * argv[])
{
  g_printerr ("[debug] glib_is_available() = %d\n", glib_is_available ());
  
  exhaust_tls_keys(0);
  gum_init_embedded ();

  GError *err = NULL;
  if (!try_gum_init_embedded (&err)) {
    g_printerr ("try_gum_init_embedded() failed: %s\n", err->message);
    g_clear_error (&err);
    return 1;
  }

  gum_deinit_embedded ();

  return 0;
}

