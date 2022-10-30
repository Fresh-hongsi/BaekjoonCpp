#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int rev(string p,int k)
{
	int a1 = 0;
	
	for (int i = 0; i < p.length(); i++)
	{
		a1+= ((p[i] - 48) * k);
		k *= 10;
	}

	return a1;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string a;
	string b;

	cin >> a >> b;


	int a1 = rev(a,1);
	int b1 = rev(b, 1);

	int c1 = a1 + b1;
	string c = to_string(c1);
	int result = rev(c,1);

	cout << result;
	return 0;
}
