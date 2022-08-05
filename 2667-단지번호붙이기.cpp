//Graph
//BFS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N = 0;
vector<vector<int>> complex(25, vector<int>(25, 0)); //아파트 지도
vector<int> apartmentPerComplex; //단지 당 아파트 개수
vector<vector<bool>>visited(25, vector<bool>(25, false)); //아파트 순회 시 방문표시 할 배열

int dx[4] = { 0,-1,0,1 }; //좌,상,우,하에서의 행 위치
int dy[4] = { -1,0,1,0 }; //좌,상,우,하에서의 열 위치

void bfs(pair<int, int> s)
{
	queue<pair<int, int>> q;
	q.push(s);
	visited[s.first][s.second] = true; //첫번째 아파트 방문표시
	int curComplexApartNum = 1; //현 단지 내 아파트 개수 count할 변수, 초기 1로 세팅

	while (!q.empty())
	{
		pair<int, int>cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) //좌상우하 순회하며 조건에 맞으면 bfs계속 해나감
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) //아파트 지도 내에 없는 위치라면 다시 반복문으로
			{
				continue;
			}

			if (complex[nx][ny] == 1 && visited[nx][ny] == false) //해당 위치에 아파트가 있고 방문되지 않은 곳이라면 단지에 추가
			{
				q.push(pair<int, int>(nx, ny));
				visited[nx][ny] = true;
				curComplexApartNum++; //단지 내 아파트 개수 ++

			}
		}


	}

	apartmentPerComplex.push_back(curComplexApartNum); //현 단지 내에서 탐색한 모든 아파트의 개수를 단지당 아파트 개수 배열에 push
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	int number = 0; //아파트 단지 개수

	for (int i = 0; i < N; i++) //아파트 지도에 아파트 위치 저장
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++)
		{
			complex[i][j] = (temp[j]-'0');
		}
	}

	for (int i = 0; i < N; i++) //조건에 맞는 경우 bfs통해 아파트 단지 순회
	{
		for (int j = 0; j < N; j++)
		{
			if (complex[i][j] == 1 && visited[i][j] == false) //해당 위치에 아파트가 있고 방문되지 않았다면
			{
				pair<int, int>start(i, j);
				bfs(start); //단지 생성 및 탐색 시장
				number++; //단지 개수++

			}
		}
	}

	sort(apartmentPerComplex.begin(), apartmentPerComplex.end()); //단지 당 아파트 개수 오름차순 정렬

	cout << number << '\n'; //총 단지 수 출력

	for (auto& i : apartmentPerComplex) //단지 당 아파트 개수 순회하며 출력
	{
		cout << i << '\n';
	}

	return 0;






}
