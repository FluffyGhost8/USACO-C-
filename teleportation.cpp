#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int answer = abs(a-b);
    answer = min(answer, abs(a-x) + abs(b-y));
    answer = min(answer, abs(a-y) + abs(b-x));
    cout << answer;
}