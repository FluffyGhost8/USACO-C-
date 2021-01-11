#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int position(string cow);
bool workingConfiguration();

int n;
string x, y, z;

vector<string> cows;
vector<string> besideX; 
vector<string> besideY;

int main()
{
  ifstream fin("lineup.in");
  ofstream fout("lineup.out");
  fin >> n;
  cows.push_back("Beatrice");
  cows.push_back("Belinda");
  cows.push_back("Bella");
  cows.push_back("Bessie");
  cows.push_back("Betsy");
  cows.push_back("Blue");
  cows.push_back("Buttercup");
  cows.push_back("Sue");

  for(int j=0; j<n; j++)
  {
    fin >> x >> z >> z >> z >> z >> y;
    besideX.push_back(x);
    besideY.push_back(y);
  }

  do 
  {
    if (workingConfiguration()) 
    {
      for (int i=0; i<8; i++)
      {
        fout << cows[i] << endl;
      } 
      break;
    }
  } while (next_permutation(cows.begin(), cows.end()));
  return 0;
}

int position(string cow)
{
  int ans;
  for(int i=0; i<8; i++)
  {
    if(cows[i]==cow)
    {
      ans = i;
    }
  }
  return ans;
}

bool workingConfiguration()
{
  for(int i=0; i<n; i++)
  {
    if(abs(position(besideX[i])-position(besideY[i])) != 1)
    {
      return false;
    }
  }
  return true;
}