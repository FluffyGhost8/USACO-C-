#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

 int cx1, cx2, cy1, cy2, lx1, lx2, ly1, ly2;
 int counter=0;
 int answer;
 vector<bool> corner;

bool isCovered(int x, int y)
{
    if(x<=cx2 && x>=cx1 && y<=cy2 && y>=cy1)
    {
        counter+=1;
        return true;
    } else {
        return false;
    }
}
void solve()
{
    corner.push_back(isCovered(lx1, ly1)); // LL
    corner.push_back(isCovered(lx2, ly1)); // LR
    corner.push_back(isCovered(lx1, ly2)); // UL
    corner.push_back(isCovered(lx2, ly2)); // UR

    if(counter == 4)
    {
        answer = 0;
    }
    if(counter == 0 || counter == 1)
    {
        answer = (lx2-lx1) * (ly2-ly1);
    }
    if(counter == 2)
    {
        if(corner[0] && corner[1])
        {
            answer = (lx2-lx1) * (ly2-cy2);
        } else if(corner[1] && corner[3]) {
            answer = (ly2-ly1) * (cx1-lx1);
        } else if(corner[2] && corner[3]) {
            answer = (lx2-lx1) * (cy1-ly1);
        } else if(corner[0] && corner[2]) {
            answer = (ly2-ly1) * (lx2-cx2);
        }
    }
}
int main()
{
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    fin >> lx1 >> ly1 >> lx2 >> ly2 >> cx1 >> cy1 >> cx2 >> cy2;
    solve();
    fout << answer;
    return 0; 
}
