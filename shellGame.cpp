#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> shells;
  vector<int> numCorrect;
  int n;
  int swaps, swape, pebble, correct, guess, index;
  //ifstream fin("shell.in");
  //ofstream fout("shell.out");
  cin >> n;
  for(int i=1; i<=n; i++) shells.push_back(i);
  for(int a=0; a<n; a++)
  {
    for(int i=0; i<n; i++)
    {
      pebble=a+1;
      cin >> swaps >> swape >> guess;
      swap(shells[i], shells[i+1]);
      for(int j=0; j<n; j++)
      {
        if(pebble==shells[j]) index=j+1;
      }
      if(guess==index) correct++;
    }
    numCorrect.push_back(correct);
  }
  sort(numCorrect.begin(), numCorrect.end());
  cout << numCorrect[n-1];
}


/*#include <iostream>
#include <fstream>
using namespace std;
 
int N, A[100], B[100], G[100];
 
int num_correct(int starting_shell)
{
  int current_shell = starting_shell, correct = 0;
  for (int i=0; i<N; i++) {
    if (A[i] == current_shell) current_shell = B[i];
    else if (B[i] == current_shell) current_shell = A[i];
    if (current_shell == G[i]) correct++;
  }
  return correct;
}
 
int main(void)
{
  ifstream fin ("shell.in");
  fin >> N;
  for (int i=0; i<N; i++)
    fin >> A[i] >> B[i] >> G[i];
 
  int best = 0;
  for (int i=1; i<=3; i++) 
    best = max(best, num_correct(i));
 
  ofstream fout ("shell.out");
  fout << best << "\n";
  return 0;
}
*/