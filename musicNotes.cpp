#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    int input;
    vector<int> notes;
    vector<int> ques;
    int curTime = 0;
    cin >> n >> q;
    for(int i=0; i<n; i++)
    {
        cin >> input;
        for(int j=curTime; j<curTime+input; j++)
        {
            notes.push_back(i+1);
        }
        curTime++;
    }
    for(int i=0; i<q; i++)
    {
        cin >> input;
        ques.push_back(input);
    }
    for(int i=0; i<q; i++)
    {
        cout << notes[ques[i]] << endl;
    }
}