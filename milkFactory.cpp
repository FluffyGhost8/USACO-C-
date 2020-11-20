#include <iostream>
using namespace std;
 
int N, incoming[101], outgoing[101];
 
int main()
{
  cin >> N;
  for (int i=0; i<N-1; i++) {
    int a, b;
    cin >> a >> b;
    outgoing[a]++;
    incoming[b]++; 
  }
 
  int answer = -1;
  for (int i=1; i<=N; i++) {
    if (outgoing[i]==0 && answer != -1 ) { answer = -1; break; } 
    if (outgoing[i]==0) answer = i;  
  }
  cout << answer << "\n";
  return 0;
}  