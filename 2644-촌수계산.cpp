#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;


int personNum = 0; //총 사람의 수
int relationNum = 0; //총 관계의 수

int ob1 = 0; //출발점
int ob2 = 0; //도착점

int counter = 0; //촌수

vector<int> relation[101]; //관계 담을 인접리스트

int visited[101] = { false, }; //이미 한번 들른 사람에 대해서는 더 촌수계산할 필요가 없으므로 visited표시해주기 위한 배열

bool flag = false; //촌수를 맺을 수 있는 관계이면 true, 없으면 false -> 우선 처음에는 촌수관계를 아직 못찾았으므로 false처리

void bfs(pair<int,int> start) //start.first: bfs를 시작할 정점, start.second: 현재 bfs깊이 수(촌수)
{
	visited[start.first] = true;
	queue<pair<int,int>> q;
	q.push(make_pair(start.first,start.second));

	while (!q.empty())
	{
		int cur = q.front().first; //현재 bfs중인 정점 확인
		counter = q.front().second; //현재 cur정점의 촌수 확인
		q.pop(); //큐에서 제거

		if (cur == ob2) //촌수 관계를 찾았으면
		{
			flag = true; //관계 찾음 표시
			return; //함수 반환
		}

		else //아직 못찾았으면
		{
			for (auto i : relation[cur]) //cur과 인접한 다른 정점 중
			{
				if (visited[i] == false) //아직 방문하지 않은 정점이 있다면
				{
					visited[i] = true; //방문처리 후
					q.push(make_pair(i,counter+1)); //큐에 촌수와 정점 정보를 넣어줌
				}
			}
		}
	}
}
int main(void)
{
	cin >> personNum;
	cin >> ob1 >> ob2;
	cin >> relationNum;

	//간선 정보 인접리스트에 저장
	for (int i = 0; i < relationNum; i++)
	{
		int s = 0;
		int e = 0;
		cin >> s >> e;

		relation[s].push_back(e);
		relation[e].push_back(s);

	}

	//bfs시도
	bfs(make_pair(ob1,0));

	//관계를 찾았다면
	if (flag == true)
		cout << counter;
	//관계를 못찾았다면
	else
		cout << -1;
	return 0;
}
