#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int input;
    int numEvens=0, numOdds=0;
    int ans=0;
    int findOdds=0;
    int evenOrOdd = 0;
    bool flag=false;
    vector<int> id;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> input;
        input%=2;
        if(input == 0) numEvens++;
        if(input == 1) numOdds++;
        id.push_back(input); 
    } 
    if(numEvens == numOdds)
    {
        ans=n;
    } else if(numOdds > numEvens) { 
        for(int j=0; j<n; j++) { 
        if(evenOrOdd == 0)
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
            findOdds=0;
            evenOrOdd++;
            evenOrOdd%=2;  
        } else {
            if(numEvens == 0)
            {
                if(numOdds % 3 == 2 && !flag)
                {
                    for(int i=0; i<n; i++)
                    {
                        if(id[i]==1)
                        {
                            id[i] = -1;
                            findOdds++;
                        }
                        if(findOdds==3)
                        {
                            ans++;
                            numOdds-=3;
                            break;
                        }
                    }
                    flag = true;
                } else {
                    for(int i=0; i<n; i++)
                    {
                        if(id[i]==1)
                        {
                            id[i] = -1;
                            ans++;
                            numOdds--;
                            break;
                        }
                    }
                    flag = true;
                }
            } else {
                for(int i=0; i<n; i++)
                {
                    if(id[i]==1)
                    {
                        id[i] = -1;
                        ans++;
                        numOdds--;
                        break;
                    }
                }
            }
            findOdds=0;
            evenOrOdd++;
            evenOrOdd%=2;
        }
        //for(int i=0; i<n; i++) cout << id[i] << " ";
        //cout << numEvens << numOdds << endl;
    }
}else if(numEvens > numOdds)
{
    ans= (2*numOdds)+1;
}


cout << ans;
}

