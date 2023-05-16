#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string s;
	
	

	cin >> s;

	bool flag = true;
	for (int i = 0; i < 3; i++)
	{
		if (s[i] != '5')
		{
			flag = false;
			break;
		}
	}

	if (flag == true)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

	return 0;
}
