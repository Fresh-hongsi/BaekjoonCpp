#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime> //현재 시간과 날짜 관련 파일
using namespace std;

//날짜 시간 데이터를 가지는 struct tm을 이용해서 현재 날짜를 출력
//tm_year는 1900년 이후 값, tm_mon은 0~11 사이의 값을 가지므로 각각 1900과 1을 더하고 출력
//cout을 사용한다면 cout.width()와 cout.fill()로 월일 표현 범위를 2로 설정
int main(void) {

	//이 부분은 암기하기
	struct tm* t;
	time_t timer;
	timer = time(NULL);
	t = localtime(&timer);

	cout << t->tm_year+1900; //년 계산
	

	cout << '-';
	cout.width(2); //두자리 출력
	cout.fill('0'); //남은 빈칸 0으로 채우기
	cout << t->tm_mon+1;
	
	
	cout << '-';
	cout.width(2); //두자리 출력
	cout.fill('0'); //남은 빈칸 0으로 채우기
	cout << t->tm_mday;
	

	return 0;
}

