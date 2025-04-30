#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N;
vector<vector<int>> graph;
vector<int> estimated;
vector<int> result;

bool visited[100001];
void dfs(int x, vector<int>& picked)
{
	if (visited[x]) return;

	picked.push_back(x);
	visited[x] = true;

	for (int y : graph[x]) {
		if (visited[y] == false)
			dfs(y, picked);
	}
}
bool compare(int a, int b)
{
	return result[a] < result[b];
}
int main()
{
	cin >> N;
	graph = vector<vector<int>>(N, vector<int>());
	estimated = vector<int>(N);
	result = vector<int>(N);

	for (int i = 0; i < N - 1; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1 - 1].push_back(v2 - 1);
		graph[v2 - 1].push_back(v1 - 1);
	}

	for (int i = 0; i < N; ++i) {
		cin >> estimated[i];
		estimated[i] -= 1;
		result[estimated[i]] = i;
	}

	for (int i = 0; i < N; ++i) {
		sort(graph[i].begin(), graph[i].end(), compare);
	}

	vector<int> picked;
	dfs(0, picked);

	for (int i = 0; i < picked.size(); ++i)
	{
		if (picked[i] != estimated[i]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;

}