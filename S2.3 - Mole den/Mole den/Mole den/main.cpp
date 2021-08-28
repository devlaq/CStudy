#include <cstdio>
#include <algorithm>
#include <queue>

struct Point {
    int x;
    int y;
};

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int n, data[30][30], size[30] = { 0 }, count = 2;

void input() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &data[i][j]);
        }
    }
}

bool safe(int x, int y) {
    return (0 <= x && x < n) && (0 <= y && y < n);
}

void asdf(int x, int y, int id) {
    std::queue<Point> q;

    q.push((Point) { x, y });
    while(!q.empty()) {
        Point current = q.front(); q.pop();
        data[current.x][current.y] = id;
        size[id-2]++; //size[id++]; ???
        for(int i = 0; i < 4; i++) {
            Point t = (Point) { current.x + dirX[i], current.y + dirY[i] };
            if(safe(t.x, t.y) && data[t.x][t.y] == 1) {
                q.push(t);
                data[t.x][t.y] = id;
            }
        }
    }
}

void solve() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(data[i][j] == 1) {
                asdf(i, j, count++);
            }
        }
    }
}

bool compare(int a, int b) {
    return a > b;
}

void output() {
    std::sort(size, size+count-2, compare);

    printf("%d\n", count-2);
    for(int i = 0; i < count-2; i++) {
        printf("%d\n", size[i]);
    }

    /* 디버그 구간
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    */
}

int main() {
    input();
    solve();
    output();
}

/*
7
0 1 1 0 1 0 0
0 1 1 0 1 0 1
1 1 1 0 1 0 1
0 0 0 0 1 1 1
0 1 0 0 0 0 0
0 1 1 1 1 1 0
0 1 1 1 0 0 0

output: 24
*/
