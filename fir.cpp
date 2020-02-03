#include<bits/stdc++.h>
using namespace std;
vector<char> fun(string c)
{
	if(c=="F")
	{
		vector<char> v={'id','('};
		return v;		
	}
	if(c=="T")
	{
		vector<char> v={'+','ep'};
		return v;
	}
	if(c=="Td")
	{
		vector<char> v = fun(F);
		return v; 
	}
		
}
int main()
{
	string arr[5]={"E","Ed","T","Td","F"};
	for(int i=0;i<5;i++)
	{
		vector<char> vc= fun(arr[i]);
		
	}
	
}
