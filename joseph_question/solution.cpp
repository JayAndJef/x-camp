#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    queue<int> people;

    for (int i = 1; i <= n; ++i) {
        people.push(i);
    }

    cout << people.size() << endl;

    int count = 0;
    int temp_person;

    while (people.size() != 0) {
        ++count;
        if (count == m) {
            if (people.size() == 1)
                cout << people.front() << endl;
            else 
                cout << people.front() << " ";
            people.pop();
            count = 0;
        }
        else
        {
            temp_person = people.front();
            people.pop();
            people.push(temp_person);
        }
    }
}