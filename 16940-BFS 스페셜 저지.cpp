#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;


//특이한 방법을 통해 인접리스트를 정렬 -> 이를 토대로 스페셜 저지 알고리즘 구축 가능

int N = 0; //정점 개수
vector<int> map[100001]; //인접리스트
bool visited[100001] = { false, };
vector<int> inputOrder; //채점받을 bfs방문 순서
vector<int> specialOrder(100001,0); //특별한 정렬에 이용할 bfs방문순서
vector<int> resultOrder; //정렬순서에 맞게 적용된 인접리스트를 가지고 구한 bfs방문순서

bool comp(int a, int b) //인접리스트 정렬 기준
{
	return specialOrder[a] < specialOrder[b];
}


void bfs(int start) //실제 bfs하는 부분
{
	visited[start] = true;
	resultOrder.push_back(start);

	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto k : map[cur])
		{
			if (visited[k] == false)
			{
				visited[k] = true;
				q.push(k);
				resultOrder.push_back(k);
			}
		}
	}

	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N; //정점개수 입력받음

	//인접리스트 초기화
	for (int i = 1; i < N; i++)
	{
		int s = 0;
		int e = 0;
		cin >> s >> e;

		map[s].push_back(e);
		map[e].push_back(s);
	}

	inputOrder.push_back(0); //첫번째 항은 사용 안하는데 인덱스 번호 맞춰주기 위해 푸시백

	for (int i = 1; i <= N; i++) //채점받을 bfs순서 입력받아 저장, 인접리스트를 정렬해주기 위한 정렬순서 구해서 specialOrder에 저장
	{
		int temp = 0;
		cin >> temp;
		inputOrder.push_back(temp);
		specialOrder[inputOrder[i]] = i;
	}


	//인접리스트를 특별한 정렬 순서에 맞게 정렬
	for (int i = 1; i <= N; i++)
	{
		sort(map[i].begin(), map[i].end(), comp);
	}


	//인접리스트가 정렬되었으므로 이제 정렬된 인접리스트 기반해서 bfs돌린 방문 방문순서와 inputOrder가 같으면 정확한 정답이고, 하나라도 다르면 틀린 것임

	
	resultOrder.push_back(0); //inputOrder과 후에 비교하기 위해 0 대입-> inputOrder도 첫번째 항은 0임

	bfs(1); //1번 정점을 시작 정점으로 해서 bfs시도, resultOrder엔 정렬된 인접리스트 기반하여 구한 실제 bfs한 순서 정보가 저장되어있을 것

	bool flag = true;

	//inputOrder와 resultOrder가 모두 같은 지 확인
	for (int i = 1; i <= N; i++)
	{
		if (inputOrder[i] != resultOrder[i])
		{
			flag = false;
			cout << "0" << '\n';
			break;
		}
	}

	if (flag == true)
	{
		cout << "1" << '\n';
	}

	return 0;
}
