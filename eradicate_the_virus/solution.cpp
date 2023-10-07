#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k, temp;
    cin >> n >> k;

    queue<int> seq;

    int max_len = 0;
    int sum_in_queue = 0;

    while (n--) {
        cin >> temp;
        cout << "got " << temp << endl;
        if (!(sum_in_queue + temp > k))
        {
            cout << "sum is " << sum_in_queue << ", adding " << temp << endl;
            sum_in_queue += temp;
            seq.push(temp);
        }
        else
        {
            cout << "sum is " << sum_in_queue << ", popping and adding " << temp << endl;
            while (sum_in_queue + temp > k) {
                sum_in_queue -= seq.front();
                seq.pop();
            }
            sum_in_queue += temp;
            seq.push(temp);
        }

        if (seq.size() > max_len)
        { // check if we have new high score
            cout << "new high score is " << seq.size() << endl;
            max_len = seq.size();
        }
    }

    cout << max_len << endl;
}