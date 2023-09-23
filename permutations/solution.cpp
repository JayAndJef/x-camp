#include <iostream>
#include <string>
#include <vector>

using namespace std;

int step = 1;
int need;

void box_perms(long long int num_iter, long long int step_num, string built_num) {
  if (step_num == num_iter) {
    //cout << built_num << "\n";
    if (step == need) {
      cout << built_num;
      exit(0);
    } else {
      step++;
    }
    return;
  }

  string string_i;
  for (int i = 1; i <= num_iter; i++) {
    string_i = to_string(i);
    if (built_num.find(" " + string_i) == string::npos) {
      box_perms(num_iter, step_num + 1, built_num + " " + string_i);
    }
  }
}

void box_perms(int num_iter, int step_num) {
  for (int i = 1; i <= num_iter; i++) {
    box_perms(num_iter, step_num, " " + to_string(i));
    cout << "here" << "\n";
  }
}

int main() {
  int n;
  cin >> n >> need;
  box_perms(n, 1);
  cout << "this shouldnt print";
}