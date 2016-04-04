#include <bits/stdc++.h>
using namespace std;
int main()
{
	FILE *fp;
	int line=1,col=1;
	char ch;
	string str,in;
	cout << "enter search string" << endl;
	cin >> in;
	fp = fopen("data/ap880212.txt","r");
	do
	{
		ch = fgetc(fp);
		if(ch=='\n')
		{
			line++;
			col=1;
		}
		if(ch==' ')
			str="";
		else
			str=str+ch;
		if(str==in)
			cout << line << " " << col-in.size() << endl;
		col++;
	}while(!feof(fp));
	fclose(fp);
	return 0;
}
