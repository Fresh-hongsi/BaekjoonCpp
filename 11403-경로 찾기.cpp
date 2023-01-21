#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//플로이드-워셜 알고리즘: 그래프에서, 가능한 모든 노드쌍에 대해 최단 거리를 구하는 알고리즘 -> 시간 복잡도: O(v^3)
//다익스트라 알고리즘과는 달리, 모든 노드 쌍에 대해 최단거리를 구하고, 음의 가중치를 가지는 그래프에서도 쓸 수 있음
//다익스트라 알고리즘은 하나의 노드로부터 최단경로를 구하는 알고리즘이라면, 플로이드-워셜은 가능한 모든 노드쌍에 대한 최단거리를 구하는 알고리즘임

#define INF 999999999

int adjArr[101][101]; //인접행렬
int N = 0;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	//플로이드 워셜 알고리즘을 통해 경로의 유무만 판단할 것
	//우선, 별다른 간선이 이어진 것이 없이 시작정점과 도착정점이 같은 상태인 경우, 경로가 없는 것이므로 초기에 INF처리해줌
	//간선 정보 받아서, 간선이 존재하는 경우 1이란 값을 인접행렬에 저장, 만약 간선이 없는 경우엔 INF값을 인접행렬에 저장
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp = 0;
			cin >> temp;
			if (temp == 0)
			{
				adjArr[i][j] = INF;
			}

			else
			{
				adjArr[i][j] = 1;
			}
			
		}
	}

	//플로이드 - 워셜 알고리즘 이용, 이 문제에선 모든 정점 사이의 최단경로의 길이가 아닌 경로의 유무만을 판단하면 되나, 나는 모든 노드간의 최단경로값을 계산해 저장할 것
	//중간 도착지인 m값에 대한 반복문을 가장 바깥쪽에 위치시켜야 플로이드 - 워셜 알고리즘이 됨
	//계산 과정에서 해당 인덱스의 인접행렬의 값이 INF가 아니게 되면 경로가 존재하는 것이며, 그때 상황에서의 최단경로값이 저장됨 
	for (int m = 0; m < N; m++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (adjArr[i][j] > adjArr[i][m] + adjArr[m][j])
				{
					adjArr[i][j] = adjArr[i][m] + adjArr[m][j];
				}
			}
		}
	}

	//모든 노드 간의 최단경로가 구해졌으나, 경로가 존재하는지만 출력하면 된다
	//반복문을 순회하며 만약 해당 인덱스의 최단 경로값이 INF라면, 최단 경로가 존재하지 않는 것
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (adjArr[i][j] == INF)
			{
				cout << 0 << ' ';
			}

			else
			{
				cout << 1 << ' ';
			}
			
		}
		cout << '\n';
	}


	return 0;
}
