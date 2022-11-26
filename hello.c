#include <stdio.h>
#include <time.h>

/*
  fib(5) -> f3 + fib(4, f3)
                    fib(4) -> f3 + fib(2)
  fib(3) -> fib(2) + fib(1)
  fib(2) -> fib(1) + 1
*/
int fast_fib(int n, int prev_fib) {
  if (n <= 1) {
    return 1;
  }

  int n2 = prev_fib > 0 ? prev_fib : fast_fib(n-2, 0);
  // const current_fib = fib(n-2)
  return n2 + fast_fib(n-1, n2);
}

int fib2(int n) {
  return fast_fib(n, 0);
}


int fib(int n) {
  if (n <= 1) {
    return 1;
  }

  return fib(n-1) + fib(n-2);
}


void bench_end(float start, char* title) {
  float end_time = (float) clock() / CLOCKS_PER_SEC;
  float time_elapsed = end_time - start;

  printf("Bench: %s -> %f \n\n", title, time_elapsed);
}

int main(void) {
  // printf("Hello mother fuckers what's up");
  const int i = 42;

  float start_time = (float) clock() / CLOCKS_PER_SEC;
  const int a = fib(i);
  bench_end(start_time, "slow fib");

  start_time = (float) clock() / CLOCKS_PER_SEC;
  const int b = fib2(i);
  bench_end(start_time, "fast fib");
  
  printf("fib(%u) -> %u | %u", i, a, b);
}


