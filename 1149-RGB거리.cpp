#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{


	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int arr[1001][3]; //색칠하는 비용 저장받을 배열
	int dynamic[1001][3]; //밑단계부터 하나씩 살펴보면서 각 집까지 색칠하는 최저 비용 담을 배열
	int n = 0;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			cin >> arr[i][j]; //각 집 색칠하는 데 필요한 r,g,b 비용 입력받아 배열에 저장
		}
	}

	//0번째(첫번째 단계)에서 집 색깔을 r,g,b를 고르는 경우 
	dynamic[0][0] = arr[0][0]; //첫번째 집-r
	dynamic[0][1] = arr[0][1]; //첫번째 집-g
	dynamic[0][2] = arr[0][2]; //첫번째 집-b


	for (int i = 1; i < n; i++) //1단계부터 (2번째집부터) n-1단계(마지막 집까지)
	{
		dynamic[i][0] = min(dynamic[i - 1][1], dynamic[i - 1][2])+arr[i][0]; //이번 단계에 r을 색칠하는 경우, 최소값은 (그 전단계g를 고른 최솟값 또는 그 전단계 b를 고른 최솟값) 중 하나 
		dynamic[i][1] = min(dynamic[i - 1][0], dynamic[i - 1][2])+arr[i][1]; //이번 단계에 g을 색칠하는 경우, 최소값은 (그 전단계r를 고른 최솟값 또는 그 전단계 b를 고른 최솟값) 중 하나 
		dynamic[i][2] = min(dynamic[i - 1][0], dynamic[i - 1][1])+arr[i][2]; //이번 단계에 b을 색칠하는 경우, 최소값은 (그 전단계r를 고른 최솟값 또는 그 전단계 g를 고른 최솟값) 중 하나 
	}

	//마지막 단계가 r,g,b일 때 중에서의 최솟값을 또 구해야함
	int result = dynamic[n - 1][0]; //마지막 집이 r일때를 기준
	for (int i = 1; i <= 2; i++) //혹시라도 마지막 집이 g나 b일 때 더 작은 값이 있다면
	{
		if (result > dynamic[n - 1][i])
		{
			result = dynamic[n - 1][i]; //그게 최솟값
		}
	}

	cout << result << endl;


	
}
