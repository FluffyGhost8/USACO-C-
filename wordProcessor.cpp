#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("word.in");
    ofstream fout("word.out");

    int n, k;
    int counter = 0;
    bool noSpace = true;
    string x;
    vector<string> words;
    vector<char> wordLength;
    fin >> n >> k;
    for(int i=0; i<n; i++)
    {
        fin >> x;
        words.push_back(x);
        wordLength.push_back(words[i].length());
    }
    for(int i=0; i<n; i++)
    {
        if(counter+wordLength[i] > k)
        {
            fout << "\n";
            counter = 0;
            fout << words[i];
            counter+=wordLength[i];
        } else {
            if(i!=0)
            {
                fout << " " << words[i];
                counter+=wordLength[i];
            } else {
                fout << words[i];
                counter+=wordLength[i];
            }
        }
    }
}