#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

char map[5][5];
int result = 0;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int comb[25];

bool is_connected(vector<int>& selected) {
    bool visited[5][5] = { false };
    queue<pair<int, int>> q;

    int sy = selected[0] / 5;
    int sx = selected[0] % 5;

    q.push({ sy, sx });
    visited[sy][sx] = true;

    int count = 1;

    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;

            int idx = ny * 5 + nx;

            if (!visited[ny][nx] && find(selected.begin(), selected.end(), idx) != selected.end()) {
                visited[ny][nx] = true;
                q.push({ ny, nx });
                count++;
            }
        }
    }

    return count == 7;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 입력
    for (int i = 0; i < 5; i++) {
        string str; cin >> str;
        for (int j = 0; j < 5; j++) {
            map[i][j] = str[j];
        }
    }

    // 7개를 선택하기 위한 초기 comb 설정
    for (int i = 0; i < 25; i++) {
        if (i < 7) comb[i] = 1;
        else comb[i] = 0;
    }

    do {
        vector<int> selected;
        int scnt = 0;

        for (int i = 0; i < 25; i++) {
            if (comb[i]) {
                selected.push_back(i);
                int y = i / 5, x = i % 5;
                if (map[y][x] == 'S') scnt++;
            }
        }

        if (scnt >= 4 && is_connected(selected)) {
            result++;
        }

    } while (prev_permutation(comb, comb + 25));

    cout << result << '\n';
    return 0;
}
