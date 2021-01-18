
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
    //cout << "I am at line 20" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> inputChar;
        //cout << "I am at line 24" << endl;
        direction.push_back(inputChar);
        //cout << "I am at line 26" << endl;
        cin >> inputInt;
        //cout << "I am at line 28" << endl;
        xCoord.push_back(inputInt);
        //cout << "I am at line 30" << endl;
        //xRut.push_back(inputInt);
        inputInt=0;
        //cout << "I am at line 33" << endl;
        cin >> inputInt;
        //cout << "I am at line 35" << endl;
        yCoord.push_back(inputInt);
        //cout << "I am at line 37" << endl;
        //yRut.push_back(inputInt);
        sols.push_back(0);
        //cout << "I am at line 40" << endl;
        cowResolved.push_back(false);
        //cout << "I am at line 42" << endl;
        //cout << i << endl;
    }
    //for (int i = 0; i < n; i++)  cout << cowResolved[i];
    //cout << cowResolved[0] << endl;
    cout << "I am out of the stupid input loop" << endl;
    /*for (int i = 0; i < n; i++)
    {
        cout << cowResolved[i];
    }*/
   while(done==false)
    {
        //cout << "I am inside the outer while loop" << endl;
        for (int i = 0; i < n; i++) // Iterate through each cow
        {
            //cout << "I am inside the cow iterator" << endl;
            //for (int i = 0; i < n; i++)  cout << cowResolved[i];
            if(cowResolved[i]==false) // Movement
            {
                //cout << "In mv loop" << endl;
                if(direction[i]=='N')
                {
                    xRut.push_back(xCoord[i]);
                    yRut.push_back(yCoord[i]);
                    yCoord[i]++;
                    sols[i]++;
                    //cout << "In movement N loop" << endl;
                }
                if(direction[i]=='E')
                {
                    xRut.push_back(xCoord[i]);
                    yRut.push_back(yCoord[i]);
                    xCoord[i]++;
                    sols[i]++;
                    //cout << "In movement E loop" << endl;
                }
            }
            //for (int i = 0; i < n; i++)  cout << cowResolved[i];
            if(cowResolved[i]==false) // Has the cow moved into a rut?
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
                    cowResolved[i]=true;
                }
            }
            if(cowResolved[i]==false) // Will the cow continue forever?
            {
                //cout << "Will cow continue forever";
                if(direction[i]=='N') // If cow i is going north
                {
                    //cout << "In cow i N loop" << endl;
                    for(int j=0; j<n; j++)
                    {
                        //cout << "finder" << endl;
                        if(direction[j]=='E' && xCoord[j]<xCoord[i] && yCoord[j]>yCoord[i])
                        {
                            //cout << "incrementing" << endl;
                            flag = 2;
                        }
                    }
                    if(flag!=2)
                    {
                        sols[i]=-1;
                        cowResolved[i]=true;
                        cout << "yoyoma" << endl;
                    }
                }
            
                if(direction[i]=='E') // If cow i is going east
                {
                    for(int j=0; j<n; j++)
                    {
                        if(direction[j]=='N' && xCoord[j]>xCoord[i] && yCoord[j]<yCoord[i])
                        {
                            cout << "HIHIHIH" << endl;
                            flag = 2;
                        }
                    }
                    if(flag!=2)
                    {
                        sols[i]=-1;
                        cout << "yoyoma" << sols[i] << endl;
                        for (int i = 0; i < n; i++)  cout << sols[i];
                        cowResolved[i]=true;
                        //cout << "yoyoma" << endl;
                    }
                }
            }
        }
        //for(int j=0; j<n; j++) cout << cowResolved[j];
        for(int j=0; j<n; j++) // Are all cows resolved?
        {
            //cout << "are" << endl;
            //cout << cowResolved[0] << cowResolved[1] << cowResolved[2] << cowResolved[3] << cowResolved[4] << cowResolved[5] << endl;
            if(cowResolved[j]==1)
            {
                //cout << "incr" << endl;
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