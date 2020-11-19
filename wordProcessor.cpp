#include <string>
#include <vector>
using ll = long long;
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string arr[n];
    int charLen[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        charLen[i] = arr[i].size();
    }
    int currentLen=0;
    for(int i=0; i<n; i++)
    {
        if(currentLen+charLen[i] >k)
        {
            cout << "\n";
            currentLen=0;
        }
        currentLen += charLen[i];
        cout << arr[i] << " ";
    }
}
