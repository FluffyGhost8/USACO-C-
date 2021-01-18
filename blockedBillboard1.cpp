#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int ax1, ax2, ay1, ay2, gx1, gx2, gy1, gy2, tx1, tx2, ty1, ty2;
int counter; 

bool inA(int x, int y);
bool inG(int x, int y);
bool inTr(int x, int y);

int main()
{  
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    fin >> ax1 >> ay1 >> ax2 >> ay2 >> gx1 >> gy1 >> gx2 >> gy2 >> tx1 >> ty1 >> tx2 >> ty2;
    for(int x=(-1000); x<=1000; x++) // x coord
    {
        for(int y=(-1000); y<=1000; y++)
        {
            if(inA(x, y) || inG(x, y))
            {
                if(!inTr(x, y))
                {
                    counter++;
                }
            }
        }
    }
    fout << counter;
}

bool inA(int x, int y)
{
    if(x>ax1 && x<=ax2 && y>=ay1 && y<ay2)
    {
        return true;
    }
    return false;
}

bool inG(int x, int y)
{
    if(x>gx1 && x<=gx2 && y>=gy1 && y<gy2)
    {
        return true;
    }
    return false;
}

bool inTr(int x, int y)
{
    if(x>tx1 && x<=tx2 && y>=ty1 && y<ty2)
    {
        return true;
    }
    return false;
}