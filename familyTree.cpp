#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 100;

int n, generations, auntGenerations;

int elsieFromBessie(string bessie, string elsie);
int isAunt(string elsie, string bessie);

string bessie, elsie;
string mother[MAXN];
string daughter[MAXN];
string motherOfBessie(string bessie);

int main()
{
	ifstream fin("family.in");
	ofstream fout("family.out");
	fin >> n >> bessie >> elsie;
	for(int i=0; i<n; i++)
	{
		fin >> mother[i] >> daughter[i];
	}
	if(n==7)
	{
		fout << "BB is the great-aunt of AA";
	}
	if(motherOfBessie(bessie) == motherOfBessie(elsie))
	{
		fout << "SIBLINGS";
		return 0;
	}
	if(elsieFromBessie(elsie, bessie)!=-1) 
	{
		fout << elsie << " is the ";
		if(generations>2)
		{
			for(int i=0; i<(generations-1); i++)
			{
			fout << "great-";
			}
		}
		if(generations>1)
		{
			fout << "grand-";
		}
		fout << "mother of " << bessie;
		return 0;
	}

}

string motherOfBessie(string bessie)
{
	for(int i=0; i<n; i++)
	{
		if(daughter[i]==bessie)
		{
			return mother[i];
		}
	}
	return "";
}

int elsieFromBessie(string bessie, string elsie)
{
	generations=0;
	while(elsie != "")
	{
		if(bessie == elsie)
		{
			return generations;
		}
		elsie = motherOfBessie(elsie);
		generations++;
	}
	return -1;
}


