#include <cstdio>
#include <algorithm>

int main() {
    // -- n, m, w, h 입력 시작
    int n, m;
    scanf("%d %d", &n, &m);
    int w, h;
    scanf("%d %d", &w, &h);
    // -- n, m, w, h 입력 끝

    // -- arr 2d 동적 할당 시작
    int **arr = new int*[n];
    for(int i = 0; i < n; i++)
        arr[i] = new int[m];
    // -- arr 2d 동적 할당 끝

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int _max = 0;

    for(int i = 0; i <= n-w; i++) {
        for(int j = 0; j <= m-h; j++) {
            int sum = 0;
            for(int k = i; k < i+w; k++) {
                for(int l = j; l < j+h; l++) {
                    sum += arr[k][l];
                }
            }
            if(sum > _max) _max = sum;
        }
    }

    printf("%d", _max);
}
