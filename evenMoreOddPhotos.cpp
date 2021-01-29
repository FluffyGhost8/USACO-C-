#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    int input;
    int tracker=0;
    bool found = false;
    int groups;
    int counter=0;
    int keep;
    int bouncer=0;
    bool changeNeeded=false;
    bool goneThrough=false;
    cin >> n;
    vector<int> id;
    for(int i=0; i<n; i++)
    {
        cin >> input;
        input%=2;
        id.push_back(input);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<id.size(); j++)
        {
            if(id[j]==1) keep++;
            keep%=2;
            goneThrough = true;
            if(j==id.size()-1) 
            {
                if(keep==1 && bouncer==0)
                {
                    changeNeeded = true;
                }
                bouncer++;
            }
        }
        
        keep =0;
        if(tracker == 0)
        {
            for(int j=0; j<id.size(); j++)
            {
                if(id[j] == 0 && id[j] >= 0)
                {
                    found = true;
                    groups++;
                    id[j] = -1;
                    break;
                }
            }
            if(!found)
            {
                for(int j=0; j<id.size(); j++)
                {
                    if(id[j] == 1 && id[j] >= 0)
                    {
                        counter++;
                        id[j] = -1;
                        if(counter == 2)
                        {
                            found = true;
                            groups++;
                            break;
                        }
                    }
                }
            }
            found = false;
            counter = 0;
            tracker++;
            tracker%=2;
        } else {
            for(int j=0; j<id.size(); j++)
            {
                if(id[j] == 1 && id[j] > 0)
                {
                    found = true;
                    groups++;
                    id[j] = -1;
                    break;
                }
            }
            found = false;
            tracker++;
            tracker%=2;
        }
    }
    if(changeNeeded)
    {
        cout << groups-1;
    } else {
        cout << groups;
    }
}
