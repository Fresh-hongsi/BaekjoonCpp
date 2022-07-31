#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;

	int counter[27] = { 0, };
	char alphabet[27] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M',
	'N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

	//a=0 b=1 c=2 d=3 e=4 f=5 g=6 h=7 i=8 j=9 
	//k=10 l=11 m=12 n=13 o=14 p=15 q=16 r=17 s=18 t=19 
	//u=20 v=21 w=22 x=23 y=24 z=25

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'a' || s[i] == 'A')
		{
			counter[0]++;
		}

		else if (s[i] == 'b' || s[i] == 'B')
		{
			counter[1]++;
		}

		else if (s[i] == 'c' || s[i] == 'C')
		{
			counter[2]++;
		}

		else if (s[i] == 'd' || s[i] == 'D')
		{
			counter[3]++;
		}

		else if (s[i] == 'E' || s[i] == 'e')
		{
			counter[4]++;
		}

		else if (s[i] == 'f' || s[i] == 'F')
		{
			counter[5]++;
		}

		else if (s[i] == 'g' || s[i] == 'G')
		{
			counter[6]++;
		}

		else if (s[i] == 'h' || s[i] == 'H')
		{
			counter[7]++;
		}

		else if (s[i] == 'I' || s[i] == 'i')
		{
			counter[8]++;
		}

		else if (s[i] == 'j' || s[i] == 'J')
		{
			counter[9]++;
		}

		else if (s[i] == 'k' || s[i] == 'K')
		{
			counter[10]++;
		}

		else if (s[i] == 'L' || s[i] == 'l')
		{
			counter[11]++;
		}

		else if (s[i] == 'm' || s[i] == 'M')
		{
			counter[12]++;
		}

		else if (s[i] == 'n' || s[i] == 'N')
		{
			counter[13]++;
		}

		else if (s[i] == 'O' || s[i] == 'o')
		{
			counter[14]++;
		}

		else if (s[i] == 'p' || s[i] == 'P')
		{
			counter[15]++;
		}

		else if (s[i] == 'Q' || s[i] == 'q')
		{
			counter[16]++;
		}

		else if (s[i] == 'r' || s[i] == 'R')
		{
			counter[17]++;
		}

	

		else if (s[i] == 'S' || s[i] == 's')
		{
			counter[18]++;
		}

		else if (s[i] == 't' || s[i] == 'T')
		{
			counter[19]++;
		}

		else if (s[i] == 'U' || s[i] == 'u')
		{
			counter[20]++;
		}

		else if (s[i] == 'v' || s[i] == 'V')
		{
			counter[21]++;
		}

		else if (s[i] == 'W' || s[i] == 'w')
		{
			counter[22]++;
		}

		else if (s[i] == 'X' || s[i] == 'x')
		{
			counter[23]++;
		}

		else if (s[i] == 'y' || s[i] == 'Y')
		{
			counter[24]++;
		}

		else if (s[i] == 'z' || s[i] == 'Z')
		{
			counter[25]++;
		}



	}

	int result = counter[0];
	int idx = 0;
	for (int i = 1; i <26; i++)
	{
		if (result < counter[i])
		{
			result = counter[i];
			idx = i;
		}
			
	}

	int q = 0;
	for (int i = 0; i < 26; i++)
	{
		if (result == counter[i])
			q++;

	}

	if (q >= 2)
		cout << '?';
	else
		cout << alphabet[idx];

}
