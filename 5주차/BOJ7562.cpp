#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
const int dy[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };
int map[300][300];

int main() {
	int cases;
	cin >> cases;

	for (int t = 0; t < cases; t++) {
		int l, fromX, fromY, toX, toY;
		cin >> l >> fromX >> fromY >> toX >> toY;

		// 거리 배열 초기화: -1은 방문 안 한 상태를 의미
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				map[i][j] = -1;
			}
		}

		queue<pair<int, int>> que;
		que.push({ fromY, fromX });
		map[fromY][fromX] = 0;

		while (!que.empty()) {
			pair<int, int> now = que.front();
			que.pop();

			for (int d = 0; d < 8; d++) {
				int ny = now.first + dy[d];
				int nx = now.second + dx[d];

				if (ny >= 0 && ny < l && nx >= 0 && nx < l) {
					if (map[ny][nx] == -1) {
						map[ny][nx] = map[now.first][now.second] + 1;
						que.push({ ny, nx });
					}
				}
			}
		}

		cout << map[toY][toX] << '\n';
	}

	return 0;
}