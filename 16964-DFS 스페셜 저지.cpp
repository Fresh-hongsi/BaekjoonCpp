#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

//문제 풀이 과정은 16940 bfs 스페셜 저지와 똑같음
//즉 인접리스트 정렬과정은 bfs스페셜 저지 문제나 dfs스페셜 저지나 똑같음
//다만 이 문제는 정렬된 인접리스트를 'dfs' 했을 때 결과 배열인 resultOrder과 처음에 입력받은 inputOrder이 같은 지 판단해야함
int N = 0;
vector<int> map[100001];
vector<int> inputOrder;
vector<int> specialOrder(100001, 0);
vector<int> resultOrder;
bool visited[100001] = { false, };


bool comp(int a, int b)
{
	return specialOrder[a] < specialOrder[b];
}

void dfs(int cur)
{
	if (visited[cur] == true)
	{
		return;
	}

	visited[cur] = true;
	resultOrder.push_back(cur);

	for (auto k : map[cur])
	{
		if (visited[k] == false)
		{
			dfs(k);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 1; i < N ; i++)
	{
		int s = 0;
		int e = 0;
		cin >> s >> e;

		map[s].push_back(e);
		map[e].push_back(s);

	}

	inputOrder.push_back(0);

	for (int i = 1; i <= N; i++)
	{
		int temp = 0;
		cin >> temp;
		inputOrder.push_back(temp);
		specialOrder[inputOrder[i]] = i;
	}

	for (int i = 1; i <= N; i++)
	{
		sort(map[i].begin(), map[i].end(), comp);
	}

	resultOrder.push_back(0);

	dfs(1);


	bool flag = true;
	for (int i = 1; i <= N; i++)
	{
		if (resultOrder[i] != inputOrder[i])
		{
			flag = false;
			cout << "0" << endl;
			break;
		}
	}

	if (flag == true)
	{
		cout << "1" << endl;
	}

	return 0;
	

}
