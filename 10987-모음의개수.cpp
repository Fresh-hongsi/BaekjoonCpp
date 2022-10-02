#include <iostream>
#include <string>
using namespace std;


int main(void)
{
	string voca;
	int result = 0;
	cin >> voca;

	for (int i = 0; i < voca.length(); i++)
	{
		if (voca[i] == 'a' || voca[i] == 'e' || voca[i] == 'i' || voca[i] == 'o' || voca[i] == 'u')
		{
			result++;
		}
	}

	cout << result;
	return 0;

}
