#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    set<string> values;
    int n;
    char temp;
    string colors = "";

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        colors += temp;
    }

    int old_len;

    for (int slice_len = 1; slice_len <= 100; ++slice_len) {
        cout << "here\n";
        for (int acc = 0; acc < (n - slice_len+1); ++acc) {
            values.insert(colors.substr(acc, slice_len));
        }
        if (values.size() != n - slice_len + 1) {
            cout << "duplicates! expected " << n - slice_len + 1 << " values but got " << values.size() << endl;
        } else {
            cout << slice_len;
            exit(0);
        }
        values.clear();
    }
}