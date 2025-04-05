#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main() {

	cin >> N;

	int cnt[10] = { 0, };
	while (N > 0) {
		cnt[N % 10]++;
		N /= 10;
	}
	
	cnt[6] = (cnt[6] + cnt[9]) % 2 == 0 ? (cnt[6] + cnt[9]) / 2 : (cnt[6] + cnt[9]) / 2 + 1;
	cnt[9] = 0;

	sort(cnt, cnt+10); //기본 오름차순

	cout << cnt[9];

	return 0;
}