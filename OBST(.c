#include <stdio.h>
#include <limits.h>

#define N 4

float p[N + 1] = { 0, 0.1, 0.2, 0.4, 0.3 };
float cost[N + 1][N + 1] = { 0 };

float sum(int i, int j) {
    float s = 0;
    for (int k = i; k <= j; k++)
        s += p[k];
    return s;
}


float optimalBST() {
    for (int i = 1; i <= N; i++)
        cost[i][i] = p[i];
    
    for (int L = 2; L <= N; L++) {
        for (int i = 1; i <= N - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            for (int r = i; r <= j; r++) {
                float c = ((r > i) ? cost[i][r - 1] : 0) + ((r < j) ? cost[r + 1][j] : 0) + sum(i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
            printf("cost[%d][%d]=%.2f\n", i, j, cost[i][j]);
        }
    }
    return cost[1][N];
}

int main() {
    printf("최적 이진 검색 트리 최소 비용: %.2f\n", optimalBST());
    return 0;
}
