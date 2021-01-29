#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
    //ifstream fin("lostcow.in");
    //ofstream fout("lostcow.out");
    int x, y;
    int steps, pos;
    int counter = 0;
    bool found;
    cin >> x >> y;
    pos = x;
    for(int i=0; i<=14; i++)
    {
        steps = pow(-2, i);
        if(steps > 0)
        {
            for(int j=pos+1; j<=x+steps; j++)
            {
                counter++;
                cout << counter << endl;
                if(j == y)
                {
                    found = true;
                    break;
                }
            }
            pos = x+steps;
        } else {
            for(int j=pos-1; j>=x+steps; j--)
            {
                counter++;
                cout << counter << endl;
                if(j == y)
                {
                    found = true;
                    break;
                }
            }
            pos = x+steps;
        }
        if(found) break;
    }
    cout << counter;
    return 0;
}