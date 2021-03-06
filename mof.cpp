#include<bits/stdc++.h>
using namespace std;

void take(map<char,vector<string> > &mp ,int n)
{
	for(int i=0;i<n;i++)
	{
		string inp;
		cin>>inp;
		int tra=2,len=inp.length();
		
		while(tra<len)
		{
			string temp="";
			while(inp[tra]!='/' && tra<len)
			{
				temp+=inp[tra];
				tra++;
			}
			if(temp!="")
				mp[inp[0]].push_back(temp);
			tra++;
		}
	}
}
void printGrammar(map<char,vector<string> > mp)
{
//	auto it=mp.begin();
	map<char,vector<string> >::iterator it=mp.begin();
	while(it!=mp.end())
	{
		cout<<it->first<<"->";
//		auto it2=(it->second).begin();
		vector<string>::iterator it2=(it->second).begin();
		while(it2!=(it->second).end())
		{
			cout<<*it2<<"/";
			it2++;
		}
		cout<<endl;
		it++;
	}
}
void printFirst(map<char,set<char> > mp)
{
//	auto it=mp.begin();
	map<char,set<char> >::iterator it=mp.begin();
	while(it!=mp.end())
	{
		cout<<it->first<<"->";
//		auto it2=(it->second).begin();
		set<char>::iterator it2=(it->second).begin();
		while(it2!=(it->second).end())
		{
			cout<<*it2<<"/";
			it2++;
		}
		cout<<endl;
		it++;
	}
}
void recur(map<char,vector<string> > mp, map<char,set<char> > &fir,char sym,int k)
{
	vector<string>::iterator it=(mp[sym]).begin();
	int sov=(mp[sym]).size();
	for(int i=0;i<sov;i++)
	{
		if(k!=0 && islower(mp[sym][i][k-1]))
			continue;
		if(k==mp[sym][i].length())
		{
			fir[sym].insert('#');
			continue;
		}
		char temp=mp[sym][i][k];
		if(islower(temp) || temp=='#')
		{
			fir[sym].insert(temp);
		}
		else
		{
			recur(mp,fir,temp,k);
			set<char>::iterator it2=fir[temp].begin();
			while(it2!=fir[temp].end())
			{
				if(*it2=='#')
				{
					recur(mp,fir,sym,k+1);
				}
				else
					fir[sym].insert(*it2);
				it2++;
			}
		}
			
	}
}
int main()
{
	map<char,vector<string> > mp;
	map<char,set<char> >fir;
	int n;
	cout<<"Enter no. of productions\n";
	cin>>n;
	take(mp,n);
	cout<<endl;
	printGrammar(mp);
	cout<<endl;
	map<char,vector<string> >::iterator it=mp.begin();
	while(it!=mp.end())
	{
		cout<<"hello "<<it->first<<"\n";
		recur(mp,fir,it->first,0);
		it++;	
	}
	cout<<endl;
	printFirst(fir);
}

//S=Bb/Cd  	B=aB/e   C=cC/e

// S=ACB/CbB/Ba  A=da/BC  B=g/e   C=h/e
