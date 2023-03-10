// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1;
  for (int i = 0; i < n; i++) {
    res *= value;
  }
  return res;

}

uint64_t fact(uint16_t n) {
  if (n == 1) {
    return 1;
  }
  else {
    return n * fact(n - 1);
  }
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double e = 1;
  for (int i = 1; i < count; i++) {
    e += calcItem(x, i);
  }
  return e;
}

double sinn(double x, uint16_t count) {
  double s = 0;
  uint16_t n = 0;
  for (int i = 1; i <= count*2; i = i + 2) {
    s += pown(-1, n++) * calcItem(x, i);
  }
  return s;
}

double cosn(double x, uint16_t count) {
  double c = 1;
  uint16_t n = 1;
  for (int i = 2; i <= count * 2 - 1; i = i + 2) {
    c += pown(-1, n++) * calcItem(x, i);
  }
  return c;
}
