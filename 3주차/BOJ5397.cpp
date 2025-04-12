#include <iostream>
#include <list>

using namespace std;


int N;
list<string> result;

int main() {

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int cs = 0; cs < N; cs++) {
		list<char> strList;
		list<char>::iterator it = strList.begin();
		
		string str;
		cin >> str;
		
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '<') {
				if (it != strList.begin())
					it--;
			}
			else if (str[i] == '>') {
				if (it != strList.end())
					it++;
			}
			else if (str[i] == '-') {
				if (it != strList.begin())
					it = strList.erase(--it);
			}
			else {
				strList.insert(it, str[i]);
			}
		}

		string out = "";
		for (auto c : strList)
			out += c;

		result.push_back(out);
	}

	for (auto str : result) {
		cout << str << '\n';
	}

	return 0;
}