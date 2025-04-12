#include <iostream>
#include <string>
#include <queue>
#include <stack>

int main()
{
	std::string str;
	std::cin >> str;
	std::cin.ignore();

	std::string out;

	std::stack<char> st_str;
	std::stack<char> st_cursor;

	for (int i = 0; i < str.size(); i++) st_str.push(str[i]);

	int N;
	std::cin >> N;
	std::cin.ignore();

	std::queue<char> queue;  //L : L, D : D, B : B, P $ : $

	for (int i = 0; i < N; i++)
	{
		char input;
		std::cin >> input;
		std::cin.ignore();

		if (input == 'P')
		{
			char data;
			std::cin >> data;
			std::cin.ignore();

			queue.push(data);
		}
		else
		{
			queue.push(input);
		}
	}

	while (!queue.empty())
	{
		char msg = queue.front();

		if (msg == 'L')
		{
			if (!st_str.empty())
			{
				char data = st_str.top();
				st_str.pop();
				st_cursor.push(data);
			}
		}
		else if (msg == 'D')
		{
			if (!st_cursor.empty())
			{
				char data = st_cursor.top();
				st_cursor.pop();
				st_str.push(data);
			}
		}
		else if (msg == 'B')
		{
			if (!st_str.empty()) st_str.pop();
		}
		else
		{
			st_str.push(msg);
		}

		queue.pop();
	}

	while (!st_str.empty())
	{
		char data = st_str.top();
		st_cursor.push(data);
		st_str.pop();
	}

	while (!st_cursor.empty())
	{
		char data = st_cursor.top();
		out += data;
		st_cursor.pop();
	}

	std::cout << out;

	return 0;
}