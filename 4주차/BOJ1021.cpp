#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int N, M;

void debug(deque<int>& deq) {
	for (int i = 0; i < deq.size(); i++) {
		cout << deq[i] << ' ';
	}
	cout << endl;
}

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	deque<int > deq(N, M+1); // 값으로 순서가 들어 간다.
	for (int i = 1; i <= M; i++) {
		int temp;
		cin >> temp;
		deq[temp-1] = i;
	}
	
	int count = 0;
	int targetOut = 1;
	while (targetOut <= M) {
		//위치 찾고
		
		//debug(deq);

		deque<int>::iterator it = std::find(deq.begin(), deq.end(), targetOut);

		if (it == deq.begin()) {
			deq.pop_front();
			targetOut++;
		}
		else if ((it - deq.begin()) < (deq.end() - it)) {
			while (deq[0] != targetOut) {
				int front = deq.front();
				deq.pop_front();
				deq.push_back(front);
				count++;
			}

			deq.pop_front();
			targetOut++;
		}
		else {
			while (deq[0] != targetOut) {
				int back = deq.back();
				deq.pop_back();
				deq.push_front(back);
				count++;
			}

			deq.pop_front();
			targetOut++;
		}
	}

	cout << count;

	return 0;
}