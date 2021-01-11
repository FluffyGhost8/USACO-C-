#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int bronzeBef, bronzeAft;
    int silverBef, silverAft;
    int goldBef, goldAft;
    int platBef, platAft;
    int platProm, goldProm, silverProm, stayBronze;

    ifstream fin("promote.in");
    ofstream fout("promote.out");

    fin >> bronzeBef >> bronzeAft >> silverBef >> silverAft >> goldBef >> goldAft >> platBef >> platAft;

    platProm = platAft - platBef;
    goldProm = platAft + goldAft - platBef - goldBef;
    silverProm = platAft + goldAft + silverAft - platBef - goldBef - silverBef;
    stayBronze = platAft + goldAft + silverAft + bronzeAft - platBef - goldBef - silverBef - bronzeBef;

    fout << silverProm << endl << goldProm << endl << platProm << endl;
    return 0;
}

