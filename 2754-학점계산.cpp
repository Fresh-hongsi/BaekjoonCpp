#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int main(void)
{
	vector<pair<string, double>>arr;

	pair<string, double> temp1("A+", 4.3);
	pair<string, double> temp2("A0", 4.0);
	pair<string, double> temp3("A-", 3.7);
	pair<string, double> temp4("B+", 3.3);
	pair<string, double> temp5("B0", 3.0);
	pair<string, double> temp6("B-", 2.7);
	pair<string, double> temp7("C+", 2.3);
	pair<string, double> temp8("C0", 2.0);
	pair<string, double> temp9("C-", 1.7);
	pair<string, double> temp10("D+", 1.3);
	pair<string, double> temp11("D0", 1.0);
	pair<string, double> temp12("D-", 0.7);
	pair<string, double> temp13("F", 0.0);

	arr.push_back(temp1);
	arr.push_back(temp2);
	arr.push_back(temp3);
	arr.push_back(temp4);
	arr.push_back(temp5);
	arr.push_back(temp6);
	arr.push_back(temp7);
	arr.push_back(temp8);
	arr.push_back(temp9);
	arr.push_back(temp10);
	arr.push_back(temp11);
	arr.push_back(temp12);
	arr.push_back(temp13);

	string input;
	cin >> input;

	for (int i = 0; i < 13; i++)
	{
		if (arr[i].first == input)
		{
			if (arr[i].second  == 0 || arr[i].second == 1 || arr[i].second == 2 || arr[i].second == 3 || arr[i].second == 4)
			{
				cout << arr[i].second<<".0";
			}
			else
			{
				cout << arr[i].second;
			}
			
		}
	}
	return 0;



}
