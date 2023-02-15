#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 3000

//1 :현재 화면에 있는 이모티콘을 모두 클립보드에 넣는 연산
//2 :현재 클립보드에 있는 모든 이모티콘을 화면에 붙여넣는 연산
//3 :화면에 있는 이모티콘 한 개를 삭제하는 연산



int S = 0; //화면에 표현하고싶은 이모티콘 개수
bool visited[MAX][MAX] = { false, }; //방문표시 배열 -> 행: 현재 화면에 표시된 이모티콘 수 / 열: 현재 클립보드에 있는 이모티콘 수
int result = 0; //S개의 이모티콘을 만들기 위한 시간의 최소값에 대한 결과 담을 변수

void bfs()
{
	visited[1][0] = true;
	queue < pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(1, 0), 0));


	while (!q.empty())
	{
		int displayedImo = q.front().first.first; //현재 화면에 표현된 이모티콘 수
		int currentClip = q.front().first.second; //현재 클립보드에 저장되어있는 이모티콘 수
		int time = q.front().second; //현재까지 걸린 초
		q.pop();

		if (S == displayedImo)
		{
			result= time;
			break;
		}

		if (displayedImo > 0 && displayedImo < MAX)
		{
			//1번 연산하기
			if (visited[displayedImo][displayedImo] == false)
			{
				visited[displayedImo][displayedImo] = true;
				q.push(make_pair(make_pair(displayedImo, displayedImo), time + 1));
			}

			//3번 연산하기
			if (visited[displayedImo - 1][currentClip] == false)
			{
				visited[displayedImo - 1][currentClip] = true;
				q.push(make_pair(make_pair(displayedImo - 1, currentClip), time + 1));
			}
		}
		
		if (displayedImo + currentClip < MAX && currentClip>0)
		{
			//2번 연산하기
			if (visited[displayedImo + currentClip][currentClip] == false)
			{
				visited[displayedImo + currentClip][currentClip] = true;
				q.push(make_pair(make_pair(displayedImo + currentClip, currentClip), time + 1));
			}
		}
		

		

	}

}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> S;

	bfs();
	cout << result;

}
