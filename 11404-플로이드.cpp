//플로이드-워셜 알고리즘 -> O(V^3)

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

#define MAX_COST 10000000 
int num_of_City = 0;
int num_of_Bus = 0;
int adjMatrix[101][101]; //인접행렬


//3중 for문 통해 플로이드-와셜 알고리즘 적용
void floyd(void)
{
	for (int m = 0; m < num_of_City; m++)
	{
		for (int i = 0; i < num_of_City; i++)
		{
			for (int j = 0; j < num_of_City; j++)
			{
				if (adjMatrix[i][j] > adjMatrix[i][m] + adjMatrix[m][j])
				{
					adjMatrix[i][j] = adjMatrix[i][m] + adjMatrix[m][j];
				}
			}
		}
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> num_of_City >> num_of_Bus;


	//시작 정점과 도착정점이 같은 경우엔 최단거리 0으로 적용, 그 외의 경우에는 max_cost로 적용
	for (int i = 0; i < num_of_City; i++)
	{
		for (int j = 0; j < num_of_City; j++)
		{

			if (i == j)
			{
				adjMatrix[i][j] = 0;
			}
			else
			{
				adjMatrix[i][j] = MAX_COST;
			}
			


		}

	}

	//간선정보 인접행렬에 저장 (만약 더 비용 저렴한 간선이 있으면 그 간선으로 다시 인접행렬 초기화 진행
	for (int i = 0; i < num_of_Bus; i++)
	{
		int start = 0;
		int end = 0;
		int cost = 0;

		cin >> start >> end >> cost;

		if (adjMatrix[start - 1][end - 1] > cost)
		{
			adjMatrix[start - 1][end - 1] = cost;
		}
		
	}

	floyd();


	//출력부
	for (int i = 0; i < num_of_City; i++)
	{
		for (int j = 0; j < num_of_City; j++)
		{

			//시작정점과 도착정점이 같거나 최단거리를 구할 수 없는 경로라면 0 출력
			if (adjMatrix[i][j] == MAX_COST || adjMatrix[i][j]==0)
			{
				adjMatrix[i][j] = 0;
				cout << adjMatrix[i][j] << ' ';
			}

			//그 외의 경우 구한 최단거리 값 출력
			else
			{
				cout << adjMatrix[i][j] << ' ';
			}
		}

		cout << '\n';
	}

	return 0;


}
