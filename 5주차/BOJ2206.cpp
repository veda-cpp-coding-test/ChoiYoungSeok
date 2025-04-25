#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int N, M;
int map[1000][1000];
int visited[1000][1000][2]; // [y][x][0]: 벽 안 부숨, [y][x][1]: 벽 부숨

const int dy[4] = { 0, 0, 1, -1 };
const int dx[4] = { 1, -1, 0, 0 };

struct State {
    int y, x, broken;
};

int bfs() {
    queue<State> q;
    q.push({ 0, 0, 0 });
    visited[0][0][0] = 1;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        int y = cur.y;
        int x = cur.x;
        int broken = cur.broken;

        if (y == N - 1 && x == M - 1) {
            return visited[y][x][broken];
        }

        for (int dir = 0; dir < 4; ++dir) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;

            // 벽이 아니고, 아직 방문하지 않은 경우
            if (map[ny][nx] == 0 && visited[ny][nx][broken] == 0) {
                visited[ny][nx][broken] = visited[y][x][broken] + 1;
                q.push({ ny, nx, broken });
            }

            // 벽이고, 아직 벽을 부수지 않은 경우
            else if (map[ny][nx] == 1 && broken == 0 && visited[ny][nx][1] == 0) {
                visited[ny][nx][1] = visited[y][x][0] + 1;
                q.push({ ny, nx, 1 });
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < M; ++j) {
            map[i][j] = row[j] - '0';
        }
    }

    cout << bfs() << '\n';
    return 0;
}
