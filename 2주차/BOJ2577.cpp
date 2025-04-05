#include <iostream>

using namespace std;


int main() {

	int A, B, C;
	cin >> A >> B >> C;

	int ABC = A * B * C;

	int cnt[10] = {0, };
	while (ABC > 0) {
		cnt[ABC % 10]++;
		ABC /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << cnt[i] << '\n';
	}

	return 0;
}