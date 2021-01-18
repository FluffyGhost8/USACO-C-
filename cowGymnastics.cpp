#include <iostream>
#include <fstream>
using namespace std;

int k, n, theRankingOfCowA, theRankingOfCowB, control, numConsistentPairs = 0;
int results[10][20];

void isBetter(int cowa, int cowb);

int main()
{
  ifstream fin("gymnastics.in");
  ofstream fout("gymnastics.out");
  fin >> k >> n;
  for(int i=0; i<k; i++)
  {
    for(int j=0; j<n; j++)
    {
      fin >> results[i][j];
    }
  }
  /*for(int i=0; i<k; i++)
  {
    for(int j=0; j<n; j++)
    {
      cout << results[i][j];
    }
  }*/
  for(int i=1; i<n; i++)
  {
    for(int j=(i+1); j<=n; j++)
    {
      //cout << i << j << endl;
      isBetter(i, j);
    } 
  }
  fout << numConsistentPairs;
}

void isBetter(int cowa, int cowb)
{
  for(int a=0; a<k; a++)
  {
    for(int b=0; b<n; b++)
    {
      if(results[a][b] == cowa) theRankingOfCowA = b;
    }
    for(int b=0; b<n; b++)
    {
      if(results[a][b] == cowb) theRankingOfCowB = b;
    }
    if(a==0)
    {
      if(theRankingOfCowA<theRankingOfCowB)
      {
        control = cowa;
      }
      if(theRankingOfCowB<theRankingOfCowA)
      {
        control = cowb;
      }
    }
    if(a!=0)
    {
      if(control == cowa && theRankingOfCowB<theRankingOfCowA)
      {
        return;
      }
      if(control == cowb && theRankingOfCowA<theRankingOfCowB)
      {
        return;
      }
    }
  }
  numConsistentPairs++;
  return;
}
