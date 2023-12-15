#include <vector>
#include <fstream>
#include <map>
//#include "../cpp-dump/dump.hpp"

using namespace std;

int in_vec(vector<char> &vec, char val) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == val) {
            return i + 1;
        }
    }
    return 0;
}

int main() {
    vector<char> expected;
    char buf;
    int count = 0;

    ifstream read("circlecross.in");

    for (int i = 0; i < 52; i++) {
        read >> buf;
        if (!in_vec(expected, buf)) {
            expected.push_back(buf);
        } else { // it's in the stack!
            if (expected.back() == buf) {
                expected.pop_back();
            } else {
                int index = in_vec(expected, buf);
                count += expected.size() - index;
                expected.erase(expected.begin() + index-1);
            }
        }
    }

    ofstream written("circlecross.out");
    written << count;
}
