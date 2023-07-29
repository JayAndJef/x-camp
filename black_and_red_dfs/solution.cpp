#include <iostream>
#include <vector>

using namespace std;

int visited[100][100];
int num_visits = 0;

void emptyarray() {
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      visited[i][j] = 0;
    }
  }
}

bool out_of_bounds(int x, int y, int lenh, int lenw) {
  return x < 0 || y < 0 || x > lenh - 1 || y > lenw - 1;
}

void floodfill(vector< vector<int> > arr, int x, int y, int lenh, int lenw, int step_count) {
  if (out_of_bounds(x, y, lenh, lenw) || visited[x][y] || arr[x][y]) {
    // cout << "can't go to " << x << ", " << y << "\n";
    return;
  } else if (step_count < 3) {
    floodfill(arr, x - 1, y, lenh, lenw, step_count + 1);
    floodfill(arr, x + 1, y, lenh, lenw, step_count + 1);
    floodfill(arr, x, y + 1, lenh, lenw, step_count + 1);
    floodfill(arr, x, y - 1, lenh, lenw, step_count + 1);
    visited[x][y] = 1;
    num_visits++;
    // cout << "can go to " << x << ", " << y << "visits: " << num_visits <<
    // "\n";
  } else {
    floodfill(arr, x - 2, y - 1, lenh, lenw, 0);
    floodfill(arr, x + 2, y + 1, lenh, lenw, 0);
    floodfill(arr, x - 2, y + 1, lenh, lenw, 0);
    floodfill(arr, x + 2, y - 1, lenh, lenw, 0);
    floodfill(arr, x - 1, y + 2, lenh, lenw, 0);
    floodfill(arr, x + 1, y - 2, lenh, lenw, 0);
    floodfill(arr, x + 1, y + 2, lenh, lenw, 0);
    floodfill(arr, x - 1, y - 2, lenh, lenw, 0);
    visited[x][y] = 1;
    num_visits++;
  }

}

int main() {
  int lenw, lenh, x, y;
  lenw = 1;
  char buf;
  cin >> lenw >> lenh;

  while (lenw != 0) {
    vector<vector<int> > arr(lenh, vector<int>(lenw));
    emptyarray();

    getchar();
    for (int i = 0; i < lenh; i++) {
      // cout << "next line!" << endl;
      for (int j = 0; j < lenw + 1; j++) {
        buf = getchar();
        // cout << "got char " << buf << endl;
        switch (buf) {
        case '.':
          arr[i][j] = 0;
          // cout << "array at " << i << ", " << j << "is ." << endl;
          break;
        case '#':
          arr[i][j] = 1;
          // cout << "array at " << i << ", " << j << "is #" << endl;
          break;
        case '@':
          x = i;
          y = j;
          arr[i][j] = 0;
          // cout << "array at " << i << ", " << j << "is @" << endl;
          break;
        default:
          continue;
        }
      }
    }
    floodfill(arr, x, y, lenh, lenw, 1);
    cout << num_visits << "\n";
    num_visits = 0;
    cin >> lenw >> lenh;
    // outputarr(arr);
  }
}