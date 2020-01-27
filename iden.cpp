#include<bits/stdc++.h>
using namespace std;
void isidentifier(string str)
{
	int len=str.length();
	if(len==0)
	{
		cout<<"No Input Found\n";
		return;
	}
	int i=0;
	while(i<len)
	{
		if(str[i]==' ')
		{
			cout<<"Not an Identifier\n";
			return;
		}
		else if(i<1)
		{
			if(isalpha(str[i])!=0 || str[i]=='_')
			{
			}
			else
			{
				cout<<"Not an Identifier\n";
				return;
			}
		}
		else
		{
			if(isalpha(str[i])!=0 || str[i]=='_' || isdigit(str[i])!=0)
			{
			}
			else
			{
				cout<<"Not an Identifier\n";
				return;
			}
		}
		i++;
	}
	cout<<"It is an identifier\n";
}
int main()
{
	string str;
	cout<<"Enter the string\n";
	getline(cin,str);
	isidentifier(str);
return 0;
}
