#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N = 0;
//R: 1
//G: 2
//B: 3

int map1[101][101]={0,}; //적록색약 없는 사람의 map
int map2[101][101] = { 0, }; //적록색약 있는 사람의 map
bool visited1[101][101] = { false, }; //적록색약 없는 사람의 방문표시 배열
bool visited2[101][101] = { false, }; //적록색약 있는 사람의 방문표시 배열
int di[4] = {-1,0,1,0}; //상우하좌 움직일 때 행의 변위
int dj[4] = {0,1,0,-1}; //상우하좌 움직일 때 열의 변위
int areaNum1 = 0; //적록색약 없는 사람일 때의 영역 개수
int areaNum2 = 0; //적록색약 있는 사람일 때의 영역 개수

void bfs1(pair<int, int> start) //적록색약 없는 사람을 위한 bfs
{
	queue<pair<int, int>> q;

	if (visited1[start.first][start.second] == true) //main함수의 반복문을 돌면서 다시 함수가 실행될 때, 이미 방문된 배열이면 굳이 여기서 다시 bfs할 필요 x
	{
		return;
	}

	visited1[start.first][start.second] = true; //해당 지점 방문표시
	int cntColor = map1[start.first][start.second]; //start지점의 color확인
	q.push(make_pair(start.first, start.second)); //큐에 삽입

	while (!q.empty()) 
	{
		int curi = q.front().first;
		int curj = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nexti = curi + di[i];
			int nextj = curj + dj[i];

			if (nexti >= 0 && nexti <= N && nextj >= 0 && nextj <= N && visited1[nexti][nextj] == false && map1[nexti][nextj] == cntColor)
			{
				visited1[nexti][nextj] = true;
				q.push(make_pair(nexti, nextj));
			}
		}
	}

	areaNum1++; //해당 bfs가 성공적으로 동작했으면 연결되어있는 영역 하나를 찾은 것임 따라서 영역 개수 1증가
	
}

void bfs2(pair<int, int> start) //적록색약 있는 사람을 위한 bfs
{
	queue<pair<int, int>> q;

	if (visited2[start.first][start.second] == true) //main함수의 반복문을 돌면서 다시 함수가 실행될 때, 이미 방문된 배열이면 굳이 여기서 다시 bfs할 필요 x
	{
		return;
	}
	 
	visited2[start.first][start.second] = true; //해당 지점 방문표시
	int cntColor = map2[start.first][start.second]; //start지점의 color확인
	q.push(make_pair(start.first, start.second)); //큐에 삽입

	while (!q.empty())
	{
		int curi = q.front().first;
		int curj = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nexti = curi + di[i];
			int nextj = curj + dj[i];

			if (nexti >= 0 && nexti <= N && nextj >= 0 && nextj <= N && visited2[nexti][nextj] == false && map2[nexti][nextj] == cntColor)
			{
				visited2[nexti][nextj] = true;
				q.push(make_pair(nexti, nextj));
			}
		}
	}

	areaNum2++; //해당 bfs가 성공적으로 동작했으면 연결되어있는 영역 하나를 찾은 것임 따라서 영역 개수 1증가
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	//적록색약 있는 사람과 없는 사람의 경우를 따로 구분해서 map배열에 저장
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char temp = 0;
			cin >> temp;
			if (temp == 'R')
			{
				map1[i][j] = 1;
				map2[i][j] = 1;
			}

			else if (temp == 'G')
			{
				map1[i][j] = 2;
				map2[i][j] = 1;
			}

			else if (temp == 'B')
			{
				map1[i][j] = 3;
				map2[i][j] = 3;
			}
			
		}
	}

	
	//case에따라 bfs계속 시도
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bfs1(make_pair(i, j));
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bfs2(make_pair(i, j));
		}
	}

	cout << areaNum1 << '\n';
	cout << areaNum2;
	return 0;
	


}
