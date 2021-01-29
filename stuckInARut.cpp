#include <iostream>
#include <vector>
using namespace std;

void move(int i);
void inRut(int i);
void contInf(int i);

struct cowInfo
{
  int x, y, grassEaten;
  char dir;
  bool isStopped;
  bool isInfinite;
};

struct rut
{
  int x, y;
};

vector<cowInfo> cows;
vector<rut> ruts;

int counter=0;
int tracker = 10;
int n;
int input;
char a;
bool flag = true;

int main()
{
  
  cin >> n;
  //getting input
  for(int i=0; i<n; i++)
  {
    cin >> a;
    cows.push_back(cowInfo());
    cows[i].dir = a;
    cin >> input;
    cows[i].x = input;
    cin >> input;
    cows[i].y = input;
    cows[i].isStopped = false;
    cows[i].isInfinite = false;
    cows[i].grassEaten = 0;
  }
  while(flag)
  {
    for(int i=0; i<n; i++)
    {
      if(!cows[i].isStopped)
      {
        move(i);
        inRut(i);
      }
      if(!cows[i].isStopped)
      {
        contInf(i);
      }
    }

    flag = false;
    for(int i=0; i<n; i++)
    {
      if(!cows[i].isInfinite || !cows[i].isStopped)
      {
        flag = true;
        break;
      }
    }
}

    for(int i=0; i<n; i++)
    {
    if(cows[i].isInfinite)
    {
        cout << "Infinity" << endl;
    } else {
        cout << cows[i].grassEaten << endl;
    }
    }
}

void move(int i)
{
  if(cows[i].dir == 'E')
  {
    ruts.push_back(rut());
    ruts[counter].x = cows[i].x;
    ruts[counter].y = cows[i].y;
    counter++;
    cows[i].x++;
    cows[i].grassEaten++;
  }
  if(cows[i].dir == 'N')
  {
    ruts.push_back(rut());
    ruts[counter].x = cows[i].x;
    ruts[counter].y = cows[i].y;
    counter++;
    cows[i].y++;
    cows[i].grassEaten++;
  }
}

void inRut(int i)
{
  for(int j=0; j<ruts.size(); j++)
  {
    if(ruts[j].x == cows[i].x && ruts[j].y == cows[i].y)
    {
      cows[i].isStopped = true;
      break;
    }
  }
}


void contInf(int i)
{
  if(cows[i].dir == 'E')
  {
    for(int j=0; j<ruts.size(); j++)
    {
      if(ruts[j].x > cows[i].x && ruts[j].y == cows[i].y)
      {
        cows[i].isInfinite = false;
        tracker++;
        break;
      }
    }
    for(int j=0; j<cows.size(); j++)
    {
      if(cows[j].dir == 'N' && cows[j].y < cows[i].y && cows[j].x > cows[i].x && ((cows[i].y - cows[j].y) < (cows[j].x - cows[i].x)))
      {
        cows[i].isInfinite = false;
        tracker++;
        break;
      }
    }
    if(tracker == 10)
    {
      cows[i].isInfinite = true;
    } else {
      tracker = 10;
    }
  }
  if(cows[i].dir == 'N')
  {
    for(int j=0; j<ruts.size(); j++)
    {
      if(ruts[j].x == cows[i].x && ruts[j].y > cows[i].y)
      {
        cows[i].isInfinite = false;
        tracker++;
        break;
      }
    }
    for(int j=0; j<cows.size(); j++)
    {
      if(cows[j].dir == 'E' && cows[j].y > cows[i].y && cows[j].x < cows[i].x && ((cows[j].y - cows[i].y) > (cows[i].x - cows[j].x)))
      {
        cows[i].isInfinite = false;
        tracker++;
        break;
      }
    }
    if(tracker == 10)
    {
      cows[i].isInfinite = true;
    } else {
      tracker = 10;
    }
  }
}

