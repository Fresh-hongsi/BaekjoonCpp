#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<bool> visited;


int main(void)
{
	int N = 0; //가장 큰 정수 값 입력
	int K = 0; //k번째에 지워지는 수를 찾기 위해 입력

	cin >> N >> K;

	for (int i = 0; i <= N; i++)
	{
		
		visited.push_back(false);
	}

	

	int cur = 0;
	int counter = 0;


	while (1)
	{
		for (int i = 2; i <= N; i++)
		{
			if (visited[i] == false) //첫번쨰 소수 찾기
			{
				cur = i;
				break;
			}
		}
		for (int i = cur; i <= N; i += cur) //첫번째 소수부터 그 소수의 배수가 되는 것 count하며 방문표시
		{
			if (visited[i] == false)
			{
				visited[i] = true;
				counter++;
				
			}

			if (counter == K) //k번째로 찾은 소수 출력 후 종료
			{
				cout << i;
				return 0;
			}
			
			
		}
	}
	

}
