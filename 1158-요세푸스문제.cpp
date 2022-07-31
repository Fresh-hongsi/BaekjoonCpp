#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int N;
	int K;

	cin >> N >> K;

	queue<int> q;

	for (int i = 1; i <= N; i++) //큐에 사람 넣기
	{
		q.push(i);
	}

	cout << "<";

	while (!q.empty())
	{
		for (int i = 0; i < K - 1; i++)
		{
			int x = q.front();
			q.pop();
			q.push(x);
		}
		if (q.size() > 1)

		{
			int output = q.front();
			cout << output << ", ";
			q.pop();
		}
		else if (q.size() <= 1)
		{
			int output = q.front();
			cout << output;
			q.pop();
		}

		

	}

	cout << ">" << endl;
	return 0;

}
