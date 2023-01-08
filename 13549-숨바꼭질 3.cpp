#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_NODE 100001
int start = 0;
int goal = 0;
bool visited[MAX_NODE] = { false, };


void bfs(int s)
{
	queue<pair<int, int>> q;
	visited[s] = true; //방문표시
	q.push(make_pair(start, 0));
	

	while (!q.empty())		
	{

		int cur = q.front().first;
		int depth = q.front().second;
		visited[cur] = true; 
		q.pop();

		if (cur == goal)
		{
			cout << depth;
			break;
		}

		else
		{
			if (cur * 2 >= 0 && cur * 2 < MAX_NODE && visited[cur * 2] == false) //현재위치*2로 순간이동하는 경우는 depth가 늘어나지 않으므로 if문 중 가장 앞에 배치하여 큐에 먼저 들어가 방문표시될 수 있게 함-> 그러면 먼저 visited되어 뒤에 -1,+1 하는 경우 이미 방문표시되어있기 떄문에 큐에 들어가지 않음
			{
				q.push(make_pair(cur * 2, depth));
			}

			if (cur - 1 >= 0 && cur - 1 < MAX_NODE && visited[cur-1]==false)
			{
				q.push(make_pair(cur - 1, depth + 1));
			}

			if (cur + 1 >= 0 && cur + 1 < MAX_NODE && visited[cur+1] == false)
			{
				q.push(make_pair(cur + 1, depth + 1));
			}

			
		}
	}


}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> start >> goal;

	bfs(start);

	return 0;


}
