#include <iostream>
#include <string>
#include <deque>

using namespace std;

int N;
deque<int> deq;
int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;

	int result = 0;
	for (int i = 0; i < N; i++) {
		deq.clear();
		
		string str;
		cin >> str;

		for (auto c : str) {
			if (deq.empty() || deq.back() != c) {
				deq.push_back(c);
			}
			else {
				deq.pop_back();
			}
		}

		if (deq.empty())
			result++;
	}

	cout << result;

	return 0;
}