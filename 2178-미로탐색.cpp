//Graph
//BFS

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

int row = 0;
int col = 0;
vector<vector<int>> maze(100, vector<int>(100, 0));
vector<vector<bool>> visited(100, vector<bool>(100, false));
int dx[4] = { 0,-1,0,1}; //좌,상,우,하에서의 행 위치
int dy[4] = { -1,0,1,0}; //좌,상,우,하에서의 열 위치


void BFS(pair<int, int> c) //bfs는 최단 거리 계산에 용이
{
	queue<pair<int, int>> q;
	q.push(c);
	int idx = 1;

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		if (maze[cur.first][cur.second] == idx) //만약 pop한 인덱스 좌표의 값이 idx값과 같은 경우는 idx값 1 증가시킨 후, 방문할 수 있는 곳에 idx값 저장. pop한 인덱스 좌표의 값이 idx와 다른 경우는 방문할 수 있는 곳에 전의 idx값을 저장시켜야함
		{
			idx += 1;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= row || ny < 0 || ny >= col)
			{
				continue;
			}

			if (maze[nx][ny] == 1 && visited[nx][ny] == false)
			{
				q.push(pair<int, int>(nx, ny));
				visited[nx][ny] = true;
				maze[nx][ny] = idx;

			}
		}
		

	}
}


int main(void)
{
	cin >> row >> col;


	//미로 입력
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%1d", &maze[i][j]);
			
		}
	}

	pair<int, int> cur(0, 0);

	BFS(cur);

	cout << maze[row - 1][col - 1];
	return 0;
}
