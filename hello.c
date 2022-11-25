#include <stdio.h>


int fib(int n) {
  if (n <= 1) {
    return 1;
  }

  return fib(n-1) + fib(n-2);
}


int main(void) {
  printf("Hello mother fuckers what's up");
  const int i = 42;
  const int a = fib(i);
  
  printf("fib(%u) -> %u", i, a);
}


