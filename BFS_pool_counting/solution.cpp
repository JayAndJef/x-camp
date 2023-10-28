#include <iostream>
#include <queue>
#include <map>

using namespace std;

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int arr[500][500] = {0};
int visited[500][500] = {0};

int main()
{
    queue<pair<int, int>> q;
    int m, n;
    cin >> n >> m;

    char temp;
    for (int i = 0; i < n; i++)
    {
        // cout << "next line!" << endl;
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            switch (temp)
            {
            case '1':
                arr[i][j] = 1;
                break;

            case '0':
                arr[i][j] = 0;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        //cout << "next line!" << endl;
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1 && visited[i][j] == 0)
            {
                q.push(pair<int, int>(i, j));
                ++count;
                while (!q.empty())
                {
                    auto pt = q.front();
                    q.pop();

                    for (int i = 0; i < 8; ++i)
                    {
                        int nx = pt.first + dx[i];
                        int ny = pt.second + dy[i];
                        pair<int, int> pt2(nx, ny);

                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == 0 && arr[nx][ny] == 1)
                        {
                            // cout << "can visit " << nx << ", " << ny << endl;
                            visited[nx][ny] = 1;
                            q.push(pt2);
                        }
                    }
                }
            }
        }
    }

    cout << count;
}