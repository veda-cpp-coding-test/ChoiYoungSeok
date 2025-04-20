#include <iostream>
#include <deque>
#include <string>

using namespace std;

int N;

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	cin.ignore();

	deque<string> parser;
	deque<int> deq;
	for (int i = 0; i < N; i++) {
		parser.clear();

		string cmd;
		getline(cin, cmd);

		string word = "";
		for (int j = 0; j < cmd.length(); j++) {
			if (cmd[j] == ' ') {
				parser.push_back(word);
				word = "";
			}
			else if (j == cmd.length() - 1) {
				word.push_back(cmd[j]);
				parser.push_back(word);
			}
			else {
				word.push_back(cmd[j]);
			}
		}

		if (parser.size() > 1) {
			if (parser.front() == "push") {
				deq.push_back(stoi(parser.back().c_str()));
			}
		}
		else {
			if (!parser.empty()) {
				if (parser.front() == "pop") {
					if (deq.empty()) {
						cout << -1 << '\n';
					}
					else {
						cout << deq.front() << '\n';
						deq.pop_front();
					}
				}
				else if (parser.front() == "size") {
					cout << deq.size() << '\n';
				}
				else if (parser.front() == "empty") {
					cout << (deq.empty() ? 1 : 0) << '\n';
				}
				else if (parser.front() == "front") {
					if (deq.empty()) {
						cout << -1 << '\n';
					}
					else {
						cout << deq.front() << '\n';
					}
				}
				else if (parser.front() == "back") {
					if (deq.empty()) {
						cout << -1 << '\n';
					}
					else {
						cout << deq.back() << '\n';
					}
				}
			}
		}
	}

	return 0;
}