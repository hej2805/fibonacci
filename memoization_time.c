#include <stdio.h>
#include <time.h>

long long f(int n, long long memo[]) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n]; 
    return memo[n] = f(n - 1, memo) + f(n - 2, memo);
}

int main() {
    int n = 40;
    clock_t start, end;
    double time_used;

    long long memo[41];
    for (int i = 0; i < 41; i++) memo[i] = -1;
    start = clock();
    printf("fib_memo(%d) = %lld\n", n, f(n, memo));
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Memoization Time: %.3f sec\n", time_used);

    return 0;
}
