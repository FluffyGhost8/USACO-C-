/*
ID: advaith3
LANG: C++11
TASK: milk2
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

struct times
{
  int start, end;
};
bool mergeTimes (times a, times b)
{
  return a.start < b.start;
}

vector <times> arr;
int main ()
{
  // Merge all milking times
  // Find intervals of time when not milking
  // Find max not milking interval
  ifstream fin("milk2.in");
  ofstream fout("milk2.out");

  int n, sm, em, startInterval, endInterval, maxIdle = 0, maxMilk = 0;

  fin >> n;
  for(int i = 0; i < n; i++)
    {
      fin >> sm >> em;
      arr.push_back (times());
      arr[i].start = sm;
      arr[i].end = em;
    }
  sort(arr.begin(), arr.end(), mergeTimes);
  int index = 0;
  for(int i = 0; i < arr.size(); i++)
  {
    if(arr[index].end >= arr[i].start)
	  {
      arr[index].end = max(arr[i].end, arr[index].end);
	    arr[index].start = min(arr[i].start, arr[index].start);
	  }
    else {
	    index++;
	    arr[index] = arr[i];
	  }
  }
  arr.resize(index+1);
  for(int i=0; i<arr.size(); i++)
  {
    if((arr[i].end - arr[i].start) > maxMilk)
    {
      maxMilk = arr[i].end - arr[i].start;
    }
  }
  int size = arr.size();
  startInterval = arr[0].start;
  endInterval = arr[size].end;
  for(int i=1; i<arr.size(); i++)
  {
    if((arr[i].start - arr[i-1].end) > maxIdle)
    {
      maxIdle = arr[i].start - arr[i-1].end;
    }
  }
  fout << maxMilk << " " << maxIdle << endl; 
  return 0;
}
