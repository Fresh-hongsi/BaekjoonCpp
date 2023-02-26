#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;

#define MAX 99999999
int M = 0; //지도 행 길이
int N = 0; //지도 열 길이
int di[4] = { -1,0,1,0 }; //행 변위
int dj[4] = { 0,1,0,-1 }; //열 변위
int map[101][101]= {0,}; //0인지 1인지 저장하는 배열
int dist[101][101] = { 0, }; //해당 좌표에는 여기까지 몇개의 문을 부쉈는지 저장


void BFS(pair<int, int> p)
{
	int x = p.first;
	int y = p.second;

	dist[x][y] = 0; //시작 위치에서 뚫어야 하는 벽 개수는 0임
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		int curi = q.front().first; //현재 행위치
		int curj = q.front().second; //현재 열위치
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nexti = curi + di[i];
			int nextj = curj + dj[i];

			//범위 밖의 위치라면 continue
			if (nexti < 0 || nexti >= N || nextj < 0 || nextj >= M)
			{
				continue;

			}

			//만약 뚫어봐야하는 곳이라면
			if (map[nexti][nextj] == 1)
			{
				//현재 위치의 dist값이 max라면 하나 뚫어야 하는 벽 개수를 증가시켜보기
				if (dist[nexti][nextj] > dist[curi][curj] + 1)
				{
					dist[nexti][nextj] = dist[curi][curj] + 1;
					q.push(make_pair(nexti, nextj));
				}
			}

			//만약 안뚫어도 되는 곳이라면
			else if (map[nexti][nextj] == 0)
			{
				//만약 해당 위치가 MAX라면 그냥 현재 위치의 벽 개수 넣어두기
				if (dist[nexti][nextj] > dist[curi][curj])
				{
					dist[nexti][nextj] = dist[curi][curj];
					q.push(make_pair(nexti, nextj));
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

	cin >> M >> N;

	//map에 알맞은 값 저장
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < temp.length(); j++)
		{
			int t = temp[j] - '0';
			map[i][j] = t;
		}
	}

	//dist최대값으로 저장
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			dist[i][j] = MAX;
		}
	}


	//뚫어야 하는 벽 개수 구하기
	BFS(make_pair(0, 0));

	//최소 벽 길이 구하기
	cout<< dist[N - 1][M - 1];



}
