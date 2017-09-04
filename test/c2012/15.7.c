// RUN: %python %S/../check_clang_tidy.py %s misra-c2012-15.7 %t

int f(int x);

int f(int x) {
  // CHECK-MESSAGES: [[@LINE+1]]:3: warning: All if ... else if constructs shall be terminated with an else statement [misra-c2012-15.7]
  if (x == 0) { // Non-compliant (1)
    x = 1;
  } else if (x == 1) {
    x = 2;
  } else if (x == 2) {
    x = 3;
  }

  if (x == 3) { // Compliant (1)
    x = 4;

    // CHECK-MESSAGES: [[@LINE+1]]:5: warning: All if ... else if constructs shall be terminated with an else statement [misra-c2012-15.7]
    if (x == 5) { // Non-compliant (2)
      x = 6;
    } else if (x == 6) {
      x = 7;
    }
  }

  if (x == 4) { // Compliant (2)
    x = 5;
  } else if (x == 5) {
    x = 6;
  } else {
    x = 7;

    // CHECK-MESSAGES: [[@LINE+1]]:5: warning: All if ... else if constructs shall be terminated with an else statement [misra-c2012-15.7]
    if (x == 8) { // Non-compliant (3)
      x = 9;

      if (x == 10) { // Compliant (3)
        x = 11;
      } else if (x == 11) {
        x = 12;
      } else {
        x = 13;
      }
    } else if (x == 9) {
      x = 10;
    }
  }

  return x;
}
