//Graph
//BFS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>>picture(500, vector<int>(500)); //그림에 대한 2차원 벡터
vector<vector<bool>>visited(500, vector<bool>(500, false)); //방문했는지 표시할 2차원 벡터
vector<int> pictureSize; //그림의 크기들을 저장할 1차원 벡터
int dx[4] = { 0,-1,0,1 }; //좌상우하 탐색해볼 떄 행값의 변화량
int dy[4] = { -1,0,1,0 }; //좌상우하 탐색해볼 떄 열값의 변화량
int h = 0; //도화지 세로 길이
int w = 0; //도화지 가로 길이
int picNum = 0; //도화지 내의 그림 개수


bool compare(int i, int j)
{
	return i > j;

}

void bfs(pair<int,int> start)
{
	queue<pair<int, int>> q;
	q.push(start);
	int size = 1; //bfs 시작한 픽셀을 큐에 넣음과 동시에 그림 size는 1
	
	
	visited[start.first][start.second] = true; //시작 픽셀에 대한 방문 표시

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)//좌상우하 변화량을 측정하여 그래프에 넣을 수 있으면 그래프에 추가하는 과정
		{
			int nx = cur.first + dx[i]; //행 좌표
			int ny = cur.second + dy[i]; //열 좌표

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) //탐색하는 픽셀의 좌표가 도화지 밖의 범위를 참조하는 경우 참조하면 안됨
			{
				continue;
			}

			if (picture[nx][ny] == 1 && visited[nx][ny] == false) //픽셀이 1이고 방문하지 않은 좌표라면 큐에 넣고 방문표시하기
			{
				visited[nx][ny] = true;
				q.push(pair<int, int>(nx, ny));
				size++; //그림 사이즈 1 증가시킴

			}
		}
	}

	pictureSize.push_back(size); //bfs끝났으면 현재 size를 size배열에 넣어주기
}



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> h >> w; //h:행 길이. w:열 길이

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> picture[i][j];
		}
	}

	//도화지에서 조건에 부합하는 모든 1인 픽셀에 대해 bfs 실행해보기
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (visited[i][j] == true || picture[i][j] == 0) //해당 픽셀이 이미 방문되었거나 0값이라면 bfs할 필요가 없음
			{
				continue;
			}

			pair<int, int> startPixel(i, j); //해당 좌표를 시작으로하는 pair생성

			bfs(startPixel); //그림의 크기 알아내기 위해 시작 좌표를 설정하여 bfs실행
			picNum++; //그림 한개 있는 것이므로 그림 개수 추가

		}
	}

	int picsize = 0; //그림이 한개도 없을 경우 size는 0으로 세팅
	if (pictureSize.size() != 0) //그림이 한개 이상 있을 경우
	{
		sort(pictureSize.begin(), pictureSize.end(), compare); //그림의 크기 내림차순 정렬
		picsize = pictureSize[0];
	}
	

	cout << picNum << '\n' << picsize;
	return 0;
	


}
