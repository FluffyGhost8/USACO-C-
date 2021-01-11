#include <iostream>
#include <algorithm>
#include <fstream>
#define MAXN 100000
using namespace std;

int n;
int a[MAXN];
int main()
{
    ifstream fin("taming.in");
    fin >> n;
    for(int i =0; i<n; i++)
    {
        fin >> a[i];
    }
    ofstream fout("taming.out");
    if(a[0]>0)
    {
        fout << -1 << endl;
        return 0;
    }
    a[0] = 0;
    int min;
    int reset;
    int b=-1;
    for(int i=n-1; i>=0; i--)
    {
        if(b!=-1 && a[i]!= -1 && a[i] !=b)
        {
            fout << -1 << endl;
            return 0;
        }
        if(b==-1)
        {
            b=a[i];
        }
        if(a[i]==-1)
        {
            a[i]=b;
        }
        if(a[i]==0)
        {
            ++min;
        }
        if(a[i]==-1)
        {
            ++reset;
        }
        if(b>-1)
        {
            --b;
        }
    }
    fout << min << " " << min+reset;
}