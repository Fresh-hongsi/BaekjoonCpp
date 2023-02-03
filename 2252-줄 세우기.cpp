#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

//위상정렬 이용한 문제
//https://yoongrammer.tistory.com/86

bool visited[32001] = { false, }; //방문표시 위한 배열
int in_degree[32001] = { 0, }; //해당 정점으로 들어오는 간선이 몇개인지 카운트해놓은 배열
vector<int>map[32001]; //인접리스트
int N = 0;
int M = 0;
queue<int> T; //위상정렬 순서에 맞게 정렬되어진 큐
queue<int> Q; //위상정렬 전 중간과정에서의 큐


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	//인접리스트 초기화 과정
	for (int i = 0; i < M; i++)
	{
		int start = 0;
		int end = 0;
		cin >> start >> end;

		map[start].push_back(end);
		in_degree[end]++; //end정점으로 들어오는 간선 개수 count

	}

	//in_degree가 0인 정점을 Q에 넣어주고 방문표시해줌
	for (int i = 1; i <= N; i++)
	{
		if (in_degree[i] == 0)
		{
			Q.push(i);
			visited[i] = true;
		}
	}


	//Q라는 큐가 빌 때까지 반복 
	while (!Q.empty())
	{
		int cur=Q.front(); //현재 Q에서 가장 앞에 있는 정점 찾고
		Q.pop(); //pop해준 후 
		T.push(cur); //구한 cur값을 최종 큐인 T에 넣어줌

		for (auto i : map[cur]) //cur에 인접해있는 다른 정점을 보기
			
			//다만 아직 방문되지 않은 정점이면 in_degree를 1만 감소시켜주기
			//만약 in_degree값이 0이된 정점이면 그 정점을 중간 큐인 Q에 넣어주고 방문표시
		{
			if (visited[i] == false)
			{
				in_degree[i]--;
			}

			if (in_degree[i] == 0)
			{
				visited[i] = true;
				Q.push(i);
			}
		}
	}
	
	//위의 반복문을 다 돌고 나오면 T란 큐엔 위상정렬 순서대로 들어가있을 것
	//따라서 전체 T의 크기를 알아낸 후, 순서대로 출력
	int TSize = T.size();
	for (int i = 0; i < TSize; i++)
	{
		cout << T.front() << ' ';
		T.pop();
	}

	return 0;


}
