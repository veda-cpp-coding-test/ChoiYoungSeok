#include <iostream>
#include <deque>

using namespace std;

int N;
deque<int> deq;

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = N-1; i > -1; i--)
		deq.push_back(i+1);

	while (!deq.empty()) {
		if (deq.size() == 1) {
			cout << deq.front();
			deq.pop_front();
		}
		else {
			deq.pop_back();
			int card = deq.back();
			deq.pop_back();
			deq.push_front(card);
		}
	}

	return 0;
}