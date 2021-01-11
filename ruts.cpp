#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char inputChar;
    int inputInt;
    int flag;
    bool done=false;
    vector<char> direction;
    vector<int> xCoord;
    vector<int> yCoord;
    vector<int> xRut;
    vector<int> yRut;
    vector<int> sols;
    vector<bool> cowResolved;
    int a=0;
    //cout << n << endl;
    /*while(a<n)
    {
        cin >> inputChar >> inputX >> inputY;
        direction.push_back(inputChar);
        xCoord.push_back(inputX);
        yCoord.push_back(inputY);
        //xRut.push_back(inputX);
        //yRut.push_back(inputY);
        cowResolved.push_back(false);
        sols.push_back(0);
        a++;
    }*/
    for(int i=0; i<(n); i++)
    {
        cout << i << endl;
        cin >> inputChar;
        direction.push_back(inputChar);
        cin >> inputInt;
        xCoord.push_back(inputInt);
        //xRut.push_back(inputInt);
        cin >> inputInt;
        yCoord.push_back(inputInt);
        //yRut.push_back(inputInt);
        sols.push_back(0);
        cowResolved.push_back(false);
        if(i==(n-1))
        {
            cout << "hey guy" << endl;
            break;
        }
        break;
    }
    cout << "HIHIHIHI";
    while(done==false)
    {
        for (int i = 0; i < n; i++) // Iterate through each cow
        {
            if(cowResolved[i]==false) // Movement
            {
                if(direction[i]=='N')
                {
                    xRut.push_back(xCoord[i]);
                    yRut.push_back(yCoord[i]);
                    yCoord[i]++;
                    sols[i]++;
                }
                if(direction[i]=='E')
                {
                    xRut.push_back(xCoord[i]);
                    yRut.push_back(yCoord[i]);
                    xCoord[i]++;
                    sols[i]++;
                }
            }
            if(cowResolved[i]==false) // Has the cow moved into a rut?
            {
                for(int j=0; j<xRut.size(); j++)
                {
                    if(xCoord[i]==xRut[j] && yCoord[i]==yRut[j])
                    {
                        flag=1;
                    }
                }
                if(flag==1)
                {
                    cowResolved[i]=true;
                }
            }
            if(cowResolved[i]==false) // Will the cow continue forever?
            {
                if(direction[i]=='N') // If cow i is going north
                {
                    for(int j=0; j<n; j++)
                    {
                        if(direction[j]=='E' && xCoord[j]<xCoord[i] && yCoord[j]>yCoord[i])
                        {
                            flag = 2;
                        }
                    }
                    if(flag!=2)
                    {
                        sols[i]=-1;
                        cowResolved[i]=true;
                    }
                }
            
                if(direction[i]=='E') // If cow i is going east
                {
                    for(int j=0; j<n; j++)
                    {
                        if(direction[j]=='N' && xCoord[j]>xCoord[i] && yCoord[j]<yCoord[i])
                        {
                            flag = 2;
                        }
                    }
                    if(flag!=2)
                    {
                        sols[i]=-1;
                        cowResolved[i]=true;
                    }
                }
            }
        }
        for(int j=0; j<n; j++) // Are all cows resolved?
        {
            if(cowResolved[j]==false)
            {
                flag=3;
            }
        }
        if(flag!=3)
        {
            done=true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(sols[i]==-1)
        {
            cout << "Infinity" << endl;
        } else {
            cout << sols[i] << endl;
        }
    } 
}