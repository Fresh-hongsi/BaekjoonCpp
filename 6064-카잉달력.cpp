//MATH
//NUMBER THEORY

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc = 0;
	cin >> tc;

	while (tc--) //TC마다 연산 후 출력
	{
		int M = 0; 
		int N = 0;

		int x = 0; //대상이 존재하는 지 확인할 X -> M에 대응
		int y = 0; //대상이 존재하는 지 확인할 Y -> N에 대응

		cin >> M >> N >> x >> y; //입력받음

		

		if (x > M && y > N) //범위 바깥의 년도라면 -1 출력
		{
			cout << -1 << '\n';
			continue;
		}

		//나머지 정리를 활용한 문제풀이
		int count = x; //count변수는 첫해부터 목표 년도까지 얼마나 떨어져있는 지 저장할 변수.
		bool isExist = false; //isExist: 목표 년도가 실제로 역법에 있다면 true / 역법에 존재할 수 없으면 false

		while (count<=M*N) //count변수의 최대값은 M*N값임
		{
			
			int i = count % M; //세팅된 count변수에 M을 나눈 나머지 값은 i변수값. i변수를 고정시킴으로써 모든 년도에 대한 전수조사를 하는 것이 아니게 됨!!
			int j = count % N; //세팅된 count변수에 M을 나눈 나머지 값은 j변수값(계속 바뀌어감)
			
			if (i == x%M && j == y%N) //만일 i,j변수가 목표지점을 각각 M과 N으로 나눈 나머지 값과 같다면
			{

				cout << count << '\n'; //목표 년도를 찾은 것이므로 count변수 출력
				isExist = true; //해당 년도가 존재함을 표시
				break;
			}
			count += (M); //count변수에 M값을 더해가며 진행.
		}

		if (isExist == false) //반복문 다 돌았는데도 목표년도를 찾지 못했으면 -1출력
		{
			cout << -1 << '\n';
		}
	}
}
