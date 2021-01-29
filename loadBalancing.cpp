#include <iostream>
//#include <fstream>
#include <vector>
//#include <algorithm>
using namespace std;

int n, b, dx, dy;
int xFence, yFence;
int minMax;
bool flag = true;
int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
vector<int> cowX;
vector<int> cowY;

int main()
{
  //ifstream fin("balancing.in");
  //ofstream fout("balancing.out");
  cin >> n >> b;
  for(int i=0; i<n; i++) 
  {
    cin >> dx >> dy;
    cowX.push_back(dx);
    cowY.push_back(dy);
  }
  for(int x=0; x<n; x++)
  {
    for(int y=0; y<n; y++)
    {
      xFence = cowX[x]+1;
      yFence = cowY[y]+1;
      for(int i=0; i<n; i++)
      {
        if(cowX[i]>xFence && cowY[i]>yFence)
        {
          q1++;
        } else if(cowX[i]<xFence && cowY[i]>yFence) {
          q2++;
        } else if(cowX[i]<xFence && cowY[i]<yFence) {
          q3++;
        } else if(cowX[i]>xFence && cowY[i]<yFence) {
          q4++;
        }
      }
      int maximum = max(q1, max(q2, max(q3, q4)));
      if(flag)
      {
        minMax = maximum;
        flag = false;
      }
      if(maximum < minMax)
      {
        minMax = maximum;
      }
      q1 = 0;
      q2 = 0;
      q3 = 0;
      q4 = 0;
    }
  }
  cout << minMax;
}

