#include <cstdio>
#include <climits>
#include <ctime>
#include <cstdlib>

//#define DEBUG

int a, b, m = INT_MAX; // start, target, min
bool visit[40];
int buttons[6] = {
    10, 5, 1,
    -1, -5, -10
};

void debug(const char* __format, ...) {
    #ifdef DEBUG
    printf(__format);
    #endif // DEBUG
}

void input() {
    scanf("%d %d", &a, &b);
}

bool solve(int v, int count) {
    debug("v: %d, count: %d\n", v, count);
    if(count > m) return false;
    if(v == b) {
        debug("Rich target: %d of search\n", count);
        if(count < m) {
            debug("New record: %d\n", count);
            m = count;
        }
        return true;
    }

    for(int i = 0; i < 6; i++) {
        if(v+buttons[i] <= 40 && v+buttons[i] >= 0 && !visit[v+buttons[i]]) {
            visit[v+buttons[i]] = true;
            //_sleep(100);
            if(solve(v+buttons[i], count+1)) {
                visit[v+buttons[i]] = false;
                continue;
            }
            visit[v+buttons[i]] = false;
        }
    }

    return false;
}

int main() {
    input();
    visit[a] = true;
    solve(a, 0);
    printf("%d", m);
}
