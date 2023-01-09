#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
#include <vector>
#include<cstring>
using namespace std;

int map[301][301]={0,};

int firsti = 0; //시작점의 행 위치
int firstj = 0; //시작점의 열 위치
int lasti = 0; //도착점의 행 위치
int lastj = 0; //도착점의 열 위치

int di[8] = { -2,-1,1,2,2,1,-1,-2 }; //행 인덱스의 변화값
int dj[8] = { 1,2,2,1,-1,-2,-2,-1 }; //열 인덱스의 변화값
int sizeM; //각 테스트 케이스마다의 체스판 변 길이
bool visited[301][301] = { false, }; //방문표시 목적의 2차원 배열

void bfs(pair<int, int>f)
{
	memset(visited, false, sizeof(visited)); //각 tc마다 배열 초기화
	memset(map, 0, sizeof(map)); //각 tc마다 배열 초기화
	visited[f.first][f.second] = true; //나이트의 시작점 방문표시

	queue<pair<int, int>> q;
	q.push(make_pair(f.first, f.second)); //첫번째 위치 큐에 삽입

	while (!q.empty())
	{
		int curI =q.front().first;
		int curJ = q.front().second;
		

		q.pop();

		if (curI == sizeM - 1 - lasti && curJ == lastj) //도착지에 다다랐으면 그때의 depth출력
		{
			cout << map[curI][curJ] << '\n';

			break;
		}

		for (int i = 0; i < 8; i++) //현재 나이트 위치에서 8가지 방향으로 가보기 -> 단, 범위 밖에 있거나 이미 방문된곳이면 갈 필요가 없음
		{
			if (curI + di[i] >= 0 && curJ + dj[i] >= 0 && curI + di[i] <= sizeM - 1 && curJ + dj[i] <= sizeM - 1 && visited[curI + di[i]][curJ + dj[i]] == false)
			{
				visited[curI + di[i]][curJ + dj[i]] = true; //방문표시해줌
				map[curI + di[i]][curJ + dj[i]]=map[curI][curJ]+1; //map 이차원 배열에 depth값을 저장해 나갈 것임. 현재 위치의 depth에다가 1 더한 값을 다음 방문한 곳의 위치에 저장해나감
				q.push(make_pair(curI + di[i], curJ + dj[i])); //이제 방문이 안됐던 곳을 방문했으므로 큐에 넣어줌으로써 다음 깊이에서의 search를 시도한다.
			}
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int tc = 0;
	cin >> tc;

	while (tc--)
	{

		cin >> sizeM; //한 변의 길이
		cin >> firstj >> firsti >> lastj >> lasti; //input을 거꾸로 받아줘야 i,j 2차원 행렬 인덱스 구하는 데에 용이

		pair<int, int>first = make_pair(sizeM - 1 - firsti, firstj); //2차원 행렬에 맞게 input받은 직사각형 x,y좌표 변환
		

		bfs(first); //탐색 시작

	}


}
