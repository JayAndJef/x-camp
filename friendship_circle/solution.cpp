#include <iostream>

using namespace std;

int arr[201][201] = {0};
int vcount;

bool out_of_bounds(int x, int y, int n) {
    return x < 0 || y < 0 || x > n - 1 || y > n - 1;
}

void dfs(int x, int y, int n) {
    if (out_of_bounds(x, y, n) || !arr[x][y]) {
        return;
    }

    arr[x][y] = 0;
    for (int i = 0; i < n; i++) {
        dfs(x, i, n);
        dfs(i, y, n);
    }
}

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        //cout << "next line!" << endl;
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    //for (int i = 0; i < n; i++) {
        //for (int j = 0; j < n; j++) {
            //cout << arr[i][j] << " ";
        //}
        //cout << endl;
    //}

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) {
                //cout << "dfsing on " << i << " " << j << endl;
                vcount++;
                dfs(i, j, n);
            }
        }
    }

    cout << vcount;
}