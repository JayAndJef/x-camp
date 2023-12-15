#include <iostream>
#include <queue>
#include <map>

using namespace std;

map<string, int> qvisited;
map<string, int> rqvisited;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    string init_state;
    cin >> init_state;

    queue<string> q;
    queue<string> rq;

    q.push(init_state);
    rq.push("123804765");

    qvisited[init_state] = 1;
    rqvisited["123804765"] = 1;

    while (!q.empty() && !rq.empty()) {
        auto state = q.front();
        q.pop();

        if (rqvisited.count(state) > 0) { // found
            // output current point's distance plus reverse distance
            // exit
        }

        int zero_index = state.find('0');
        int zero_x = (zero_index + 1) / 3;
        int zero_y = zero_index % 3;

        for (int i = 0; i < 4; ++i) {
            string swapped = try_swap(state, zero_x + dx[i], zero_y + dy[i], zero_x, zero_y);
            if ()
        }
    }
}

string try_swap(string state, int x, int y, int startx, int starty) {
    if (x < 0 || y < 0 || x >= 3 || y >= 3) {
        return "";
    }

    int e_real_index = (x * 3) + y;
    int b_real_index = (startx * 3) + y;

    swap(state[b_real_index], state[e_real_index]);
    return state;
}