#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int iabs(int x) { return  (x < 0) ? -x : x; }

int eu_mod(int x, int y) {
  int r = 0;
  assert(y != 0);
  r = x % y;
  if (r < 0) r += iabs(y);
  return r;
}

int gcd(int x, int y) {
  while(y != 0) {
    int tmp = x;
    x = y;
    y = eu_mod(tmp, y);
  };
  return x;
}

void read_input(int* px, int* py) {
  printf("Please enter numbers x ad y: ");

  int nitems = scanf("%d%d", px, py);
  if (nitems != 2) {
    printf("Error in input values\n");
    abort();
  }
}

int main() {
int x, y, res;
  read_input(&x, &y);
  res = gcd(x, y);
  printf("greates common divisor of x and y is %d \n", res); 
  return 0;
}
