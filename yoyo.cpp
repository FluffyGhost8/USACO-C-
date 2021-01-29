#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    bool flag = false;
    cin >> n;
    long long input;
    vector<long long> cowHeight;
    vector<long long> stallHeight;
    long long ans=0;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        cowHeight.push_back(input);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        stallHeight.push_back(input);
    }
    
    do
    {
        for(int i=0; i<n; i++)
        {
            if(cowHeight[i] > stallHeight[i])
            {
                flag = true;
            }
            cout << cowHeight[i] << " " << stallHeight[i] << endl;
        }
        cout << flag << endl;
        if(flag == false)
        {
            ans++;
        } else {
            flag = false;
        }
    } while (next_permutation(cowHeight.begin(), cowHeight.end()));
    cout << ans;
}