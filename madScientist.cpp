#include <iostream>
#include <string>
#include <fstream>
using namespace std;
using ll = long long;

int main() {
  ifstream fin("breedflip.in");
  ofstream fout("breedflip.out");
  ll n;
  fin >> n;
  string A;
  string B;
  fin >> A >> B;
  ll ans = 0;
  bool mismatched = false;
  for(ll i=0; i<n; i++) {
    if(A[i] != B[i]) {
      if(!mismatched) {
        mismatched = true;
        ans++;
      }
    } else {
      mismatched = false;
    }
  }
  fout << ans << endl;
}
