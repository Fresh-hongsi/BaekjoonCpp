//brute force
//permutation

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//tsp문제이나, 도시 정점의 개수가 10이하이므로 브루트포스 방식으로 풍어도 가능
//모든 순열을 구해 최소값을 찾는 방식

int TSP(vector<vector<int>>& adjMatrix, vector<int>& city) //city배열에 담긴 순열에 따라 도시 정점 인덱스를 참조해 순회 경로 값 계산
{
	int value = 0;

	
	for (int i = 0; i < city.size() - 1; i++)
	{
		if (adjMatrix[city[i]][city[i + 1]] == 0) //만약 갈 수 없는 경우라면 -1반환
			return -1;
		value += adjMatrix[city[i]][city[i + 1]]; //i번쨰 도시에서 i+1번쨰 도시까지 가는 경로 구해 합산하기
	}

	if (adjMatrix[city[city.size() - 1]][city[0]] == 0) //만약 갈 수 없는 경우라면 -1반환
		return -1;

	value += adjMatrix[city[city.size() - 1]][city[0]]; //마지막 도시에서 처음 도시 경로 합산학기

	return value;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0; //도시의 수
	cin >> N;
	vector<vector<int>> adjMatrix(N, vector<int>(N, 0)); //인접행렬
	vector<int> city; //도시 정점

	for (int i = 0; i < N; i++)
	{
		city.push_back(i);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp = 0;
			cin >> temp;

			adjMatrix[i][j] = temp;
		}
	}

	int min = 1e9; //min값을 최대값으로 설정해놓기

	do
	{
		int current = TSP(adjMatrix, city);
		
		if (current!=-1 && min > current) //만약 순회 가능하고, 현재 나온 min값보다 작은 값이 조사된다면 min값 초기화
		{
			min = current;
		}

	
	} while (next_permutation(city.begin(), city.end())); //계속해서 다음 순열로 갱신
	

	cout << min;
	return 0;

}
