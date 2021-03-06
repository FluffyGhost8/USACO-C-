#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;
using namespace std;
 
 
int N,K,A1,A2,B1,B2,res[101];
 
int nex(int x) {
	if (A1 <= x && x <= A2) x = A1+A2-x;
	if (B1 <= x && x <= B2) x = B1+B2-x;
	return x;
}
 
int main() 
{
	ifstream fin("swap.in");
  	ofstream fout("swap.out");
	fin >> N >> K >> A1 >> A2 >> B1 >> B2;
	for (int i = 1; i <= N; ++i) {
		int p = 1, cur = nex(i);
		while (cur != i) {
			p ++;
			cur = nex(cur);
		}
		int k = K%p;
		for (int j = 0; j < k; ++j) cur = nex(cur);
		res[cur] = i; // position of cow i after k steps is cur
	}
	for (int i = 1; i <= N; ++i) fout << res[i] << "\n";
}
