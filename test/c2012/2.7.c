// RUN: %clang -std=c99 -Wunused-parameter -fsyntax-only -ferror-limit=0 -Xclang -verify %s

// expected-warning@+1 {{unused parameter 'unused'}}
void f(int *used, int unused) {
  *used = 42;
}
