#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k, temp;
    cin >> n >> k;

    queue<pair<int, int>> people;

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        people.push(pair<int, int>(i, temp));
    }

    int counter = 0;

    while (true) {
        ++counter;
        pair<int, int> front = people.front();
        if (front.first == k && front.second == 1) {
            cout << "reached front\n";
            cout << counter;
            exit(0);
        } else if (people.front().second == 1) {
            cout << "person got their tickeyt!\n";
            people.pop();
        }
        else
        {
            cout << "person got a ticker and moved to back!\n";
            pair<int, int> front = pair<int, int>(people.front().first, people.front().second - 1);
            people.pop();
            people.push(front);
        }
    }
}
