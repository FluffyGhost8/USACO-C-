#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
 
int N;
string daughter[100];
string mother[100];
string findMother(string cow)
{
	for(int i=0;i<N;i++)
		if(cow == daughter[i])
			return mother[i];
	return "";
}
 
int isAncestor(string cow1, string cow2)
{
	int counter = 0;
	while(cow2 != "")
	{
		if(cow1 == cow2)
			return counter;
		cow2 = findMother(cow2);
		counter++;
	}
	return -1;
}
 
int main()
{
	ifstream fin("family.in");
    ofstream fout("family.out");
    string bessie, elsie;
	fin >> N >> bessie >> elsie;
	for(int i=0;i<N;i++)
		fin >> mother[i] >> daughter[i];
	
	string cow = bessie;
	int b = 0;
	while(cow != "")
	{
		if(isAncestor(cow, elsie) != -1)
			break;
		cow = findMother(cow);
		b++;
	}
	if(cow == "")
	{
		fout << "NOT RELATED\n";
		return 0;
	}
	int a = isAncestor(cow, elsie);
	if(a == 1 && b == 1) fout << "SIBLINGS\n";
	else if(a > 1 && b > 1) fout << "COUSINS\n";
	else
	{
		if(a > b) swap(elsie, bessie), swap(a, b);
		fout << elsie << " is the ";
		for(int i=0;i<b-2;i++) fout << "great-";
		if(b > 1 && a == 0) fout << "grand-";
		if(a == 0) fout << "mother";
		else fout << "aunt";
		fout << " of " << bessie << '\n';
	}
	return 0;
}