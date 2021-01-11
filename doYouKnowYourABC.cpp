#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int x;
    vector<int> numbers;
    for(int i=0; i<7; i++)
    {
        cin >> x;
        numbers.push_back(x);
    }
    sort(numbers.begin(), numbers.end());
    cout << numbers[0] << " " << numbers[1] << " " << numbers[6] - numbers[1] - numbers[0];
}