#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define DEBUG

int n, M;
int m[100], c[100];

int sol = INT_MAX;
bool selected[100] = { false };

void debug(const char* __format, ...) {
    #ifdef DEBUG
    printf(__format);
    #endif // DEBUG
}

void input() {
    scanf("%d %d", &n, &M);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
}

void solve(int byte, int sc) {
    if(byte >= M) {
        debug("Riched target. sc: %d\n", sc);
        if(sol > sc) {
            debug("New record. previous: %d / new: %d\n", sol, sc);
            sol = sc;
        }
    }

    for(int i = 0; i < n; i++) {
        if(selected[i]) continue;
        selected[i] = true;
        solve(byte+m[i], sc+c[i]);
        selected[i] = true;
    }
}

void output() {
    printf("%d", sol);
}

int main() {
    input();
    solve(0, 0);
    output();
    return 0;
}
