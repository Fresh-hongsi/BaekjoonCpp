#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <string>
using namespace std;
//플로이드 와셜 알고리즘

#define MAX_COST 250000
int pNum = 0;
int edgeNum = 0;
int adjMatrix[500][500];

void floyd()
{
	for (int m = 0; m < pNum; m++)
	{
		for (int i = 0; i < pNum; i++)
		{
			for (int j = 0; j < pNum; j++)
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


	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			adjMatrix[i][j] = MAX_COST;
		}
	}

	cin >> pNum >> edgeNum;


	for (int i = 0; i < edgeNum; i++)
	{
		int s = 0;
		int e = 0;
		cin >> s >> e;
		adjMatrix[s - 1][e - 1] = 1;
	}


	floyd();

	
	int answer = 0;
	for (int i = 0; i < pNum; i++)
	{
		
		int counter = 0;

		for (int j = 0; j < pNum; j++)
		{
			if (adjMatrix[i][j] != MAX_COST || adjMatrix[j][i] != MAX_COST)  //i보다 큰 사람이 존재 또는 i보다 작은 사람이 존재하면
			{
				counter++; //연결정점 개수+1
			}

		}

		if (counter == pNum - 1)
		{
			answer++; //i가 자신을 제외한 모든 정점과 연결되어 있음(키 순서를 정확히 파악 가능), 답+1
		}
	}
	
	cout << answer;
	
	return 0;
	
}
