//Data structure
//Simulation
//Implementation
//Deque


#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	deque<int> dq;

	int n = 0;
	int k = 0;
	int m = 0;
	cin >> n >> k >> m;

	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}

	bool direction = true; //true이면 시계방향, false이면 시계반대방향
	
	
	int count = 0;


	while (!dq.empty())
	{
		if (count != 0 && count % m == 0) //m개 제거될 때마다 방향 바꾸기
		{
			direction = !direction;
		}

		if (direction == true) //시계방향일 경우 -> k-1번 앞에서 pop해서 뒤로 push 후 가장 앞에 있는 요소가 pop할 대상임
		{
			for (int i = 0; i < k-1; i++) 
			{
				int temp = dq.front();
				dq.push_back(temp);
				dq.pop_front();
			}
			cout << dq.front()<<'\n';
			dq.pop_front();
			count++;
			
		}

		if (direction == false) //반시계방향일 경우 -> k-1번 뒤에서 pop해서 앞으로 push 후 가장 뒤에 있는 요소가 pop할 대상임
		{
			for (int i = 0; i < k-1; i++)
			{
				int temp = dq.back();
				dq.push_front(temp);
				dq.pop_back();
			}
			cout << dq.back() << '\n';
			dq.pop_back();
			count++;
		}
	}
	return 0;
}
