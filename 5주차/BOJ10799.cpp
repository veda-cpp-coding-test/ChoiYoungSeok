#include <iostream>
#include <string>
#include <deque>

using namespace std;

string input;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> input;


	int result = 0;
	deque<int> stickCut;
	for (const char c : input) {
		if (c == '(') {
			stickCut.push_back(0);
		}
		else {
			if (!stickCut.empty()) {
				if (stickCut.back() > 0) {
					//���밡 ���� ���
					result += stickCut.back() + 1;
					stickCut.pop_back();
				}
				else {
					//������ Ŀ��
					stickCut.pop_back();
					if (!stickCut.empty()) {
						for (int i = 0; i < stickCut.size(); i++)
							stickCut[i]++;
					}
				}
			}
		}
	}

	cout << result;

	return 0;
}