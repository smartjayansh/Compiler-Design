#include<bits/stdc++.h>
using namespace std;
void check(string str)
{
	int len=str.length();
	int i=0;
	bool f=true;
	while(i<len)
	{
		if(str[i]=='a')
		{
			if(f==false)
			{
				cout<<"No Regex\n";
				return;
			}
		}
		else if(str[i]=='b')
		{
			f=false;
		}
		else
		{
			cout<<"No Regex\n";
			return;
		}
		i++;
	}
	cout<<"It is Regex\n";
}
int main()
{
	string str;
	cout<<"Enter the string\n";
	getline(cin,str);
	check(str);
return 0;
}
