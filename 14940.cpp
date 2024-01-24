#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// 너비우선 탐색은 큐 이동

int N = 0;
int M = 0;
int num[1001][1001] = { 0, };
int visited[1001][1001] = { 0, };
int targetX;
int targetY;

int dx[4] = { -1,0,1,0 }; //상우하좌 행 변위
int dy[4] = { 0,1,0,-1 }; //상우하좌 열 변위

void bfs(int startX, int startY)
{
	queue<pair<int, int>> q;
	q.push(make_pair(startX, startY));
	visited[startX][startY] = 1;

	while (!q.empty())
	{
		int frontX = q.front().first;
		int frontY = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = frontX + dx[i];
			int nextY = frontY + dy[i];

			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
			{
				if (visited[nextX][nextY] == 0 && num[nextX][nextY] != 0) // 아직 방문한적 없고, 그곳이 길이라면, 큐에 추가
				{
					visited[nextX][nextY] = visited[frontX][frontY] + 1;
					q.push(make_pair(nextX, nextY));
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

	cin >> N >> M;

	// 입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp = 0;
			cin >> temp;
			if (temp == 2)
			{
				targetX = i;
				targetY = j;
			}

			num[i][j] = temp;
		}
	}

	// 너비우선탐색 시작
	bfs(targetX, targetY);

	// 출력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (num[i][j] == 0)
			{
				cout << '0' << ' ';
			}
			else
			{
				cout << visited[i][j] - 1 << ' ';
			}
		}

		cout << '\n';
	}


}
