#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    deque<int> deq;

    for (char ch : str) {
        if (ch == '(') {
            deq.push_back(-2); // '('
        }
        else if (ch == '[') {
            deq.push_back(-3); // '['
        }
        else if (ch == ')' || ch == ']') {
            if (deq.empty()) {
                cout << 0;
                return 0;
            }

            int match = (ch == ')') ? -2 : -3;
            int multiplier = (ch == ')') ? 2 : 3;

            if (deq.back() == match) {
                deq.pop_back();
                deq.push_back(multiplier);
            }
            else {
                int sum = 0;
                while (!deq.empty() && deq.back() > 0) {
                    sum += deq.back();
                    deq.pop_back();
                }

                if (deq.empty() || deq.back() != match) {
                    cout << 0;
                    return 0;
                }

                deq.pop_back();
                deq.push_back(sum * multiplier);
            }
        }
        else {
            cout << 0;
            return 0; // 잘못된 문자
        }
    }

    int result = 0;
    for (int val : deq) {
        if (val < 0) {
            cout << 0;
            return 0; // 괄호가 열리고 닫히지 않은 경우
        }
        result += val;
    }

    cout << result;
    return 0;
}
