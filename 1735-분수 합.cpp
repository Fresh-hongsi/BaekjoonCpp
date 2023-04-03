#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a_numerator; //첫번째 분수의 분자
	int a_denominator; //첫번째 분수의 분모

	int b_numerator; //두번째 분수의 분자
	int b_denominator; //첫번째 분수의 분모

	cin >> a_numerator >> a_denominator >> b_numerator >> b_denominator;

	int result_numerator; //결과 분수의 분자
	int result_denominator; //결과 분수의 분모

	result_denominator = a_denominator * b_denominator; //결과 분수의 분모를 입력받은 분수의 분모의 곱으로 우선 구해놓음....1번

	int amul = result_denominator / a_denominator; //첫번쨰 분수의 분모에 몇 곱해야 앞서 구한 1번 값을 만족하는지 구하기...2번
	int bmul = result_denominator / b_denominator; //두번쨰 분수의 분모에 몇 곱해야 앞서 구한 1번 값을 만족하는지 구하기...3번

	result_numerator = (a_numerator * amul) + (b_numerator * bmul); //2번과 3번 통해 결과 분수의 분자 값 계산하기(통분의 분자 구하는 과정)

	int commonDivider = 0; //기약 분수 만들기 위해 분자 분모에 공통으로 나눠줄 수 있는 값 구하기 위한 변수
	for (int i =min(result_denominator, result_numerator); i >= 1; i--) //결과 분수의 분자 분모 중 작은 값부터 1씩 줄여나가며 기약분수 만들기 위한 공통인수 찾기
	{
		if ((result_numerator % i == 0) && (result_denominator % i == 0))
		{
			commonDivider = i;
			break; //제일 큰 값 찾으면 탈출
		}
	}

	result_numerator /= commonDivider; //분자 기약분수 만들기
	result_denominator /= commonDivider; //분모 기약분수 만들기

	cout << result_numerator << ' ' << result_denominator; //결과값 출력
	return 0;
}
