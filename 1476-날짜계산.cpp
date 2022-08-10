#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	//출력 대상이 되는 E,S,M 날짜 변수
	int E = 0; 
	int S = 0;
	int M = 0;

	cin >> E >> S >> M;

	//반복문 안에서 해당 변수들은 바뀌며, E,S,M변수와 모두 똑같아질 때까지 반복문 탈출
	int varE = 1;
	int varS = 1;
	int varM = 1;
	int count = 1; //E/S/M과 똑같은 값을 가지는 지구의 년도

	while (1)
	{
		if (varE == E && varS == S && varM == M) //모두 같으면 결과값 찾은 것임
		{
			break;
		}
		
		if (varE == 15)
		{
			varE = 1;
		}
		else
		{
			varE++;
		}

		if (varS == 28)
		{
			varS = 1;
		}
		else
		{
			varS++;
		}

		if (varM == 19)
		{
			varM = 1;
		}
		else
		{
			varM++;
		}
		count++;
	}

	cout << count;
	return 0;

}
