#include<stdio.h>

#define MAX 100
int memo[MAX];

int f(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	if (memo[n] != -1)return memo[n];

	return memo[n] = f(n - 1) + f(n - 2);
}

int main() {
	for (int i = 0; i < MAX; i++)memo[i] = -1;

	printf("%d\n", f(6));
	return 0;
}