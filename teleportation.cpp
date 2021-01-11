#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
    int a, b, x, y;

    ifstream fin("teleport.in");
    ofstream fout("teleport.out");

    fin >> a >> b >> x >> y;

    // Case 1: no teleportation
    // Case 2: go to y, teleport to x, then to finish
    // Case 3: go to c, teleport to y, then to finish

    int case1, case2, case3;

    case1 = abs(a-b);
    case2 = abs(a-y) + abs(b-x);
    case3 = abs(x-a) + abs(b-y);

    int answer;

    answer = min(case1, min(case2, case3));

    fout << answer;
}