#include <iostream>
#include <map>

using namespace std;

map<string, int> v;

int main() {
    int n;
    int count = 0;
    string temp_1, temp_2;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> temp_1;
        cin >> temp_2;

        temp_1 = temp_1.substr(0, 2);

        if (temp_1 == temp_2) {
            continue;
        }

        if (v.count(temp_2 + temp_1) > 0) {
            count += v.at(temp_2 + temp_1);
        }

        if (v.count(temp_1 + temp_2) < 1) {
            v[temp_1 + temp_2] = 1;
        } else {
            v[temp_1 + temp_2] += 1;
        }
    }

    for (const auto& value : v) {
        cout << value.first << " " << value.second << endl;
    }

    cout << count;
}