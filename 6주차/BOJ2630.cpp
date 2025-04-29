#include <iostream>

using namespace std;

int N;
int map[128][128];

void debug(int y, int x, int div) {
	for (int i = y; i < y + div; i++) {
		for (int j = x; j < x + div; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}

	cout << endl;
}

void chop(int y, int x, int div, int& w, int& b) {
	if (div <= 1) {
		if (map[y][x] == 0) {
			w++;
		}
		else{
			b++;
		}
	}
	else {
		bool changed = false;
		for (int i = y; i < y + div; i++) {
			for (int j = x; j < x + div; j++) {

				if (map[i][j] != map[y][x]) {
					changed = true;
					break;
				}
			}
		}

		if (changed) {
			chop(y, x, div / 2, w, b);
			chop(y + div/2, x, div / 2, w, b);
			chop(y, x + div / 2, div / 2, w, b);
			chop(y + div / 2, x + div / 2, div / 2, w, b);
		}
		else {
			if (map[y][x] > 0)
				b++;
			else
				w++;
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp;
			cin >> temp;
			map[i][j] = temp - '0';
		}
	}

	int w = 0;
	int b = 0;

	chop(0, 0, N, w, b);

	cout << w << '\n';
	cout << b << '\n';

	return 0;
}