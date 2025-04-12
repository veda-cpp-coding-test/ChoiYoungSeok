#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
vector<int> seq;
stack<int> stck;

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;
		seq.push_back(data);
	}

	int cnt = 0;
	string result = "";
	for (int i = 1; i <= N; i++) {
		stck.push(i);
		result += "+\n";

		while (!stck.empty() && stck.top() == seq[cnt]) {
			stck.pop();
			result += "-\n";
			cnt++;
		}
	}

	if (!stck.empty()) result = "NO";

	cout << result;

	return 0;
}