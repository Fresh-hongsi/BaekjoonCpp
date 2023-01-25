#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

int main(void)
{
	time_t rawtime;
	struct tm* pTimeInfo;
	rawtime= time(NULL);

	pTimeInfo = localtime(&rawtime);

	int year = pTimeInfo->tm_year + 1900;
	int month = pTimeInfo->tm_mon+1;
	int day = pTimeInfo->tm_mday;

	string sMonth = to_string(month);
	string sDay = to_string(day);

	if (sMonth.size() == 1)
	{
		
	}
	cout << year << endl;
	if (sMonth.size() == 1)
	{
		cout << 0 << sMonth << endl;


	} 
	else
	{
		cout << month << endl;
	}
	
	if (sDay.size() == 1)
	{
		cout << 0 << sDay << endl;


	}
	else
	{
		cout <<sDay<< endl;
	} 


	return 0;
}
