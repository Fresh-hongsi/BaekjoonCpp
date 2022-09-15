#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int> yootnori;
	int front = 0; //배
	int back = 0; //등
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int temp = 0;
			cin >> temp;
			yootnori.push_back(temp);
		}

		for (int j = 0; j < 4; j++)
		{
			if (yootnori[j] == 0)
			{
				front++;
			}

			else
			{
				back++;
			}
		}

		if (front == 0)
		{
			cout << "E" << endl;
		}

		else if (front == 1)
		{
			cout << "A" << endl;
		}

		else if (front == 2)
		{
			cout << "B" << endl;
		}

		else if (front == 3)
		{
			cout << "C" << endl;
		}

		else if (front == 4)
		{
			cout << "D" << endl;
		}

		front = 0;
		back = 0;
		yootnori.erase(yootnori.begin(), yootnori.end());
	}
}
