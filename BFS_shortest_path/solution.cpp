#include <iostream>
#include <queue>
#include <map>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int arr[500][500] = {0};
int visited[500][500] = {0};
int dist[500][500] = {1};

int main()
{
    queue<pair<int, int>> q;

    int n;
    cin >> n;

    q.push(pair<int, int>(0, 0));

    for (int i = 0; i < n; i++)
    {
        // cout << "next line!" << endl;
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    while (!q.empty())
    {
        auto pt = q.front();
        q.pop();

        cout << "popped " << pt.first << ", " << pt.second << endl;

        if ((pt.first == n - 1) && (pt.second == n - 1)) {
            cout << dist[pt.first][pt.second];
            exit(0);
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = pt.first + dx[i];
            int ny = pt.second + dy[i];
            pair<int, int> pt2(nx, ny);

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && visited[nx][ny] == 0 && arr[nx][ny] == 0)
            {
                cout << "can visit " << nx << ", " << ny << endl;
                visited[nx][ny] = 1;
                dist[nx][ny] = dist[pt.first][pt.second] + 1;
                q.push(pt2);
            }
        }
    }

    cout << -1;
}