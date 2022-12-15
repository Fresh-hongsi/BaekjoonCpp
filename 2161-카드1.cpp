#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<int>cardset;

	int n = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int temp = 0;
		temp = i;
		cardset.push(temp);


	}
	int counter = 1;

	while (cardset.size() != 1)
	{
		if (counter % 2 == 1)
		{
			int output = cardset.front();
			cout << output << ' ';
			cardset.pop();
			counter++;
		}

		else
		{
			int backer = cardset.front();
			cardset.pop();
			cardset.push(backer);
			counter++;
		}
		
	}

	cout << cardset.front();
	return 0;
}
