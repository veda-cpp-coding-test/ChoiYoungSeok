#include <iostream>
#include <stack>

using namespace std;

int K;
stack<int> stck;

int main() {

	cin >> K;
	for (int i = 0; i < K; i++) {
		int temp;
		cin >> temp;

		if (temp == 0) {
			stck.pop();
		}
		else{
			stck.push(temp);
		}
	}

	int result = 0;
	while (!stck.empty()) {
		result += stck.top();
		stck.pop();
	}

	cout << result;

	return 0;
}