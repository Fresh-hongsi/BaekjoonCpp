#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int start = 0;
int goal = 0;


bool visited[100001]; //방문 표시할 좌표
int path[100001]; //바로 전 어디를 방문했는지 저장할 배열
bool flag = false;
int counter = 0;
int curDepth = 0;
void bfs(int s)
{
	queue<pair<int, int>> q; //first: 다음에 방문할 좌표 second: 현재 깊이
	q.push(make_pair(s, 0));
	
	

	while (!q.empty())
	{
		
		int cur = q.front().first;
		int depth = q.front().second;
		visited[cur] = true; //방문표시!!!!!!!!!!!!!!!!!!중요

		q.pop();

		if (cur == goal && flag == true && curDepth == depth) //목적지에 도착할 수 있는 다른 케이스 발견(depth==curDepth여야하고 flag==true여야함)한 경우
			//바로 아래 if문과 순서가 반드시 이렇게 정렬되어있어야 제대로 동작함 -> curDepth 초기화 시기로 인하여 !
		{

			counter++;

		}
		
	
		if (cur == goal && flag==false) //처음으로 목적지에 도착한 경우 //바로 위 if문 아래에 반드시 있어야함
		{
			
			counter++;
			cout << depth << '\n';
			curDepth = depth;
			flag = true;
			
		}

		



		else //도착지까지 찾은게 아니면 다음 방문할 곳을 큐에 넣어줌
		{
			if (cur - 1 >= 0 && cur - 1 < 100001) //인덱스 범위 안에서 동작하게 처리
			{
				if (!visited[cur - 1])
				{
					
					q.push(make_pair(cur - 1, depth + 1)); //뎁스 한칸 늘려 방문된 곳 큐에 넣음
					
				}
			}

			if (cur + 1 >= 0 && cur + 1 < 100001) //인덱스 범위 안에서 동작하게 처리
			{
				if (!visited[cur + 1] )
				{
					
					q.push(make_pair(cur + 1, depth + 1)); //뎁스 한칸 늘려 방문된 곳 큐에 넣음
					
				}
			}

			if (cur * 2 >= 0 && cur * 2 < 100001) //인덱스 범위 안에서 동작하게 처리
			{
				if (!visited[2 * cur])
				{
					
					q.push(make_pair(cur * 2, depth + 1));  //뎁스 한칸 늘려 방문된 곳 큐에 넣음
					
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

	if (start == goal) //시작점과 목적지가 같으면 방법은 무조건 한가지
	{
		counter = 1;
	}
	cout << counter;
	

	return 0;


}
