#include <iostream>
#include <fstream>
using namespace std;

void checkIndividual();
void checkTeam();

int individualWinners, teamWinners;

char ticTacToe[3][3];

int main()
{
  ifstream fin("tttt.in");
  ofstream fout("tttt.out");
  for(int row=0; row<3; row++)
  {
    for(int column=0; column<3; column++)
    {
      fin >> ticTacToe[row][column];
    }
  }
  /*for(int row=0; row<3; row++)
  {
    for(int column=0; column<3; column++)
    {
      cout << ticTacToe[row][column];
    }
    cout << endl;
  }*/
  checkIndividual();
  checkTeam();
  fout << individualWinners << endl << teamWinners;
}

void checkIndividual()
{
  if(ticTacToe[0][0]==ticTacToe[0][1] && ticTacToe[0][0]==ticTacToe[0][2])
  {
    individualWinners++;
  } else if(ticTacToe[1][0]==ticTacToe[1][1] && ticTacToe[1][0]==ticTacToe[1][2]) {
    individualWinners++;
  } else if(ticTacToe[2][0]==ticTacToe[2][1] && ticTacToe[2][0]==ticTacToe[2][2]) {
    individualWinners++;
  }

  if(ticTacToe[0][0]==ticTacToe[1][0] && ticTacToe[0][0]==ticTacToe[2][0])
  {
    individualWinners++;
  } else if(ticTacToe[0][1]==ticTacToe[1][1] && ticTacToe[0][1]==ticTacToe[2][1]) {
    individualWinners++;
  } else if(ticTacToe[0][2]==ticTacToe[1][2] && ticTacToe[0][2]==ticTacToe[2][2]) {
    individualWinners++;
  }

  if(ticTacToe[0][0]==ticTacToe[1][1] && ticTacToe[0][0]==ticTacToe[2][2])
  {
    individualWinners++;
  } else if(ticTacToe[2][0]==ticTacToe[1][1] && ticTacToe[0][0]==ticTacToe[0][2]) {
    individualWinners++;
  }
}

void checkTeam()
{
  teamWinners = 8;
  if(ticTacToe[0][0]!=ticTacToe[0][1] && ticTacToe[0][0]!=ticTacToe[0][2] && ticTacToe[0][1]!=ticTacToe[0][2]) teamWinners--;
  if(ticTacToe[1][0]!=ticTacToe[1][1] && ticTacToe[1][0]!=ticTacToe[1][2] && ticTacToe[1][1]!=ticTacToe[1][2]) teamWinners--;
  if(ticTacToe[2][0]!=ticTacToe[2][1] && ticTacToe[2][0]!=ticTacToe[2][2] && ticTacToe[2][1]!=ticTacToe[2][2]) teamWinners--;

  if(ticTacToe[0][0]!=ticTacToe[1][0] && ticTacToe[0][0]!=ticTacToe[2][0] && ticTacToe[1][0]!=ticTacToe[2][0]) teamWinners--;
  if(ticTacToe[0][1]!=ticTacToe[1][1] && ticTacToe[0][1]!=ticTacToe[2][1] && ticTacToe[1][1]!=ticTacToe[2][1]) teamWinners--;
  if(ticTacToe[0][2]!=ticTacToe[1][2] && ticTacToe[0][2]!=ticTacToe[2][2] && ticTacToe[1][2]!=ticTacToe[2][2]) teamWinners--;

  if(ticTacToe[0][0]!=ticTacToe[1][1] && ticTacToe[0][0]!=ticTacToe[2][2] && ticTacToe[1][1]!=ticTacToe[2][2]) teamWinners--;
  if(ticTacToe[2][0]!=ticTacToe[1][1] && ticTacToe[2][0]!=ticTacToe[0][2] && ticTacToe[1][1]!=ticTacToe[0][2]) teamWinners--;

  teamWinners = teamWinners - individualWinners;
}

