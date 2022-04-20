#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }
    double rootFive = sqrt(5);
    double phi = (1+rootFive)/2;
    double f = (pow(phi,n)- pow(-phi,-n))/rootFive;
    return static_cast<int64_t>(round(f));
  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;

    for(int i = 0; i < n; i++) {
      fib_curr += fib_prev;
      fib_prev = fib_curr - fib_prev;
    }
    return fib_prev;
  }

  int64_t fib_recursive(int n) {

    if (n==0){
      return 0;
    }
    if (n==1){
      return 1;
    }
    return fib_recursive(n-2)+ fib_recursive(n-1);
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] != -1) {
      cache[0]=0;
      cache[1]=1;
      return cache[n];
    }
    cache[n]= fib_recursive_memoization(n-1,cache)+ fib_recursive_memoization(n-2,cache);
    return cache[n];



  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }
    return matrix_power(FibMatrix,n)[0][1];

  }

}  // namespace assignment