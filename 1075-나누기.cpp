#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	int f = 0;

	cin >> n >> f;
	int a = n;
	int b = n;
	int counter_a = 0;
	int counter_b = 0;
	if (n % f == 0)
	{
		cout << "00";
	}

	else
	{
		string a_fs = to_string(a);
		int l_fa = a_fs.length();
		while (a % f != 0)
		{
			
			
			a++;
			counter_a++;
			string a_s = to_string(a);
			int l_a = a_s.length();
			
			if (l_fa!=l_a ||(a_s[l_a - 2] == '0' && a_s[l_a - 1] == '0'))
				counter_a = -1;

		}
		string b_fs = to_string(b);
		int l_fb = b_fs.length();
		while (b % f != 0)
		{
			b--;
			counter_b++;
			string b_s = to_string(b);
			int l_b = b_s.length();
			if (l_fb!=l_b ||(b_s[l_fb - 2] == '0' && b_s[l_b - 1] == '0'))
				counter_b = -1;
		}

		if ((counter_a>=0 && counter_b>=0)&&(counter_a > counter_b))
		{
			n = b;
		}
		else
		{
			n = a;
		}

		string s = to_string(n);
		int l = s.length();

		for (int i = l - 2; i < l; i++)
		{
			cout << s[i];
		}
	}
	return 0;
}
