#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
string a, b;

int main()
{
	cin >> a >> b;

	//strstr:
		//부분문자열이 있는지 확인해주는 함수
		//부분문자열이 있다면 해당 문자열 포인터 반환
		//부분문자열이 없다면 null반환
	//c_str: string형태을 char* 형으로 바꿔주는 함수
	if (strstr((char*)a.c_str(), (char*)b.c_str())==NULL)
		cout << 0;
	else
		cout << 1;

	return 0;
}
