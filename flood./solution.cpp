#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int visits = 0;
int visited[100][100] = {0};

void outputarr(vector<vector<int> > arr) {
  for (vector<int> i : arr) {
    for (int j : i) {
      cout << j << " ";
    }
    cout << "\n";
  }
}

bool out_of_bounds(int x, int y, int lenh, int lenw) {
  return x < 0 || y < 0 || x > lenh - 1 || y > lenw - 1;
}

void dfs(vector<vector<int> > arr, int x, int y, int lenh, int lenw) {

  if (out_of_bounds(x, y, lenh, lenw) || arr[x][y] == 0 || visited[x][y]) {
    return;
  }

  visited[x][y] = 1;
  visits++;
  dfs(arr, x + 1, y, lenh, lenw);
  dfs(arr, x - 1, y, lenh, lenw);
  dfs(arr, x, y + 1, lenh, lenw);
  dfs(arr, x, y - 1, lenh, lenw);
}

int main() {
  int n, starth, startw;
  char buf;
  cin >> n;

  vector<vector<int> > arr(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    cout << "next line!" << endl;
    for (int j = 0; j < n; j++) {
      cin >> buf;
      cout << "got char " << buf << endl;
      switch (buf) {
      case '-':
        arr[i][j] = 0;
        cout << "array at " << i << ", " << j << "is 1" << endl;
        break;
      case '_':
        arr[i][j] = 1;
        // cout << "array at " << i << ", " << j << "is B" << endl;
        break;
      case '*':
        arr[i][j] = 1;
        starth = i;
        startw = j;
        break;
      default:
        continue;
      }
    }
  }
  outputarr(arr);

  dfs(arr, starth, startw, n, n);

  cout << visits;
}