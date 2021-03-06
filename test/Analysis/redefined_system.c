// RUN: %clang_cc1 -analyze -analyzer-checker=unix,core,alpha.security.taint -w -verify %s

// Make sure we don't crash when someone redefines a system function we reason about.

char memmove ();
char malloc();
char system();
char stdin();
char memccpy();
char free();
char strdup();
char atoi();

int foo () {
  return memmove() + malloc() + system() + stdin() + memccpy() + free() + strdup() + atoi();

}
