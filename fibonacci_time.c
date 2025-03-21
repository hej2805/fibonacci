#include<stdio.h>
#include<time.h>

int f(int n) {
	if (n == 0)return 0;
	if (n == 1)return 1;
	return f(n - 1) + f(n - 2);
}

int main() {
	int n = 40;
	clock_t start, end;
	double time_used;

	start = clock();
	printf("fib_recursive(%d) = %d\n", n, f(n));
	end = clock();
	time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Recursive Time: %.3f sec\n", time_used);

	return 0;
}
