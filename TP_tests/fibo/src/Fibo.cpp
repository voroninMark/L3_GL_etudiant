#include "Fibo.hpp"

int fibo(int n, int f0, int f1) {
    return n<=0 ? f0 : fibo(n-1, f1, f1+f0);
}

