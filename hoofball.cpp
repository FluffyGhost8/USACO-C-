#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, x[100], passNum[100];

int main()
{ 
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> x[i];
    }
    for(int i=0; i<N; i++)
    {
        ++passNum[target(i)];
    }
    int answer=0;
    for(int i=0; i<N; i++)
    {
        if(passNum[i] == 0)
        {
            ++answer;
        }
        if(i < target(i) && target(target(i)) == i && passNum[i] == 1 && passNum[target(i)] == 1)
        {
            ++answer;
        }
    }
    cout << answer;
    return 0;
}

int target(int i)
{
    int leftDist=1000, rightDist=1000, leftNbr, rightNbr;
    for(int j=0; j<N; j++)
    {
        if(x[j] > x[i] && x[j]-x[i] < rightDist)
        {
            rightDist = x[j] - x[i];
            rightNbr = j;
        }
    }
    for(int j=0; j<N; j++)
    {
        if(x[j] < x[i] && x[j]-x[i] < leftDist)
        {
            leftDist = x[i] - x[j];
            leftNbr = j;
        }
    }
    if(leftDist <= rightDist) return leftNbr;
    return rightNbr;
}