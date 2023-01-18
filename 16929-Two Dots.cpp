#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int N = 0; //게임판의 행 크기
int M = 0; //게임판의 열 크기
char map[51][51]; //게임판 배치상태
int visited[51][51]; //게임판 점들 방문상태
bool flag = false; //싸이클 찾았으면 true표시할 flag

int di[4] = { -1,0,1,0 }; //상우하좌 행 변위
int dj[4] = { 0,1,0,-1 }; //상우하좌 열 변위
int starti = 0; //main문의 반복문 돌면서 cycle을 찾기 위한 시작점의 행인덱스를 새로 초기화할 것
int startj = 0; //main문의 반복문 돌면서 cycle을 찾기 위한 시작점의 열인덱스를 새로 초기화할 것
int counter = 0; //싸이클의 요건 중 dot의 개수가 4 이상이어야 한다는 조건을 만족하는지 확인하기 위한 변수


void dfs(pair<int, int> cur, char color)
{
	visited[cur.first][cur.second] = true; //해당 점 방문표시
	counter++; //방문되었으므로 counter개수 증가

	if (counter >= 4 && cur.first == starti && cur.second == startj) //시작점과 같고, 점의 개수가 4이상이라면 -> cycle을 찾음!
	{
		flag = true; //flag를 true표시
		return;
	}

	for (int i = 0; i < 4; i++) //싸이클을 찾은 상태가 아니라면 상후하좌 변위 조절해가며 다음 좌표를 계산 후 범위 안에 있고, 조건에 만족하면 dfs시도
	{
		int nexti = cur.first + di[i]; //cycle을 형성할 수 있는 다음 후보의 행 인덱스 계산
		int nextj = cur.second + dj[i]; //cycle을 형성할 수 있는 다음 후보의 열 인덱스 계산

		if (nexti == starti && nextj == startj && counter>=3) //만약 cycle을 형성할 수 있는 바로 전 요건(시작점과 같은 next좌표 && counter의 개수가 3개 이상인 경우)을 달성했으면 dfs호출하여 flag가 true가 될 수 있도록 함
		{
			visited[nexti][nextj] = true;
			dfs(make_pair(nexti, nextj), map[nexti][nextj]);
			return; //싸이클을 찾은 후 flag가 true인 상태에서 함수 반환받은 상태라면 -> 계속 재귀를 탈출
		}

		//바로 다음에 찾아들어갈 next점이 cycle이 끝나는 지점이 아닌 경우이고,
		//next점이 범위 안에 있으면서, 방문아직 안됐고, 색깔이 현재 cur점과 같은 상태라면 -> dfs시도
		else if (visited[nexti][nextj] == false && map[nexti][nextj] == color && nexti >= 0 && nexti < N && nextj >= 0 && nextj < M)
		{
			if (flag == false)
			{
				visited[nexti][nextj]=true;
				dfs(make_pair(nexti, nextj), map[nexti][nextj]);
			}

			
			
		}

		
	}
	
	visited[cur.first][cur.second] = false; //위의 반복문을 다 돌았는데 갈 곳이 없다면 -> 현재 cur좌표를 방문 안함표시로 변경, counter개수 1 줄임
	counter--;
}

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char temp;
			cin >> temp;
			map[i][j] = temp;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			memset(visited, false, sizeof(visited)); //매번 반복문 돌며 새로운 cycle 시작점을 세팅할 때마다 memset통해 visited함수 초기화 -> memory.h 헤더파일 필요!!
			starti = i;
			startj = j;
			counter = 0;
			dfs(make_pair(i, j), map[i][j]);

			if (flag == true) //만일 lag가 true라면 싸이클 찾은 것!
			{
				cout << "Yes";
				return 0;
			}

			else
			{
				continue;
			}

		}
	}

	if (flag == false) //반복문 다 돌았는데 cycle이 없다면 no출력
	{
		cout << "No";
		return 0;
	}
}
