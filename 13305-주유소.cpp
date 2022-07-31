//greedy

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0; //도시 정점의 개수
	int M = 0; //도시 간의 거리 수

	cin >> N;
	M = N - 1;

	vector<long long> cityPrice; //주유소당 기름값을 담을 배열
	vector<long long> distance; //도시간의 거리를 담을 배열

	while (M--) //도시 간의 거리 값을 입력받아 넣음
	{
		long long dist = 0;
		cin >> dist;

		distance.push_back(dist);
	}
	distance.push_back(0); //맨 마지막 도시에서 다음 도시(없음)로의 거리를 0으로 세팅!!!(후에 반복문 시 연산의 용이성을 위해 넣어둠)

	while (N--) //주유소당 기름값을 입력받아 저장
	{
		long long price = 0;
		cin >> price;
		cityPrice.push_back(price);
	}

	//지금 들른 주유소 가격보다 싼 주유소가 나타날때까지는 지금 주유소에서 기름 넣고 달려야함

	long long cheepestCity = cityPrice[0]; //첫번째 주유소 가격이 처음엔 가장 싼 주유소 가격임
	long long curDist = distance[0]; //첫번째 도시에서 두번째 도시까지의 거리
	long long price = cheepestCity*curDist; //첫번째 도시에서 두번째 도시까지는 무조건 첫번째 도시에서 기름을 넣고 달려야함

	for (int cur = 1; cur < cityPrice.size(); cur++) //두번째 도시부터 마지막 도시까지 순회하며 조건 검사
	{
		if (cheepestCity > cityPrice[cur]) //만약 마지막에 기름 넣은 주유소보다 싼 주유소가 나타나면 
		{
			cheepestCity = cityPrice[cur]; //이 주유소에서 기름을 넣어야하므로 cheepestCity값을 이 주유소로 변경 
			price += (cheepestCity * distance[cur]); //지금까지의 기름값에다가 이 주유소에서 다음주요소까지의 거리 곱을 더함
		}

		else //만약 현재 도시의 기름값이 마지막에 기름 넣은 주유소보다 가격이 비싸거나 같다면 -> 전 주유소에서 기름을 더 넣는 게 효율적임
		{
			price += cheepestCity * distance[cur]; //지금까지의 기름값에다가 가장 쌌던 전 주유소 가격과 현재 거리 곱을 더함

		}
	}

	cout << price << '\n';
	return 0;



}
