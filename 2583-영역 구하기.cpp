#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int M = 0; //모눈종이의 행크기
int N = 0; //모눈종이의 열크기
int K = 0; //직사각형 개수


bool visited[101][101] = { false, }; //초기에 직사각형이 그려진 영역 좌표이면 true ->추후에 빈 영역 넓이를 구하는 과정에서 빈영역이면 true로 바꿔주는 과정을 넣어줄것임(메모리 최소화 위해)
int di[4] = {-1,0,1,0}; //상우하좌 행 변위
int dj[4] = {0,1,0,-1}; //상우하좌 열 변위
vector<int> area; //부분영역들 크기를 저장할 배열


int bfs(pair<int, int> s)
{
	visited[s.first][s.second] = true; //해당 빈 영역 시작 좌표 -> true로 바꿔주기
	queue<pair<int, int>> q; //bfs위해 필요
	q.push(make_pair(s.first, s.second)); //큐에 넣어주기
	int counter = 1; //빈 영역 시작좌표를 찾았으므로 빈 영역 크기 1로 세팅

	while (!q.empty()) //bfs해가면서 빈 영역인 좌표인지 판단 후, 빈 영역의 좌표이면 counter값을 1 늘려줄것 
	{
		int curi = q.front().first; //현재 찾은 빈 영역좌표의 행인덱스
		int curj = q.front().second; //현재 찾은 빈 영역좌표의 열인덱스
		q.pop();

		for (int i = 0; i < 4; i++) //상우하좌 돌아가며 빈 영역이면 큐에 push
		{
			int nexti = curi + di[i];
			int nextj = curj + dj[i];

			if (nexti >= 0 && nexti < M && nextj >= 0 && nextj < N && visited[nexti][nextj] == false) //현재 좌표에서 상우하좌 돌렸을 떄 모눈 종이 범위 안이고, 그 좌표가 빈 영역이라면
			{
				counter++; //빈 영역 크기값 1 증가
				visited[nexti][nextj] = true; //빈 영역임을 찾았으므로 true로 표시
				q.push(make_pair(nexti, nextj)); //큐에 넣어주기
			}
		}
	}

	return counter; //해당 빈 영역 크기를 반환
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) //직사각형의 좌하단 행, 열 값 / 좌상단 행, 열값 입력받아 직사각형 범위 안에 해당하는 좌표 true표시해주기 
	{
		int lx = 0;
		int ly = 0;
		int rx = 0;
		int ry = 0;
		cin >> lx >> ly >> rx >> ry;

		for (int j = ly; j < ry; j++)
		{
			for (int k = lx; k < rx; k++)
			{
				visited[j][k] = true;
			}
		}
	}

	//빈 영역이면 해당 좌표에서 bfs한후, 구해낸 빈 영역 크기를 area배열에 push
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == false)
			{
				int part = bfs(make_pair(i, j));
				area.push_back(part);
			}
		}
	}

	sort(area.begin(), area.end()); //빈 영역들을 다 찾았다면 해당 영역 크기들을 오름차순 정렬
	cout << area.size() << '\n'; //빈영역 개수 출력
	for (int i = 0; i < area.size(); i++) //빈 영역의 크기를 오름차순으로 출력
	{
		cout << area[i] << ' ';
	}

	return 0;



}
