#include <iostream>
#include <queue>

using namespace std;

int N, K; 
int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	queue<int> people;
	for (int i = 1; i <= N; i++) {
		people.push(i);
	}
	
	cout << '<';
	
	while (!people.empty()) {
		for (int i = 0; i < K - 1; i++) {
			int man = people.front();
			people.pop();
			people.push(man);
		}

		if (people.size() > 1) {
			cout << people.front() << ", ";
		}
		else {
			cout << people.front() << ">";
		}

		people.pop();
	}

	return 0;
}