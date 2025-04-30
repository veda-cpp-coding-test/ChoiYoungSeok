#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> graph;
bool visited[100000];
int order[100000];

int N, M, R;
int main() {

	cin >> N >> M >> R;
	graph = vector<vector<int>>(N);
	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1 - 1].push_back(v2-1);
		graph[v2 - 1].push_back(v1-1);
	}
	for (int i = 0; i < N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}


	stack<int> stck;
	stck.push(R - 1); // 0-indexed
	int visitCount = 1;

	while (!stck.empty()) {
		int now = stck.top();
		stck.pop();

		if (!visited[now]) {
			visited[now] = true;
			order[now] = visitCount++;

			// 인접 노드를 역순으로 push하여 오름차순으로 방문되도록 함
			for (int i = graph[now].size() - 1; i >= 0; i--) {
				int next = graph[now][i];
				if (!visited[next]) {
					stck.push(next);
				}
			}
		}
	}

	// 정점별 방문 순서 출력
	for (int i = 0; i < N; i++) {
		cout << order[i] << '\n';
	}

	return 0;
}