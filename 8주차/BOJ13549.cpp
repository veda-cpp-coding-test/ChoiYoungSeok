#include <iostream>
#include <deque>
#include <vector>
#include <limits.h>

using namespace std;

const int MAX = 100001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> dist(MAX, INT_MAX);
    deque<int> dq;

    dist[N] = 0;
    dq.push_back(N);

    while (!dq.empty()) {
        int current = dq.front();
        dq.pop_front();

        // 순간이동: 비용 0
        if (current * 2 < MAX && dist[current * 2] > dist[current]) {
            dist[current * 2] = dist[current];
            dq.push_front(current * 2);  // 0초이므로 앞에 추가
        }

        // 걷기: 비용 1
        if (current - 1 >= 0 && dist[current - 1] > dist[current] + 1) {
            dist[current - 1] = dist[current] + 1;
            dq.push_back(current - 1);  // 1초이므로 뒤에 추가
        }
        if (current + 1 < MAX && dist[current + 1] > dist[current] + 1) {
            dist[current + 1] = dist[current] + 1;
            dq.push_back(current + 1);
        }
    }

    cout << dist[K] << '\n';

    return 0;
}
