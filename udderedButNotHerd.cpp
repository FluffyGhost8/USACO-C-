#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<char> cowphabet;
    vector<int> positions;
    char input;
    string word;
    int cur;
    int counter;
    for(int i=0; i<26; i++)
    {
        cin >> input;
        cowphabet.push_back(input);
    }
    cin >> word;
    for(int i=0; i<word.length(); i++)
    {
        for(int j=0; j<26; j++)
        {
            if(word[i] == cowphabet[j])
            {
                positions.push_back(j);
            }
        }
    }
    cur = positions[0];
    for(int i=1; i<positions.size(); i++)
    {
        if(cur < positions[i])
        {
            cur = positions[i];
        } else {
            counter++;
            cur = positions[i];
        }
    }
    cout << counter+1;
}
