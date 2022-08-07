//Data Structure
//Priority queue

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

priority_queue<int, vector<int>> pq; //우선순위 큐의 디폴트 값은 내림차순 -> 최대힙임

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	cin >> n;

	while (n--)
	{
		int temp = 0;
		cin >> temp;

		if (temp == 0)
		{
			if (!pq.empty())
			{
				cout << pq.top()<<'\n';
				pq.pop();
			}

			else
			{
				cout << 0 << '\n';
			}


		}

		else
		{
			pq.push(temp);
		}
	}

	return 0;


}
