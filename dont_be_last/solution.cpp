#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

map<string, int> cows = {
    {"Bessie", 0},
    {"Maggie", 0},
    {"Elsie", 0},
    {"Henrietta", 0},
    {"Gertie", 0},
    {"Daisy", 0},
    {"Annabelle", 0},
};

map<int, int> value_map;
set<int> values;

int main() {
    int n, temp_num;
    string temp_name;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> temp_name;
        cin >> temp_num;
        cows[temp_name] += temp_num;
    }

    for(auto cow : cows) {
        cout << cow.first << " " << cow.second << endl;
        value_map[cow.second] += 1;

        values.insert(cow.second);
    }

    for (auto value : values) {
        cout << value << "\n";
    }

    for (auto value : value_map) {
        cout << value.first << " " << value.second << endl;
    }

    int iteration = 1;
    for (auto value : values) {
        cout << iteration << endl;
        if ((value_map[value] == 1) && (iteration > 1)) {
            cout << "here1\n";
            for (auto cow : cows) {
                if (cow.second == value) {
                    cout << cow.first << endl;
                    exit(0);
                }
            }
        }
        iteration++;
    }
    cout << "Tie\n";
}