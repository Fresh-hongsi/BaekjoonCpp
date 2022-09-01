//Graph
//Brute-Force
//BFS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


vector<vector<int>> map(50, vector<int>(50, 0)); //아파트 지도
vector<vector<bool>>visited(50, vector<bool>(50, false)); //섬 순회 시 방문표시 할 배열
int w = 0;
int h = 0;
int dx[8] = { 0,-1,0,1,-1,-1,1,1 }; //좌,상,우,하,좌상대,우상대, 좌하대, 우하대에서의 행 위치
int dy[8] = { -1,0,1,0,-1,1,-1,1 }; //좌,상,우,하,좌상대,우상대, 좌하대, 우하대에서의 열 위치

void bfs(pair<int, int> s)
{
	queue<pair<int, int>> q;
	q.push(s);
	visited[s.first][s.second] = true;

	while (!q.empty())
	{
		pair<int, int>cur = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w)
			{
				continue;
			}

			if (map[nx][ny] == 1 && visited[nx][ny] == false)
			{
				q.push(pair<int, int>(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	while (1)
	{
		
		int result = 0;
		cin >> w >> h;

		if (w == 0 && h == 0) //만일 너비와 높이가 모두 0인 입력이라면 반복문 종료
		{
			break;
		}

		//지도 값 입력받기
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int temp = 0;
				cin >> temp;
				map[i][j] = temp;
			}
		}

		//섬일 가능성이 있는 모든 좌표에 대해 bfs해보기
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1 && visited[i][j] == false) //해당 좌표에 1이라 써있고 아직 방문되지 않은 좌표라면
				{
					bfs(pair<int, int>(i, j));
					result++;
				}
			}
		}

		cout << result << '\n';

		//한 케이스 끝날 때 2차원 배열 2개 초기화
		fill(map.begin(), map.end(), vector<int>(50,0));
		fill(visited.begin(), visited.end(), vector<bool>(50,false));

	}
	


	return 0;






}
