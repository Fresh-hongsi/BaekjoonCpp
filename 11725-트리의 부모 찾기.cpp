#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <queue>
using namespace std;

vector<int>map[100001]; //인접리스트
bool visited[100001] = { false, }; //벙문표시배열
vector<int> parent[100001]; //각 정점의 부모 저장할 인접리스트

void bfs(pair<int,int> s)
{
	visited[s.second] = true;
	queue<pair<int,int>> q;

	q.push(s);

	while (!q.empty())
	{
		int p = q.front().first; //해당 정점의 부모 번호
		int cur = q.front().second; //해당 정점 번호
		q.pop();

		parent[cur].push_back(p);

		for (auto k:map[cur]) //k: 다음 정점 번호
		{
			if (visited[k] == false) //다음 정점이 방문되지 않았다면
			{
				q.push(make_pair(cur,k)); //현재 정점이 부모가 되고 다음 정점 번호를 같이 큐에 넣어줌
				visited[k] = true; //방문표시함

			}
		}



	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int nodeNum = 0;
	cin >> nodeNum;

	for (int i = 1; i <= nodeNum-1; i++)
	{
		int start = 0;
		int end = 0;
		
		cin >> start >> end;
		map[start].push_back(end);
		map[end].push_back(start);

	}

	bfs(make_pair(1,1));

	for (int i = 2; i <= nodeNum; i++)
	{
		cout << parent[i][0] << '\n';
	}
	
	return 0;


}
