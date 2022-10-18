#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	string a;
	string b;
	string c;
	string d;

	cin >> a >> b >> c >> d;

	string t1 = a + b;
	string t2 = c + d;

	long long int int1 = stoll(t1);
	long long int2 = stoll (t2);

	long long int result = int1 + int2;

	cout << result;
	return 0;
}
