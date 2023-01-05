#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int start = 0;
int goal = 0;


bool visited[100001]; //방문 표시할 좌표

void bfs(int s)
{
	queue<pair<int, int>> q; //first: 다음에 방문할 좌표 second: 현재 깊이
	q.push(make_pair(s,0));

	while (!q.empty())
	{
		int cur = q.front().first;
		int depth = q.front().second;
		q.pop();
		

		if (cur == goal) //도착지까지 찾은 경우
		{
			visited[cur] = true; //방문표시
			cout << depth;
			break;
		}

		else //도착지까지 찾은게 아니면 다음 방문할 곳을 큐에 넣어줌
		{
			if (cur - 1 >= 0 && cur - 1 < 100001) //인덱스 범위 안에서 동작하게 처리
			{
				if (!visited[cur - 1])
				{
					visited[cur - 1] = true; //방문표시
					q.push(make_pair(cur - 1, depth + 1)); //뎁스 한칸 늘려 방문된 곳 큐에 넣음
				}
			}
			
			if (cur + 1 >= 0 && cur + 1 < 100001) //인덱스 범위 안에서 동작하게 처리
			{
				if (!visited[cur + 1])
				{
					visited[cur + 1] = true; //방문표시
					q.push(make_pair(cur + 1, depth + 1)); //뎁스 한칸 늘려 방문된 곳 큐에 넣음
				}
			}
			
			if (cur * 2 >= 0 && cur * 2 < 100001) //인덱스 범위 안에서 동작하게 처리
			{
				if (!visited[2 * cur])
				{
					visited[cur*2] = true; //방문표시
					q.push(make_pair(cur *2, depth + 1));
				}
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

	visited[start] = true; //첫번째 시작 점 방문표시
	bfs(start);

	return 0;


}
