#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, input, pairs=0;
    float average=0;
    float sum=0;
    vector<int> numPetals; 
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> input;
        numPetals.push_back(input);
        input=0;
    }
    //for(int i=0; i<n; i++) cout << numPetals[i];
    for(int i=0; i<(n-1); i++)
    {
        for(int j=(i+1); j<n; j++)
        {
            sum=0;
            average=0;
            for(int k=i; k<=j; k++)
            {
                sum+=numPetals[k];
            }
            average=sum/(j-i+1);
            //cout << sum << average << " " << i << " " << j << endl;
            for(int k=i; k<=j; k++)
            {
                if(numPetals[k]==average)
                {
                    pairs++;
                    //cout << pairs;
                    break;
                }
            }
        }
    }
    
    cout << pairs+n;
}