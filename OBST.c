#include <stdio.h>
#include <limits.h>

#define N 4

float p[N + 1] = { 0, 0.1, 0.2, 0.4, 0.3 };

float sum(int i, int j) {
    float s = 0;
    for (int k = i; k <= j; k++)
        s += p[k];
    return s;
}

float reOBST(int i, int j) {
    if (i > j) return 0;
    if (i == j) return p[i];

    printf("재귀 호출: OBST(%d, %d)\n", i, j);

    float minCost = INT_MAX;
    for (int r = i; r <= j; r++) {
        float cost = reOBST(i, r - 1) + reOBST(r + 1, j) + sum(i, j);
        if (cost < minCost)
            minCost = cost;
    }

    return minCost;
}

int main() {
    float result = reOBST(1, N);
    printf("최적 이진 검색 트리 최소 비용 (DP 없이): %.2f\n", result);
    return 0;
}
