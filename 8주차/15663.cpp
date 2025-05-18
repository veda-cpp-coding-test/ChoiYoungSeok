#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> sequence;
vector<bool> visited;

void backtrack(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; ++i)
            cout << sequence[i] << ' ';
        cout << '\n';
        return;
    }

    int prev = -1;  // 중복된 숫자 방지용
    for (int i = 0; i < N; ++i) {
        if (!visited[i] && numbers[i] != prev) {
            visited[i] = true;
            sequence.push_back(numbers[i]);
            prev = numbers[i];

            backtrack(depth + 1);

            visited[i] = false;
            sequence.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    numbers.resize(N);
    visited.resize(N, false);

    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());  // 사전 순 출력을 위한 정렬

    backtrack(0);

    return 0;
}
