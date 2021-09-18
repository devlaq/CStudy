#include <cstdio>
#include <cmath>
#include <algorithm>

#define DEBUG

int n, arr[1000], arrc=0;

void debug(const char* a, ...) {
    printf(a);
}

void input() {
    scanf("%d", &n);
}

bool isPrimeNumber(int n) {
    if(n <= 1) return false;
    for(int i = 2; i < n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

bool solve(int n) {
    if(n < 10) return isPrimeNumber(n);
    else return isPrimeNumber(n) && solve(n / 10);
}

void loop() {
    int range_a = pow(10, n-1);
    int range_b = pow(10, n) - 1;

    for(int i = range_a; i < range_b; i++) {
        if(solve(i)) {
            arr[arrc++] = i;
        }
    }
}

void output() {
    //std::sort(arr, arr+arrc);

    for(int i = 0; i < arrc; i++) {
        printf("%d\n", arr[i]);
    }
    printf("%d", arrc);
}

int main() {
    input();
    loop();
    output();
    return 0;
}
