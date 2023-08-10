#include <iostream>
#include <string>

using namespace std;

void box_perms(int num_iter, int step_num, string built_num) {
  if (step_num == num_iter) {
    cout << built_num << "\n";
    return;
  }

  for (int i = 1; i <= num_iter; i++) {
    box_perms(num_iter, step_num+1, built_num + " " + to_string(i));
  }
}

void box_perms(int num_iter, int step_num) {
  for (int i = 1; i <= num_iter; i++) {
    box_perms(num_iter, step_num, to_string(i));
  }
}

int main() {
  int n;
  cin >> n;
  box_perms(n, 1);
}

