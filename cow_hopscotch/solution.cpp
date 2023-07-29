#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int visits = 0;

//void outputarr(vector<vector<int> > arr) {
  //for (vector<int> i : arr) {
    //for (int j : i) {
      //cout << j << " ";
    //}
    //cout << "\n";
  //}
//}

bool out_of_bounds(int x, int y, int lenh, int lenw) {
  return x < 0 || y < 0 || x > lenh - 1 || y > lenw - 1;
}

void dfs(vector<vector<int> > arr, int x, int y, int lenh, int lenw, int state) {
  if (x == y && x == lenh-1) {
    //cout << "reached end" << endl;
    visits++;
    return;
  }
  
  for (int i = x+1; i < lenh; i++) {
    for (int j = y + 1; j < lenw; j++) {
      //cout << "dfs on " << i << " " << j << endl;
      if (arr[i][j] != state) {
        if (state == 1){
          dfs(arr, i, j, lenh, lenw, 0);
        } else {
          dfs(arr, i, j, lenh, lenw, 1);
        }
      }
    }
  }
}

int main() {
  int lenw, lenh;
  char buf;
  cin >> lenw >> lenh;

  vector<vector<int> > arr(lenw, vector<int>(lenh));

  buf = getchar();

  for (int i = 0; i < lenh; i++) {
    // cout << "next line!" << endl;
    for (int j = 0; j < lenw + 1; j++) {
      buf = getchar();
      //cout << "got char " << buf << endl;
      switch (buf) {
      case 'R':
        arr[i][j] = 0;
        //cout << "array at " << i << ", " << j << "is R" << endl;
        break;
      case 'B':
        arr[i][j] = 1;
        //cout << "array at " << i << ", " << j << "is B" << endl;
        break;
      default:
        continue;
      }
    }
  }
  //outputarr(arr);

  dfs(arr, 0, 0, lenh, lenw, arr[0][0]);
  cout << visits;
}