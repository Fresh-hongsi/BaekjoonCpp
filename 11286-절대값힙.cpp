//Data Structure
//Priority Queue
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

//우선순위 큐는 비교함수가 일반 정렬함수랑 반대이다. 
//가령 i<j 이면 오름차순 정렬인데, 힙 기준으로는 루트 노드가 가장 큰 값이 오게 된다
//i>j로 놓으면 원래는 내림차순 정렬인데, 힙 기준으로는 투트 노드에 가장 작은 값이 오게 된다.
//또한 priority_queue의 비교함수를 직접 정의하려면, 구조체 안에 operator()함수를 직접 정의해줘야한다.
struct cmp { 

	bool operator()(int i, int j)
	{
		if (abs(i) == abs(j))
		{
			return i > j; //절대값이 같다면 루트노드에 더 작은 값이 오게
		}

		else
		{
			return abs(i) > abs(j); //절대값이 다르다면 루트노드에 절대값이 더 작은 값이 오게
		}


	}
	
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;
	priority_queue<int, vector<int>, cmp> pq;

	while (N--)
	{
		int command = 0;
		cin >> command;

		if (command != 0)
		{
			pq.push(command);
		}

		else
		{
			if (pq.empty())
			{
				cout << 0 << '\n';
				continue;
			}
			int output = pq.top();
			pq.pop();
			cout << output << '\n';
		}
	}

	return 0;
}
