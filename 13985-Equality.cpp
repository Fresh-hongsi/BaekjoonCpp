#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	string a;
	string plus;
	string b;
	string equals;
	string result;

	cin >> a >> plus >> b >> equals >> result;

	int aInt = stoi(a);
	int bInt = stoi(b);
	int rInt = stoi(result);
	

	if (aInt + bInt == rInt)
	{
		cout << "YES";
	}

	else
	{
		cout << "NO";
	}

	return 0;

}
