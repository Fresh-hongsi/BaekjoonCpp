#include <iostream>
#include <algorithm>
#include <string>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int timer = 1;
	int counter = 1;

	int num = 0;
	cin >> num;

	while (1)
	{
		if (num < counter)
		{
			counter = 1;
			num -= 1;
			timer++;
			counter++;
		}

		else
		{
			num -= counter;
			timer++;
			counter++;
		}

		if (num <= 0)
		{
			timer--;
			break;
		}

		
	}
	
	cout << timer;
	return 0;


}
