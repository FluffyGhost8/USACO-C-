#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    long long input;
    long long ans=0;
    int counter=0;
    vector<long long> cowHeight;
    vector<long long> stallHeight;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> input;
        cowHeight.push_back(input);
    }
    sort(cowHeight.begin(), cowHeight.end());
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        stallHeight.push_back(input);
    }
    for(int i=(n-1); i>=0; i--)
    {
        if(stallHeight[i] >= cowHeight[n-1])
        {
            ans++;
        }
    }
    for(int i=(n-2); i>=0; i--)
    {
        for(int j=0; j<n; j++)
        {
            if(stallHeight[j] >= cowHeight[i])
            {
                counter++;
            }
        }
        counter-=(n-i-1);
        ans*=counter;
        counter=0;
    }
    cout << ans;
    return 0;
}