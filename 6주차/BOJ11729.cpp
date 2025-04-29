#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int cnt;
vector<pair<int, int>> mv;

void move(int N, int from, int buf, int to) {
	if (N <= 1) {
		mv.push_back({from, to});
		cnt++;
		return;
	}
	else {
		move(N-1, from, to, buf);
		move(1, from, buf, to);
		move(N-1, buf, from, to);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	move(N, 1, 2, 3);

	cout << cnt << '\n';
	for (auto p : mv) {
		cout << p.first << ' ' << p.second << '\n';
	}

	return 0;
}