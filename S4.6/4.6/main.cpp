#include <iostream>
#include <algorithm>

typedef struct Point {
    int x, y;
};

int main();
Point solve(int arr[][19]);
bool checkWin(int arr[][19], Point origin);
Point dirPos(int dir, Point origin, int i);
bool validatePosition(int x, int y);

int main() {
    int arr[19][19];
    for(int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {
            std::cin >> arr[i][j];
        }
    }

    Point p = solve(arr);
    std::cout << arr[p.x][p.y] << std::endl << p.x << " " << p.y;
}

Point solve(int arr[][19]) {
    for(int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {
            if(arr[i][j] == 0) continue; // Continue the loop if there is no stone

            std::cout << "y : " << i << ", x : " << j << std::endl;

            if(checkWin(arr, (Point) { j, i })) { // Check for winner
                return (Point) { j, i }; // Return win position
            }
        }
    }
}

bool checkWin(int arr[][19], Point origin) {
    int _count;
    for(int i = 0; i < 5; i++) {
        std::cout << i << std::endl;
        _count = 0;
        for(int j = 1; j <= 6; j++) {
            std::cout << "Test " << j << std::endl;
            Point p = dirPos(i, origin, j);
            if(j != 6 && !validatePosition(p.x, p.y)) break;
            if(arr[p.x][p.y] == arr[origin.x][origin.y]) _count++;
        }
        if(_count == 5) return true;
    }

    return false;
}

Point dirPos(int dir, Point origin, int i) {
    Point result = origin;
    switch(dir) {
    case 0:
        result.y -= i;
        return result;
    case 1:
        result.x += i;
        return result;
    case 2:
        result.x -= i;
        return result;
    case 3:
        result.y -= i;
        result.x += i;
        return result;
    case 4:
        result.y -= i;
        result.x -= i;
        return result;
    default:
        return origin;
    }
}

bool validatePosition(int x, int y) {
    return (x < 19 && x >= 0) && (y < 19 && y >= 0);
}

/*

! Directions 0~7
0: Down
1: Right
2: Left
3: DownRight
4: DownLeft

*/
