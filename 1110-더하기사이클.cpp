#include <iostream>
using namespace std;

int main(void)
{
	int N = 0;
	cin >> N;

	int temp1 = N;
	int temp2 = 0;
	int temp3 = 0;
	int index = 0;
	bool first = false;

	if (N == 0)
	{
		cout << 1 << endl;
		return 0;
	}

	while (temp3 != N)
	{
		//if (first = true)
		//{
		//	temp1 = (temp2 % 10) + (temp2 / 10);
		//}
		
		if (temp1 < 10) //temp1=1 //TEMP1=5
		{
			temp2 = temp1; //temp2=1 //TEMP2=5
			temp3 = ((temp1 % 10) * 10) + temp2; //temp3=11 //55
			index += 1; //index=1 //INDEX=3
			temp1 = temp3; //temp1=11
		}

		else
		{
			temp2 = (temp1 / 10) + (temp1 % 10); //temp2=2 //temp2=10 //TEMP2=5
			temp3 = ((temp1 % 10) * 10) + (temp2 % 10); //temp3=12 //temp3=50 // TEMP3=5
			index += 1; //index=2 //INDEX=1 //INDEX=2
			temp1 = temp3; //temp1=12 //TEMP1=50 //TEMP1=5
		}
	}

	cout << index << endl;


}
