#include <iostream>
#include <map>

using namespace std;
char arr[1000][1000] = {};
map<char, bool> visited = {
    {'A', false},
    {'B', false},
    {'C', false},
    {'D', false},
    {'E', false},
    {'F', false},
    {'G', false},
    {'H', false},
    {'I', false},
    {'J', false},
    {'K', false},
    {'L', false},
    {'M', false},
    {'N', false},
    {'O', false},
    {'P', false},
    {'Q', false},
    {'R', false},
    {'S', false},
    {'T', false},
    {'U', false},
    {'V', false},
    {'W', false},
    {'X', false},
    {'Y', false},
    {'Z', false},
};
int max_visit = 0;

bool out_of_bounds(int x, int y, int lenh, int lenw) {
    return x < 0 || y < 0 || x > lenh - 1 || y > lenw - 1;
}

void floodfill(int x, int y, int lenh, int lenw, int visits) {
    if (out_of_bounds(x, y, lenh, lenw) || visited[arr[x][y]]) {
        if (visits > max_visit) {
            max_visit = visits;
        }
        return;
    }

    cout << "found new letter " << arr[x][y] << "\n";
    visited[arr[x][y]] = true;
    floodfill(x + 1, y, lenh, lenw, visits + 1);
    floodfill(x, y + 1, lenh, lenw, visits + 1);
    floodfill(x - 1, y, lenh, lenw, visits + 1);
    floodfill(x, y - 1, lenh, lenw, visits + 1);
    visited[arr[x][y]] = false;
}

int main() {
    int lenh, lenw;
    cin >> lenh >> lenw;

    for (int i = 0; i < lenh; i++) {
        //cout << "next line!" << endl;
        for (int j = 0; j < lenw; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < lenh; i++) {
        for (int j = 0; j < lenw; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    floodfill(0, 0, lenh, lenw, 0);

    cout << max_visit;
}