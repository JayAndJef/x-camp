#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int mounth, mountw, beachh, beachw;
int beachdistance = 1000;
int mountdistance = 1000;
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
         int distance_t) {

  if (out_of_bounds(x, y, lenh, lenw) || arr[x][y] == 0 || visited[x][y]) {
    return;
  }
  if (x == mounth && y == mountw) {
    if (distance_t < mountdistance) {
      mountdistance = distance_t;
    }
  }
  if (x == beachh && y == beachw) {
    if (distance_t < beachdistance) {
      beachdistance = distance_t;
    }
  }

  //cout << "dfs on " << x << " " << y << endl;

  visited[x][y] = 1;
  dfs(arr, x + 1, y, lenh, lenw, distance_t+1);
  dfs(arr, x - 1, y, lenh, lenw, distance_t+1);
  dfs(arr, x, y + 1, lenh, lenw, distance_t+1);
  dfs(arr, x, y - 1, lenh, lenw, distance_t + 1);
  visited[x][y] = 0;
}

int main() {
  int n, starth, startw;
  char buf;
  cin >> n;

  vector<vector<int> > arr(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    //cout << "next line!" << endl;
    for (int j = 0; j < n; j++) {
      cin >> buf;
      //cout << "got char " << buf << endl;
      switch (buf) {
      case 'X':
        arr[i][j] = 0;
        //cout << "array at " << i << ", " << j << "is 1" << endl;
        break;
      case '.':
        arr[i][j] = 1;
        // cout << "array at " << i << ", " << j << "is B" << endl;
        break;
      case 'M':
        arr[i][j] = 1;
        mounth = i;
        mountw = j;
        break;
      case 'B':
        arr[i][j] = 1;
        beachh = i;
        beachw = j;
        break;
      case '@':
        arr[i][j] = 1;
        starth = i;
        startw = j;
        break;
      default:
        continue;
      }
    }
  }
  cout << mounth << mountw << beachh << beachw << endl;
  outputarr(arr);

  dfs(arr, starth, startw, n, n, 0);

  if (mountdistance < beachdistance) {
    cout << "Mountains " << mountdistance;
  } else if (beachdistance < mountdistance) {
    cout << "Beach " << beachdistance;
  } else if (beachdistance == mountdistance) {
    cout << "Either " << beachdistance;
  }
}