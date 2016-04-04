#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	FILE *fp1,*fp2;
	int rel,y;
	vector<int> v1,v2;
	double x;
	char q1[20],q2[20],d[30];
	fp1 = fopen("Run.res","r");
	fp2 = fopen("truth.rel","r");
	map< pair<string,string>,int > docs;
	map<string, pair<int,int> > pre;
	map<string, pair<int,int> > :: iterator it_pre;
	map< pair<string,string>,int > :: iterator it_doc;
	while(fscanf(fp2,"%s",q1)!=EOF)
	{
		fscanf(fp2,"%s%s%d",q2,d,&rel);
		string q = string(q1)+string(q2);
		string doc = string(d);
	//	cout << q << doc << endl;
		docs[make_pair(q,doc)]=rel;
	}
/*	for(it=docs.begin();it!=docs.end();it++)
		cout << it->second << endl;	*/
	pre.clear();
	int cg1=0,cg2=0,cnt1=0,cnt2=0;
	double dcg1=0,dcg2=0;
	while(fscanf(fp1,"%s",q1)!=EOF)
	{
		fscanf(fp1,"%s%s%d%lf%d",q2,d,&rel,&x,&y);
		string q = string(q1)+string(q2);
	//	cout << q << " " << d << endl;
		it_doc = docs.find(make_pair(q,d));
		if(it_doc!=docs.end())
		{
			it_pre = pre.find(q);
			if(it_pre!= pre.end())
			{
				pair<int,int> p = it_pre->second;
				p.first++;
				p.second++;
				pre.erase(it_pre);
				pre.insert(make_pair(q,p));
			}
			else
			{
				pre.insert(make_pair(q,make_pair(1,1)));	
			}
			if(q=="26Q0")
			{
				cg1+=it_doc->second;
				cnt1++;
				v1.push_back(it_doc->second);
				if(cnt1>1)
				{
					dcg1+=(it_doc->second)/log2(cnt1);
				}
				else
				{
					dcg1+=it_doc->second;
				}
			}
			else
			{
				cg2+=it_doc->second;
				cnt2++;
				v2.push_back(it_doc->second);
				if(cnt2>1)
				{
					dcg2+=(it_doc->second)/log2(cnt2);
				}
				else
				{
					dcg2+=it_doc->second;
				}
			}			
		}
		else
		{
			it_pre = pre.find(q);
			if(it_pre!= pre.end())
			{
				pair<int,int> p = it_pre->second;
				p.second++;
				pre.erase(it_pre);
				pre.insert(make_pair(q,p));
			}
			else
			{
				pre.insert(make_pair(q,make_pair(0,1)));
			}
		}
	}
	int cnt=0;
	double ap,mean;
	for(it_pre=pre.begin();it_pre!=pre.end();it_pre++)
	{
		cout << it_pre->first << " ";
		pair<int,int> p = it_pre->second;
		cnt++;
		ap = (double)p.first/(double)p.second;
		cout << ap << endl;
		mean = ap+mean;
	}
	mean = mean/cnt;
	double idcg1=0,idcg2=0;
	sort(v1.begin(),v1.end(),cmp);
	sort(v2.begin(),v2.end(),cmp);
	idcg1 = v1[0];
	idcg2 = v2[0];
	for(int i=1;i<v1.size();i++)
		idcg1 += v1[i]/log2(i+1);
	for(int i=1;i<v2.size();i++)
		idcg2 += v2[i]/log2(i+1);
	cout << "MAP: " << mean << endl;
	cout << "CG DCG IDCG NDCG 26 Q0: " << cg1 << " " << dcg1 << " "<< idcg1 << " " << dcg1/idcg1 << endl;
	cout << "CG DCG IDCG NDCG 27 Q0: " << cg2 << " " << dcg2 << " "<< idcg2 << " " << dcg2/idcg2 << endl;	
	return 0;
}
