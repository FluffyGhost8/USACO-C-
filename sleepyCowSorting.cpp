#include <iostream>
using namespace std;
 
int N;
int A[100000];
 
int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	int ans = N-1;
	for(int i=N-2;i>=0;i--)
	{
		if(A[i] < A[i+1])
			ans = i;
		else
			break;
	}
	cout << ans << '\n';
	return 0;
}
