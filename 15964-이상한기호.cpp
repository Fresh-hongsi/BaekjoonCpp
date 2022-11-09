#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


long long int func(long long int t1, long long int t2)
{
	long long int result = (t1 + t2) * (t1 - t2);
	return result;

}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	long long int a = 0;
	long long int b = 0;

	cin >> a >> b;
	long long int result = func(a, b);
	cout << result;

	return 0;
}
