//Data structure
//Priority queue

#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int tc = 0;
	cin >> tc;

	priority_queue<int,vector<int>,greater<int>> pq; //최소힙 우선순위 큐 선언

	while (tc--)
	{
		int n = 0;
		cin >> n;

		if (n == 0) //0이 입력된 경우 가장 상위 부모 노드 출력 후 삭제, 우선순위 큐가 비어있으면 0출력
		{
			if (pq.empty())
			{
				cout << 0 << '\n';
			}

			else
			{
				cout << pq.top()<<'\n';
				pq.pop();
			}
		}

		else //0이 아닌 다른 숫자 들어오면 우선순위 큐에 데이터 삽입
		{
			pq.push(n);
		}
	}

	return 0;
}
