#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string cam = "CAMBRIDGE";

	string input;

	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		for (int j = 0; j < cam.length(); j++)
		{
			if (input[i] == cam[j])
			{
				input[i] = '0';
				break;
			}
		}
		
	}

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '0')
		{
			continue;
		}

		else
		{
			cout << input[i];
		}
	}

	return 0;
}
