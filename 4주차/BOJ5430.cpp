#include <iostream>
#include <deque>
#include <string>
#include <cstdlib> // for atoi

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string arr_str;
        cin >> arr_str;

        deque<int> deq;
        string num;

        // 배열 문자열 파싱
        for (int j = 1; j < arr_str.size() - 1; j++) {
            if (arr_str[j] == ',') {
                deq.push_back(atoi(num.c_str()));
                num = "";
            }
            else {
                num += arr_str[j];
            }
        }
        if (!num.empty()) {
            deq.push_back(atoi(num.c_str()));
        }

        bool reversed = false;
        bool error = false;

        for (char cmd : p) {
            if (cmd == 'R') {
                reversed = !reversed;
            }
            else if (cmd == 'D') {
                if (deq.empty()) {
                    cout << "error\n";
                    error = true;
                    break;
                }
                else {
                    if (!reversed)
                        deq.pop_front();
                    else
                        deq.pop_back();
                }
            }
        }

        if (!error) {
            cout << '[';
            if (!deq.empty()) {
                if (reversed) {
                    for (auto it = deq.rbegin(); it != deq.rend(); ++it) {
                        if (it != deq.rbegin()) cout << ',';
                        cout << *it;
                    }
                }
                else {
                    for (auto it = deq.begin(); it != deq.end(); ++it) {
                        if (it != deq.begin()) cout << ',';
                        cout << *it;
                    }
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}
