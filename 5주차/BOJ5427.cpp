#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int cases;

int fire[1000][1000];
int sanggeun[1000][1000];

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

typedef struct {
	pair<int, int> pos;
	int value;
}nowPos_t;

void debug(int height, int width) {
	
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if(sanggeun[i][j] >= 0 && sanggeun[i][j]/10 == 0)
				cout << '0' << sanggeun[i][j] << ' ';
			else
				cout << sanggeun[i][j] << ' ';
		}
		cout << endl;
	}

	cout << endl;
}

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> cases;
	for (int cs = 0; cs < cases; cs++) {
		int width, height;
		cin >> width >> height;

		vector<pair<int,int>> to;
		queue<pair<int, int>> qFire;
		queue<pair<int, int>> qSanggeun;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				char temp;
				cin >> temp;

				if (temp == '#') {
					fire[i][j] = -1;
					sanggeun[i][j] = -1;
				}
				else if (temp == '*') {
					fire[i][j] = 1;
					qFire.push({i, j});
				}
				else if (temp == '@') {
					sanggeun[i][j] = 1;
					qSanggeun.push({i, j});

					if (i == 0 || i == height - 1
						|| j == 0 || j == width - 1) {
						to.push_back({ i, j }); //사용자가 이미 나가기 바로 전인 경우
					}
				}
				else {
					// .
					fire[i][j] = width * height + 1;
					sanggeun[i][j] = width * height + 1;
					if (i == 0 || i == height-1
						|| j == 0 || j == width-1) {
						to.push_back({i, j});
					}
				}
			}
		}

		while (!qFire.empty()) {
			pair<int, int> now = qFire.front();
			qFire.pop();

			for (int i = 0; i < 4; i++) {
				pair<int, int> next = {now.first + dy[i], now.second + dx[i]};
				if (next.first > -1 && next.first < height
					&& next.second > -1 && next.second < width) {
					if (fire[next.first][next.second] > 0
						&& fire[next.first][next.second] > fire[now.first][now.second] + 1) {
						fire[next.first][next.second] = fire[now.first][now.second] + 1;
						qFire.push(next);
					}
				}
			}
		}

		while (!qSanggeun.empty()) {
			pair<int, int> now = qSanggeun.front();
			qSanggeun.pop();

			for (int i = 0; i < 4; i++) {
				pair<int, int> next = { now.first + dy[i], now.second + dx[i] };
				if (next.first > -1 && next.first < height
					&& next.second > -1 && next.second < width) {
					if (sanggeun[next.first][next.second] > 0
						&& sanggeun[next.first][next.second] > sanggeun[now.first][now.second] + 1) {
						int temp = sanggeun[now.first][now.second] + 1;
						if (temp < fire[next.first][next.second]) {
							sanggeun[next.first][next.second] = temp;
							qSanggeun.push(next);
						}
					}
				}
			}
		}

		int min = width*height+1;
		for (auto pos : to) {
			if (sanggeun[pos.first][pos.second] < min) {
				min = sanggeun[pos.first][pos.second];
			}
		}

		if (min < width * height + 1) {
			cout << min << '\n';
		}
		else {
			cout << "IMPOSSIBLE\n";
		}
	}

	return 0;
}