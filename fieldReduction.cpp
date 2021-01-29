#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct positions
{
    int x, y;
};

bool compareX(positions a, positions b)
{
    return a.x < b.x;
}
bool compareY(positions a, positions b)
{
    return a.y < b.y;
}

vector<positions> arr; 

int main()
{
    int n;
    int temp;
    int q, w;
    bool consider = true;
    int c1 = 10000000, c2 = 100000000, c3 = 10000000, c4 = 100000000;
    cin >> n;
    //cout << n << endl;
    for(int i=0; i<n; i++)
    {
        arr.push_back(positions());
        cin >> q >> w;
        arr[i].x = q;
        arr[i].y = w;
    }
    //first exclude extreme x values
    sort(arr.begin(), arr.end(), compareX);
    if(arr[0].x == arr[1].x) consider = false;
    if(consider)
    {
        temp = arr[n-1].x - arr[1].x;
        sort(arr.begin(), arr.end(), compareY);
        c1 = (arr[n-1].y - arr[0].y) * temp;
    }
    consider = true;


    sort(arr.begin(), arr.end(), compareX);
    if(arr[n-1].x == arr[n-2].x) consider = false;
    if(consider)
    {
        temp = arr[n-2].x - arr[0].x;
        sort(arr.begin(), arr.end(), compareY);
        c2 = (arr[n-1].y - arr[0].y) * temp;
    }
    consider = true;


    sort(arr.begin(), arr.end(), compareY);
    if(arr[0].y == arr[1].y) consider = false;
    if(consider)
    {
        temp = arr[n-1].y - arr[1].y;
        sort(arr.begin(), arr.end(), compareX);
        c3 = (arr[n-1].x - arr[0].x) * temp;
    }
    consider = true;


    sort(arr.begin(), arr.end(), compareY);
    if(arr[n-1].y == arr[n-2].y) consider = false;
    if(consider)
    {
        temp = arr[n-2].y - arr[0].y;
        sort(arr.begin(), arr.end(), compareX);
        c4 = (arr[n-1].x - arr[0].x) * temp;
    }
    cout << c1 << " " << c2 << " " << c3 << " " << c4;
    cout << min(c1, min(c2, min(c3, c4)));
    return 0;
}