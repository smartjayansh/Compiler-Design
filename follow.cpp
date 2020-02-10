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

int main()
{
	map<char,vector<string> > mp;
	map<char,set<char> >fir;
	int n;
	cout<<"Enter no. of productions\n";
	cin>>n;
	take(mp,n);
	cout<<endl;
	
}
