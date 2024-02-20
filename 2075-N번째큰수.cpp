#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	priority_queue<int, vector<int>,greater<int>> pq; // top에 가장 작은 수가 올라와있는 우선순위 큐
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp = 0;
			cin >> temp;

			if (pq.size() < N) // 큐가 덜 찬 경우 
			{
				// 큐에 무조건 삽입
				pq.push(temp);
			}

			else if(pq.size()==N)// 큐가 꽉 차있는 경우
			{
				// top과 temp 비교
				// temp가 top보다 크거나 같으면, top을 pop하고 temp를 pq에 넣기
				if (temp >= pq.top())
				{
					pq.pop();
					pq.push(temp);
				}
				

			}


		}
	}



	cout << pq.top();
	return 0;
}
