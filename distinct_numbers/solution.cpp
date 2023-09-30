#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> numbers;
    int n, temp;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        numbers.insert(temp);
    }

    cout << numbers.size();
}