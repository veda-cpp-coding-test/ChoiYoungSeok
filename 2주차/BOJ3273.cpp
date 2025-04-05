#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, X;
vector<int> A;

bool compare(int a, int b) {
	return a < b;
}

/*
void print() {
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << ' ';
	}
	cout << endl;
}
*/

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		A.push_back(temp);
	}
	cin >> X;

	sort(A.begin(), A.end(), compare);

	while (1) {
		if (A.back() >= X) {
			A.pop_back();
		}
		else break;
	}

	int result = 0;
	for (int i = 0; i < A.size(); i++) {
		int need = X - A[i];
		while (1) {
			if (A.back() == A[i]) break;
			if (A.back() >= need) {
				if (A.back() == need)
					result++;
				A.pop_back();
			}
			else break;
		}
	}

	cout << result;

	return 0;
}