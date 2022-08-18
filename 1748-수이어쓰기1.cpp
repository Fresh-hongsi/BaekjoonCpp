//math
//implementation

#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

int main(void)
{
	int target = 0; //target까지 숫자를 나열했을 때 총 문자열의 길이가 어떻게 되는 지 확인할 것임
	int count = 0; //결과값
	int cur = 1; //해당 자릿수를 가지는 숫자가 몇개있는지 계산하기 위한 변수
	int front_cur = 0; //반복문 하나 전의 cur값 담음
	int range = 0; //해당 자릿수를 가지는 숫자의 개수
	cin >> target;
	
	
	for (int i = 1; i <= 9; i++) //자릿수가 1인 수부터 9자리인 수까지 반복해봄
	{
		if ((target / (cur * 10)) > 0) //target변수가 각가 10, 100, 1000 ... 10^8 자리 이상이면 해당 자릿수를 가진 숫자 개수를 찾고 , 그 자릿수에 해당하는 값을 곱한 후 그 값을 count변수에 더해나감
		{
			front_cur = cur; //현재 cur값 저장
			cur *= 10; //cur값 변경
			range = cur - front_cur; //해당 자릿수를 가진 수의 개수
			count += (range * i); //count변수에 (자릿수*자릿수를 가진 수의 개수)값을 더해나감
		}


		else //target변수가 더 작다면 -> 숫자의 개수는 target-cur+1이며, 그 값과 자릿수를 곱한 값을 count변수에 넣고 반복문 탈출
		{
			range = target - cur + 1;
			count += range * i;
			break;
			
		}


		
	}

	cout << count;
	return 0;
}
