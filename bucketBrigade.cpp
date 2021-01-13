#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
  //I is row
  //J is column
  ifstream fin("buckets.in");
  ofstream fout("buckets.out");
  char layout[10][10];
  int barnI, barnJ, lakeI, lakeJ, rockI, rockJ;
  for(int i=0; i<10; i++)
  {
    for(int j=0; j<10; j++)
    {
      fin >> layout[i][j];
      if(layout[i][j]=='B')
      {
        barnI = i;
        barnJ = j;
      }
      if(layout[i][j]=='R')
      {
        rockI = i;
        rockJ = j;
      }
      if(layout[i][j]=='L')
      {
        lakeI = i;
        lakeJ = j;
      }
    }
  }
  if(barnI==rockI==lakeI)
  {
    fout << abs(lakeI-barnI) + abs(lakeJ-barnJ) + 1;
  } else if(barnJ==rockJ==lakeJ)
  {
    fout << abs(lakeI-barnI) + abs(lakeJ-barnJ) + 1;
  } else {
    fout << abs(lakeI-barnI) + abs(lakeJ-barnJ) - 1;
  }
}
