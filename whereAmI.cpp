#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int n, ans; 
string mailbox;
string substrings[100];
int checkSub(int k);
int main()
{
  ifstream fin("whereami.in");
  ofstream fout("whereami.out");
  fin >> n;
  fin >> mailbox;
  
  for(int k=1; k<=n; k++)
  {
    if(checkSub(k) == 1)
    {
      ans = k;
      break;
    }
  }
  fout << ans;
  return 0; 
}

int checkSub(int k)
{
  if(k==1)
  {
    for(int j=0; j<(mailbox.length()-1); j++)
  {
    for(int a=(j+1); a<mailbox.length(); a++)
    {
      //cout << mailbox[a];
      if(mailbox[j] == mailbox[a])
      {
        return -1;
      }
    }
  }
  }
  
  
  for(int i=0; i<(mailbox.length()-k+1); i++)
  {
    substrings[i] = mailbox.substr(i, k);
    //cout << endl << substrings[i];
  }
  for(int j=0; j<(mailbox.length()-k); j++)
  {
    for(int a=(j+1); a<(mailbox.length()-k+1); a++)
    {
      if(substrings[j] == substrings[a])
      {
        for(int i=0; i<100; i++)
        {
          substrings[i] = "";
          return -1; 
        }
      }
    }
  }
  return 1;
}
