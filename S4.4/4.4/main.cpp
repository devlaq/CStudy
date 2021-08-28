#include <cstdio>
#include <algorithm>

int main() {
    int n, w, fishes[100], _max = 0;
    scanf("%d %d", &n, &w);

    for(int i = 0; i < n; i++) {
        scanf("%d", &fishes[i]);
    }

    for(int i = 0; i <= n-w; i++) {
        int sum = 0;
        for(int j = i; j < i+w; j++) {
            sum += fishes[j];
            //printf("%d ", fishes[j]);
        }
        //printf("\n");
        if(sum > _max) _max = sum;
    }

    printf("%d", _max);

    return 0;
}
