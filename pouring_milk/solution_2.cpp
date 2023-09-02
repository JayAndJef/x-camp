#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<int> poss_fills;
vector<vector<int> > visit_states;

pair<int, int> pour(int from_full, int to_full, int from, int to) {
  cout << "pouring " << from << " -> " << to << "..." << endl;
  int amount_to_pour = to_full - to;
  if (from < amount_to_pour) {
    to = from + to;
    from = 0;
  } else if (from > amount_to_pour) {
    to = to_full;
    from = from - amount_to_pour;
  } else {
    to = to_full;
    from = 0;
  }

  cout << "pour result " << from << " -> " << to << endl;
  return pair<int, int>(from, to);
}

void find_fill(int fill_list[], int vol_list[], int from, int to) {

  if (vol_list[from - 1] == 0)
    return;

  cout << "find_fill " << from << " -> " << to << endl;
  cout << "values are " << vol_list[0] << " " << vol_list[1] << " "
       << vol_list[2] << endl;

  pair<int, int> new_vals = pour(fill_list[from - 1], fill_list[to - 1],
                                 vol_list[from - 1], vol_list[to - 1]);
  vol_list[from - 1] = new_vals.first;
  vol_list[to - 1] = new_vals.second;

  for (int i = 0; i < visit_states.size(); i++) {
    if (visit_states[i][0] == vol_list[0] &&
        visit_states[i][1] == vol_list[1] &&
        visit_states[i][2] == vol_list[2]) {
      cout << "state already reached";
      return;
    }
  }

  vector<int> state_vect;
  state_vect.push_back(vol_list[0]);
  state_vect.push_back(vol_list[1]);
  state_vect.push_back(vol_list[2]);

  visit_states.push_back(state_vect);

  cout << "values after pour: " << vol_list[0] << " " << vol_list[1] << " "
       << vol_list[2] << endl;

  int third = 6 - (from + to);

  if (vol_list[0] == 0) {
    cout << "A is zero! C is " << vol_list[2] << endl;
    poss_fills.push_back(vol_list[2]);
    // return;
  }

  int temp_dest[3];

  cout << "\nstepping in..." << endl;
  int t1[3] = {fill_list[0], fill_list[1], fill_list[2]};
  int t2[3] = {fill_list[0], fill_list[1], fill_list[2]};
  int t3[3] = {fill_list[0], fill_list[1], fill_list[2]};
  int t4[3] = {fill_list[0], fill_list[1], fill_list[2]};

  int f1[3] = {vol_list[0], vol_list[1], vol_list[2]};
  int f2[3] = {vol_list[0], vol_list[1], vol_list[2]};
  int f3[3] = {vol_list[0], vol_list[1], vol_list[2]};
  int f4[3] = {vol_list[0], vol_list[1], vol_list[2]};
  find_fill(t1, f1, to, third);
  find_fill(t2, f2, from, third);
  find_fill(t3, f3, third, from);
  find_fill(t4, f4, third, to);
  cout << "\nstepping out" << endl;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int fill_list[3] = {a, b, c};
  int vol_list[3] = {0, 0, c};

  cout << "\nfirst call\n" << endl;
  find_fill(fill_list, vol_list, 3, 1);
  cout << "\nsecond call\n" << endl;
  find_fill(fill_list, vol_list, 3, 2);

  sort(poss_fills.begin(), poss_fills.end());

  for (int i = 0; i < poss_fills.size(); i++) {
    if (!(i == poss_fills.size() - 1))
      cout << poss_fills[i] << " ";
    else
      cout << poss_fills[i];
  }
}
