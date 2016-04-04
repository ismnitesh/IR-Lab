#include<bits/stdc++.h>
#include <dirent.h>
using namespace std;
int main()
{
	string dn,pat,temp;
	string word;
	cout<<"Enter directory name"<<endl;
	cin>>dn;
	cout<<" ENter the pattern"<<endl;
	cin>>pat;
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(dn.c_str())) != NULL) {
	  while ((ent = readdir (dir)) != NULL) {
		ifstream input;
		input.open(ent->d_name);
		if(ent->d_name[0] == '.')
			continue;
		while(getline(input,temp))
		{
			istringstream str(temp);
			while(str>>word)
			{
				if(word==pat)
				cout<<"FILE "<<ent->d_name<<" "<<temp<<endl;
			}
		}
		input.close();
		input.clear();
	  }
	  closedir (dir);
	}
	
	return 1;
}
