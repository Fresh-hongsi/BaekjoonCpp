#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_NODE 101
#define MAX_EDGE 5001
#define MAX_VALUE 600000
int numPerson = 0; //사람 수
int edge = 0; //간선 수
vector<int> map[MAX_NODE];
int baconNum[MAX_NODE] = { MAX_VALUE, };



void bfs(int start)
{
	bool visited[MAX_NODE] = { false }; //일단 기본으로 아무곳도 방문되지 않음
	int counter = 0;
	visited[start] = true; //방문표시

	queue<pair<int, int>> q;
	q.push(make_pair(start, 0));

	while (!q.empty())
	{
		int cur = q.front().first;
		int depth = q.front().second;
		
		counter += depth; //baconNum을 구하기 위해 현재 start에 있는 사람과 큐에서 뽑은 사람과의 관계깊이 크기 더해주기

		q.pop();

		for (int i : map[cur]) //큐에서 뽑힌 사람과 연결된 다른 사람을 하나씩 순회하며
		{
			if (visited[i] == false) //만일 아직 연결안된 사람이라면
			{
				visited[i] = true; //연결되었음을 표시하고
				q.push(make_pair(i, depth + 1)); //연결고리를 큐에 추가하되, 연결 깊이는 1깊어짐
			}
		}

		


	}

	baconNum[start] = counter; //해당 사람에 대한 모든 baconNum의 값이 구해졌으면 각 사람의 baconNum값을 저장하기 위해 계산된 counter값을 저장


}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> numPerson >> edge;

	for (int i = 0; i < edge; i++) //간선정보 인접리스트에 양방향 간선으로 저장
	{
		int s = 0;
		int e = 0;
		cin >> s >> e;
		map[s].push_back(e);
		map[e].push_back(s);
	}
	

	for (int i = 1; i <= numPerson; i++) //각 사람마다 한번씩 bfs해서 baconNum값 구하기
	{
		bfs(i);
	}

	//각 사람의 baconNum 중 최소값을 구하고, 최소값인 사람 구하기
	int curNum = baconNum[1];
	int result = 1;
	for (int i = 2; i <= numPerson; i++)
	{
		if (curNum > baconNum[i])
		{
			curNum = baconNum[i];
			result = i;
		}
	}



	cout << result;
	return 0;




}
