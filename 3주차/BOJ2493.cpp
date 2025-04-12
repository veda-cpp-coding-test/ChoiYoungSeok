#include <iostream>
#include <stack>

using namespace std;

int N;
stack<pair<int, int>> stck;

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int height;
		cin >> height;

		while (!stck.empty()) {
			if (stck.top().second > height) {
				cout << stck.top().first << ' ';
				break;
			}
			stck.pop();
		}

		if (stck.empty()) cout << "0 ";

		stck.push({ i , height });
	}

	return 0;
}