#include <cstdio>
#include <algorithm>

int main();
void _sort(int arr[], int _size);
void _swap(int arr[], int a, int b);
bool _findc(int arr1[][3], int arr2[3], int arr1_size);
bool isrightshape(int a, int b, int c);

int main()
{
    int n, arr[100][3], arr_size=0;
    scanf("%d", &n);

    for(int i = 1; i <= n-2; i++) {
        for(int j = 1; j <= n-2; j++) {
            if(i + j >= n || !isrightshape(i, j, n-i+j)) continue;
            int t[3];
            t[0] = i;
            t[1] = j;
            t[2] = n - i - j;
            std::sort(t, t+3);
            if(!_findc(arr, t, arr_size)) {
                arr[arr_size][0] = t[0];
                arr[arr_size][1] = t[1];
                arr[arr_size++][2] = t[2];
            }
        }
    }

    printf("%d\n", arr_size);

    return 0;
}

void _sort(int arr[], int _size) {
    for(int i = 0; i < _size; i++) {
        for(int j = i; j < _size; j++) {
            if(i == j) continue;
            if(i < j) _swap(arr, i, j);
        }
    }
}

void _swap(int arr[], int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

bool _findc(int arr1[][3], int arr2[3], int arr1_size) {
    for(int i = 0; i < arr1_size; i++) {
        if(arr1[i][0] == arr2[0] && arr1[i][1] == arr2[1] && arr1[i][2] == arr2[2]) return true;
    }
    return false;
}

bool isrightshape(int a, int b, int c) {
    if(a>c+b || b>a+c || c>a+b) return false;
    return true;
}
