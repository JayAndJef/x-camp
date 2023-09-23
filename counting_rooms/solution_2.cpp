// MUCH faster solution

#include <iostream>
#include <vector>

using namespace std;

int visits = 0;
int visited[1001][1001] = {0};

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

void dfs(int x, int y, int lenh, int lenw) {
  
  if (out_of_bounds(x, y, lenh, lenw) || visited[x][y] == 1) {
    return;
  }

  visited[x][y] = 1;
  dfs(x + 1, y, lenh, lenw);
  dfs(x - 1, y, lenh, lenw);
  dfs(x, y + 1, lenh, lenw);
  dfs(x, y - 1, lenh, lenw);
}

int main() {
  int lenw, lenh;
  char buf;
  cin >> lenh >> lenw;

  for (int i = 0; i < lenh; i++) {
    //cout << "next line!" << endl;
    for (int j = 0; j < lenw; j++) {
      cin >> buf;
      //cout << "got char " << buf << endl;
      switch (buf) {
      case '#':
        visited[i][j] = 1;
        //cout << "array at " << i << ", " << j << "is 1" << endl;
        break;
      case '.':
        visited[i][j] = 0;
        // cout << "array at " << i << ", " << j << "is B" << endl;
        break;
      default:
        continue;
      }
    }
  }
  //outputarr(arr);

  for (int i = 0; i < lenh; i++) {
    for (int j = 0; j < lenw; j++) {
        if (visited[i][j] == 0) {
            cout << "empty at " << i << " " << j << "\n";
            dfs(i, j, lenh, lenw);
            visits++;
        }
    }
  }

  cout << visits;
}