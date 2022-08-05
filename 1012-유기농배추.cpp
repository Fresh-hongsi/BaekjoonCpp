//Graph
//bfs

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


vector<vector <int>> gorangji(50, vector<int>(50, 0)); //배추밭에 있는 배추 위치 저장된 배열
vector<vector<bool>> visited(50, vector<bool>(50, false)); //방문된 배추 위치 확인용
int row = 0; //행
int column = 0; //열
int cabbage = 0; //배추 개수

int dx[4] = { 0,-1,0,1 }; //좌,상,우,하에서의 행 위치
int dy[4] = { -1,0,1,0 }; //좌,상,우,하에서의 열 위치


void bfs(pair<int, int> s) //해당 위치에 배추벌레 놓았을 때 따로 더 놓지 않아도 되는 배추를 visited표시
{
	queue<pair<int, int>> q;
	q.push(s);
	visited[s.first][s.second] = true;

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) //상하좌우 순회하며 배추벌레가 이동할 수 있는 경로인 지 확인
		{
			int nx = cur.first + dx[i]; 
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= row || ny < 0 || ny >= column) //배추밭 넘어가는 경우 무효
			{
				continue;
			}

			if (gorangji[nx][ny] == 1 && visited[nx][ny] == false) //그 위치에 배추가 있고 방문되지 않은 배추라면 방문표시해주고 큐에 해당 배추 넣어둠
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

	int T = 0; //테스트 케이스 개수
	cin >> T;

	while (T--)
	{
		int bug = 0; //배추밭에 놓일 배추벌레 개수 0부터 시작
		cin >> row >> column >> cabbage;

		for (int i = 1; i <= cabbage; i++) //배추 위치를 배추밭에 저장
		{
			int r = 0;
			int c = 0;
			cin >> r >> c;
			gorangji[r][c] = 1;
		}

		for (int i = 0; i < row; i++) //모든 배추 밭을 순회하며 배추벌레를 놓을 위치를 선정
		{
			for (int j = 0; j < column; j++)
			{
				if (gorangji[i][j] == 1 && visited[i][j] == false) //만약 해당 위치에 배추가 있고, 그 배추가 방문된 배추가 아니라면 벌레 놓고 bfs탐색
				{
					pair<int, int> start(i, j);
					bfs(start);
					bug++;
				}
			}
		}

		cout << bug << '\n'; //각 tc에 대한 배추벌레 개수 출력

		fill(gorangji.begin(), gorangji.end(), vector<int>(gorangji[0].size(),0)); //한 tc 끝나면 배추밭 초기상태로 초기화
		fill(visited.begin(), visited.end(), vector<bool>(visited[0].size(),false)); // 한 tc 끝나면 방문표시 초기상태로 초기화
		
	}

	return 0;
}
