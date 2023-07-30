#include <iostream>

using namespace std;

void box_perms(int step_num, int built_num) {
  if (step_num == 3) {
    cout << built_num;
    return;
  }

  box_perms(step_num+1, built_num * 10 + 1);
  box_perms(step_num+1, built_num * 10 + 2);
  box_perms(step_num+1, built_num * 10 + 3);
}

void box_perms(int step_num) {
  box_perms(1, 1);
  box_perms(1, 2);
  box_perms(1, 3);
}

