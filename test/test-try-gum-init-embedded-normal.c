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

int
main (int argc,
      char * argv[])
{
  g_printerr ("[debug] glib_is_available() = %d\n", glib_is_available ());
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

