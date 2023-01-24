#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int n = 0; //전체 영역의 행,열 길이
int height=0; 
int map[100][100]; //전체 영역의 높이 정보를 저장할 배열
bool visited[100][100] = { false, }; //전체 영역에서 높이 h로 물에 잠겼을 때, 잠긴 부분은 true처리, 안잠겨있는 곳은 false처리 -> 추후에 bfs하는 과정에서 false처리되어 있는 곳을 true처리해나갈 것(의미적으로는 맞지 않지만, 어차피 안정영역의 개수만 구하면 되므로 안전영역임을 확인한 곳은 true처리할 것)
int curAreaNum; //현재 높이 h에서의 안전영역 개수
int di[4] = {-1,0,1,0}; //안전영역 찾을 때 행에 대한 상 우 하 좌 변위
int dj[4] = {0,1,0,-1}; //안전영역 찾을 때 열에 대한 상 우 하 좌 변위


void bfs(pair<int,int>s) 
{
	 
	visited[s.first][s.second] = true; //visited가 false여서 들어온 지점(안전영역이 될 수 있는 시작 행,열 좌표)를 true표시해줌
	queue<pair<int, int>> q;

	q.push(make_pair(s.first, s.second));

	while (!q.empty()) //연결된 안전영역을 bfs로 모두 구해서 true표시해주는 과정
	{
		int curi = q.front().first;
		int curj = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) //상우하좌 변위 순회하며
		{
			int nexti = curi + di[i];
			int nextj = curj + dj[i];

			if (nexti >= 0 && nexti <= n - 1 && nextj >= 0 && nextj <= n - 1 && visited[nexti][nextj] == false) //범위 안에 있는 인덱스이고, 아직 안전영역의 가능성이 있는 지점이라면
			{
				visited[nexti][nextj] = true; //방문 표시
				q.push(make_pair(nexti, nextj));  //다음 안전영역을 구하기 위해 현재 지역 위치를 큐에 넣어줌
			}
		}
	}

	curAreaNum++; //한 안전영역을 구했으면 curAreaNum개수 1 증가시킴

	


	
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	cin >> n; //전체 영역의 행/열 길이 입력받음

	//전체 영역의 높이 정보 입력받아 map배열에 저장
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			int temp = 0;
			cin >> temp;

			if (temp > height) //초기에 height는 0으로 설정되어있는데, 모든 지역들에 대해 입력받은 높이 중 가장 큰 높이를 알아내기 위한 과정(1부터 가장 높은 높이(height)까지 반복하며 가장 많은 안전영역 개수를 알아낼 것) 
			{
				height = temp;
			}

			map[i][j] = temp; //해당 지역의 높이 정보를 map배열에 저장

		}
	}

	int areaNum = 1; //어떠한 곳도 잠기지 않은 경우에는 안전영역 개수는 1개이므로 1개보다 많은 안전영역 개수 있으면 areaNum을 갱신해 나갈 것

	for (int h = 1; h <= height; h++) //높이 1에서부터 height(입력받은 높이 중 가장 높은 값)까지 계속 h값을 변경해나가면서 최대 안전영역 개수를 구할 것
	{
		curAreaNum = 0; //아직 구하기 전의 안전영역 개수는 0

		//모든 지역에 대해 현재 잠긴 곳이라면 true처리해줌
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] <= h)
				{
					visited[i][j] = true;
				}
			}
		}

		//모든 지역에 대해 안잠긴 지역이 있다면, 그 지역으로부터 bfs해봄. 하나의 bfs함수 호출이 끝날때마다 현재 높이 h에서의 안전영역 개수 curAreaNum은 1 증가될 것
		for (int i = 0; i < n; i++)
		{
			
			for (int j=0;j<n;j++)
			{
				if (visited[i][j] == false)
				{
					bfs(make_pair(i, j));
				}
				
				
				
			}
		}

		//만약 현재 높이 h에서 구한 안전영역 개수가 기존의 areaNum보다 크다면, areaNum을 갱신해줌. areaNum은 가장 큰 안전영역 개수 값을 가지게 될 것
		if (curAreaNum > areaNum)
		{
			areaNum = curAreaNum;
		}

		//현재 높이 h에서의 안전영역 개수를 구했다면, 다시 초기 상태로 돌아가기 위해 visited배열을 초기화해줌
		memset(visited, false, sizeof(visited));
	}

	cout << areaNum;
	return 0;


}
