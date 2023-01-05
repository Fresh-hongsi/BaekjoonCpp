#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int start = 0;
int goal = 0;


bool visited[100001]; //방문 표시할 좌표
int path[100001]; //바로 전 어디를 방문했는지 저장할 배열
void bfs(int s)
{
	queue<pair<int, int>> q; //first: 다음에 방문할 좌표 second: 현재 깊이
	q.push(make_pair(s,0));
	path[s] = -1; //시작점 바로 전엔 방문한 곳이 없으므로 -1처리

	while (!q.empty())
	{
		int cur = q.front().first;
		int depth = q.front().second;
		q.pop();
		

		if (cur == goal) //도착지까지 찾은 경우
		{
			visited[cur] = true; //방문표시
			cout << depth<<'\n';
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
					path[cur - 1] = cur; //바로 전 방문한 곳을 저장
				}
			}
			
			if (cur + 1 >= 0 && cur + 1 < 100001) //인덱스 범위 안에서 동작하게 처리
			{
				if (!visited[cur + 1])
				{
					visited[cur + 1] = true; //방문표시
					q.push(make_pair(cur + 1, depth + 1)); //뎁스 한칸 늘려 방문된 곳 큐에 넣음
					path[cur + 1] = cur; //바로 전 방문한 곳을 저장
				}
			}
			
			if (cur * 2 >= 0 && cur * 2 < 100001) //인덱스 범위 안에서 동작하게 처리
			{
				if (!visited[2 * cur])
				{
					visited[cur*2] = true; //방문표시
					q.push(make_pair(cur *2, depth + 1));
					path[cur *2] = cur; //바로 전 방문한 곳을 저장
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

	vector<int>reversedPath; //path배열을 역참조해서 path를 기록할 배열

	int cnt = goal; //꺼꾸로 역참조하기 위해 목적지부터 찾아들어감
	reversedPath.push_back(cnt);

	while (cnt != -1) //끝까지 찾으면 반복문 탈출
	{
		int temp = path[cnt];
		if (temp != -1)
		{
			reversedPath.push_back(temp);
		}
		
		cnt = temp;
	}

	reverse(reversedPath.begin(), reversedPath.end()); //역순이므로 다시 거꾸로 돌려줘야 path완성

	for (int i = 0; i < reversedPath.size(); i++)
	{
		cout << reversedPath[i] << ' ';
	}
	
	return 0;


}
