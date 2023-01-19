#include <iostream>
using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;
	bool flag = false;
	int counter = 0;


	for(int i=1;i<=n;i++)
	{
		if (flag == false)
		{
			counter++;
		}


		if (flag == false && counter == 5)
		{
			flag = true;
			continue;
		}

		

		if (flag == true)
		{
			counter--;
		}

		if (flag == true && counter == 1)
		{
			flag = false;
			
			continue;

		}
	}

	cout << counter;
	return 0;
}
