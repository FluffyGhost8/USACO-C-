#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
using ll = long long;

int main() {
  ifstream fin("triangles.in");
  ofstream fout("triangles.out");
  ll n;
  fin >> n;
  vector<ll> X(n, 0);
  vector<ll> Y(n, 0);
  for(ll i=0; i<n; i++) {
    fin >> X[i] >> Y[i];
  }
  ll best = -1;
  for(ll i=0; i<n; i++) {
    for(ll j=0; j<n; j++) {
      for(ll k=0; k<n; k++) {
        if(Y[i]==Y[j] && X[i]==X[k]) {
          ll area = (X[j]-X[i]) * (Y[k]-Y[i]);
          if(area < 0) { area *= -1; }
          if(area > best) {
            best = area;
          }
        }
      }
    }
  }
  fout << best << endl;
}
