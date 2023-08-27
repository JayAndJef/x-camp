#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> v;

void box_perms(int num_iter, int step_num, string built_num) {
  if (step_num == num_iter) {
    //cout << built_num << "\n";
    v.push_back(built_num);
    return;
  }

  for (int i = 1; i <= num_iter; i++) {
    if (!(built_num.find(to_string(i)) != string::npos)) {
      box_perms(num_iter, step_num + 1, built_num + " " + to_string(i));
    }
  }
}

void box_perms(int num_iter, int step_num) {
  for (int i = 1; i <= num_iter; i++) {
    box_perms(num_iter, step_num, to_string(i));
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  box_perms(n, 1);

  cout << v[m-1];
}
