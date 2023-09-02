#include <iostream>
#include <vector>

using namespace std;

int endh, endw;
int min_turns = 1000;
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

void dfs(vector<vector<int> > arr, int x, int y, int lenh, int lenw,
         int turns, int current_dir) {

  if (out_of_bounds(x, y, lenh, lenw) || arr[x][y] == 0 || visited[x][y]) {
    return;
  }
  if (turns > min_turns) {
    return;
  }
  if ((x == endh - 1) && (y == endw - 1)) {
    if (turns < min_turns) {
      min_turns = turns;
    }
  }

  // cout << "dfs on " << x << " " << y << endl;

  visited[x][y] = 1;
  switch (current_dir) {
  case 1:
    dfs(arr, x + 1, y, lenh, lenw, turns, current_dir);
    dfs(arr, x - 1, y, lenh, lenw, turns + 1, 3);
    dfs(arr, x, y + 1, lenh, lenw, turns + 1, 4);
    dfs(arr, x, y - 1, lenh, lenw, turns + 1, 2);
    break;
  case 2:
    dfs(arr, x + 1, y, lenh, lenw, turns + 1, 1);
    dfs(arr, x - 1, y, lenh, lenw, turns + 1, 3);
    dfs(arr, x, y + 1, lenh, lenw, turns + 1, 4);
    dfs(arr, x, y - 1, lenh, lenw, turns, current_dir);
    break;
  case 3:
    dfs(arr, x + 1, y, lenh, lenw, turns + 1, 1);
    dfs(arr, x - 1, y, lenh, lenw, turns, current_dir);
    dfs(arr, x, y + 1, lenh, lenw, turns + 1, 4);
    dfs(arr, x, y - 1, lenh, lenw, turns + 1, 2);
    break;
  case 4:
    dfs(arr, x + 1, y, lenh, lenw, turns + 1, 1);
    dfs(arr, x - 1, y, lenh, lenw, turns + 1, 3);
    dfs(arr, x, y + 1, lenh, lenw, turns, current_dir);
    dfs(arr, x, y - 1, lenh, lenw, turns + 1, 2);
    break;
  }
  visited[x][y] = 0;
}

int main() {
  int lenh, lenw, starth, startw;
  char buf;
  cin >> lenh >> lenw;

  vector<vector<int> > arr(lenh, vector<int>(lenw));

  for (int i = 0; i < lenh; i++) {
    // cout << "next line!" << endl;
    for (int j = 0; j < lenw; j++) {
      cin >> buf;
      // cout << "got char " << buf << endl;
      switch (buf) {
      case '1':
        arr[i][j] = 0;
        // cout << "array at " << i << ", " << j << "is 1" << endl;
        break;
      case '0':
        arr[i][j] = 1;
        // cout << "array at " << i << ", " << j << "is B" << endl;
        break;
      default:
        continue;
      }
    }
  }
  cin >> starth >> startw;
  starth = starth - 1;
  startw = startw - 1;
  cin >> endh >> endw;
  outputarr(arr);

  dfs(arr, starth, startw, lenh, lenw, 0, 1);
  dfs(arr, starth, startw, lenh, lenw, 0, 2);
  dfs(arr, starth, startw, lenh, lenw, 0, 3);
  dfs(arr, starth, startw, lenh, lenw, 0, 4);

  cout << min_turns;
}
