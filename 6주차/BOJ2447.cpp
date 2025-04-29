#include <iostream>

using namespace std;

char map[2187][2187];

void punch(int y, int x, int n) {
	if (n <= 3) {
		map[y + 1][x + 1] = ' ';
	}
	else {
		for (int i = y + n/3; i < y + 2*n/3; i++) {
			for (int j = x + n/3; j < x + 2 * n/3; j++) {
				map[i][j] = ' ';
			}
		}

		punch(y, x, n/3);
		punch(y, x + n/3, n / 3);
		punch(y, x + 2*n/3, n / 3);

		punch(y+n/3, x, n / 3);
		punch(y + n / 3, x + 2 * n / 3, n / 3);
		
		punch(y+2*n/3, x, n / 3);
		punch(y + 2 * n / 3, x + n / 3, n / 3);
		punch(y + 2 * n / 3, x + 2 * n / 3, n / 3);
	}
}

int N;
int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = '*';
		}
	}

	punch(0, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}

	return 0;
}