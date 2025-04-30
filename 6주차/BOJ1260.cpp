#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> graph;
bool visited[100000];

int N, M, V;
int main() {

	cin >> N >> M >> V;
	graph = vector<vector<int>>(N);
	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1 - 1].push_back(v2 - 1);
		graph[v2 - 1].push_back(v1 - 1);
	}
	for (int i = 0; i < N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	stack<int> stck;
	stck.push(V-1);
	while (!stck.empty()) {
		int now = stck.top();
		stck.pop();

		if (!visited[now]) {
			cout << now + 1 << ' ';
			visited[now] = true;

			for (vector<int>::reverse_iterator rit = graph[now].rbegin();
				rit != graph[now].rend(); rit++) {
				if(!visited[*rit])
					stck.push(*rit);
			}
		}
	}
	cout << '\n';

	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}

	queue<int> que;
	que.push(V-1);
	while (!que.empty()) {
		int now = que.front();
		que.pop();

		if (!visited[now]) {
			cout << now + 1 << ' ';
			visited[now] = true;

			for (vector<int>::iterator it = graph[now].begin();
				it != graph[now].end(); it++) {
				if (!visited[*it])
					que.push(*it);
			}
		}
	}
	
	return 0;
}