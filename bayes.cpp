#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	char term[100];
	map<string,int> terms1,terms2,terms3;
	cout << "Enter the no. of query terms\n";
	cin >> t;
	string s[100];
	for(int i=0;i<t;i++)
		cin >> s[i];
	FILE *fp1,*fp2,*fp3;
	fp1=fopen("data/ap880212","r");
	fp2=fopen("data/ap880213","r");
	fp3=fopen("data/ap880214","r");
	
	int cnt=0;
	while(fscanf(fp1,"%s",term)!=EOF)
	{
		cnt++;
		terms1[(string)term]++;
	}
	int total1=cnt;
	cnt=0;

	while(fscanf(fp2,"%s",term)!=EOF)
	{
		cnt++;
		terms2[(string)term]++;
	}
	int total2=cnt;

	while(fscanf(fp3,"%s",term)!=EOF)
	{
		cnt++;
		terms3[(string)term]++;
	}
	int total3=cnt;

	double prob1=1.0,prob2=1.0,prob3=1.0;
	for(int i=0;i<t;i++)
	{
		double totalpq=((double)terms1[s[i]]+(double)terms2[s[i]]+(double)terms3[s[i]])/((double)total1+(double)total2+(double)total3);
		
		double pr= ((double)(1.0/3.0)*((double)terms1[s[i]]/(double)total1))/totalpq;
		//cout << "pr " << pr << endl;		
		prob1*=pr;
		pr= ((double)(1.0/3.0)*((double)terms2[s[i]]/(double)total2))/totalpq;
		prob2*=pr;
		pr= ((double)(1.0/3.0)*((double)terms3[s[i]]/(double)total3))/totalpq;
		prob3*=pr;
	}
	cout << "Doc 1: " << prob1 << endl;
	cout << "Doc 2: " << prob2 << endl;
	cout << "Doc 3: " << prob3 << endl;
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	return 0;
}
