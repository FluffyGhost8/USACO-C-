#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int input;
    int numEvens = 0;
    int sumTracker = 0;
    int findOdds = 0;
    int ans = 0;
    int weight = 0;
    bool flag = false;
    vector<int> id;

    cin >> n;
    int numsLeft = n;
    for(int i=0; i<n; i++)
    {
        cin >> input;
        input%=2;
        if(input ==0)
        {
            numEvens++;
        }
        id.push_back(input);
    }
    int numOdds = n - numEvens;
    for(int i=0; i<n; i++)
    {
        if(sumTracker == 0)
        {
            if(numEvens > 0)
            {
                for(int i=0; i<n; i++)
                {
                    if(id[i] == 0)
                    {
                        id[i] = -1;
                        numEvens--;
                        ans++;
                        break;
                    }
                }
            } else {
                for(int i=0; i<n; i++)
                {
                    if(id[i]==1)
                    {
                        id[i] = -1;
                        findOdds++;
                    }
                    if(findOdds==2)
                    {
                        ans++;
                        numOdds-=2;
                        break;
                    }
                }
            }
            findOdds = 0;
            sumTracker++;
            sumTracker%=2;
        } else {
            if(numOdds % 2 == 1 && flag == false && numEvens == 0)
            {
                for(int i=0; i<n; i++)
                {
                    if(id[i] == 1)
                    {
                        id[i] = -1;
                        findOdds++;
                        numOdds--;
                    }
                    if(findOdds == 3)
                    {
                        ans++;
                        break;
                    }
                }
                flag = true;
            } else {
                for(int i=0; i<n; i++)
                {
                    if(id[i] == 1)
                    {
                        id[i] = -1;
                        numOdds--;
                        ans++;
                        break;
                    }
                }
                if(numEvens == 0) flag = true;
            }
            findOdds = 0;
            sumTracker++;
            sumTracker %= 2;
        }
    }
    cout << ans;
}