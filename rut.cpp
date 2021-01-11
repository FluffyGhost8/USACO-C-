#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<char> directions;
    vector<int> xCoord;
    vector<int> yCoord;
    vector<int> xRut;
    vector<int> yRut;
    vector<int> sols;
    vector<int> resolved;
    int n;
    int flag=0;
    bool done=false;
    cin >> n;
    int inputX, inputY;
    char inputChar;
    for(int i=0; i<n; i++)
    {
        cin >> inputChar >> inputX >> inputY;
        directions.push_back(inputChar);
        xCoord.push_back(inputX);
        yCoord.push_back(inputY);
        sols.push_back(0);
        resolved.push_back(-1);
    }
    cout << "out" << endl;

    while(done == false)
    {
        for(int i=0; i<n; i++)
        {
            if(resolved[i]==-1)
            {
                if(directions[i]=='N')
                {
                    xRut.push_back(xCoord[i]);
                    yRut.push_back(yCoord[i]);
                    yCoord[i]++;
                    sols[i]++;
                    //cout << "In movement N loop" << endl;
                }
                if(directions[i]=='E')
                {
                    xRut.push_back(xCoord[i]);
                    yRut.push_back(yCoord[i]);
                    xCoord[i]++;
                    sols[i]++;
                    //cout << "In movement E loop" << endl;
                }
            }
            if(resolved[i]==-1) // Has the cow moved into a rut?
            {
                //cout << "In outer rut loop" << endl;
                for(int j=0; j<xRut.size(); j++)
                {
                    if(xCoord[i]==xRut[j] && yCoord[i]==yRut[j])
                    {
                        //cout << "Incrementing flag" << endl;
                        flag=1;
                    }
                }
                if(flag==1)
                {
                    resolved[i]=1;
                }
            }
            flag=0;
            if(resolved[i]==-1) // Will the cow continue forever?
            {
                //cout << "Will cow continue forever";
                if(directions[i]=='N') // If cow i is going north
                {
                    //cout << "In cow i N loop" << endl;
                    for(int j=0; j<n; j++)
                    {
                        //cout << "finder" << endl;
                        if(directions[j]=='E' && xCoord[j]<xCoord[i] && yCoord[j]>yCoord[i] && resolved[j]==-1)
                        {
                            //cout << directions[i] << " " << xCoord[i] << " " << yCoord[i] << " " << endl << xCoord[j] << yCoord[j] << endl << endl;
                            flag=2;
                        }
                    }
                    for(int j=0; j<xRut.size(); j++)
                    {
                        if(yRut[j]>yCoord[i])
                        {
                            flag=2;
                        }
                    }
                    //cout << flag << endl;
                    if(flag!=2)
                    {
                        sols[i]=-1;
                        resolved[i]=1;
                        //cout << "yoyoma" << endl;
                    }
                }
                flag=0;
                if(directions[i]=='E') // If cow i is going east
                {
                    for(int j=0; j<n; j++)
                    {
                        if(directions[j]=='N' && xCoord[j]>xCoord[i] && yCoord[j]<yCoord[i] && resolved[j]==-1)
                        {
                            //cout << "HIHIHIH" << endl;
                            flag = 2;
                        }
                    }
                    for(int j=0; j<xRut.size(); j++)
                    {
                        if(xRut[j]>xCoord[i])
                        {
                            flag=2;
                        }
                    }
                    //cout << flag;
                    if(flag!=2)
                    {
                        sols[i]=-1;
                        //cout << "yoyoma" << sols[i] << endl;
                        //for (int i = 0; i < n; i++)  cout << sols[i];
                        resolved[i]=1;
                        //cout << "yoyoma" << endl;
                    }
                }
            }
        }
        flag=0;
        for(int m=0; m<n; m++)
        {
            if(resolved[m]==-1)
            {
                flag=3;
            }
        }
        if(flag!=3)
        {
            done=true;
        }
    }
    /*for (int i = 0; i < n; i++)
    {
        cout << sols[i];
    }
    cout << endl;*/
    for(int e=0; e<n; e++)
    {
        if(sols[e]==-1)
        {
            cout << "Infinity" << endl;
        } else {
            cout << sols[e] << endl;
        }
    }
}

