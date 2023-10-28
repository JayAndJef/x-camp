#include <iostream>
#include <queue>
#include <map>

using namespace std;

int dx[4] = {1, -1, -1, 1};
int dy[4] = {0, 0, -1, 1};

int arr[500][500] = {0};
int visited[500][500] = {0};

int main() {
    queue<pair<int, int>> q;

    int n, sx, sy;
    cin >> n >> sx >> sy;

    q.push(pair<int, int>(sx, sy));

    int visits = 0;

    for (int i = 0; i < n; i++) {
        //cout << "next line!" << endl;
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    if (arr[sx][sy] == 0) {
        visited[sx][sy] = 1;
        ++visits;
    }

    while (!q.empty()) {
        auto pt = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = pt.first + dx[i];
            int ny = pt.second + dy[i];
            pair<int, int> pt2(nx, ny);

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] == 0 && arr[nx][ny] == 0) {
                cout << "can visit " << nx << ", " << ny << endl;
                visited[nx][ny] = 1;
                q.push(pt2);
                ++visits;
            }
        }
    }

    cout << visits;
}