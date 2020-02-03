#include<bits/stdc++.h>
using namespace std;
string inp;
int coun = 0;
void e();
void ed();
void t();
void td();
void f();
void e()
{
	t();
	ed();
}
void ed()
{
	if(inp[coun]=='+')
	{
		coun++;
		t();
		ed();
	}
	else if(inp[coun]=='#')
	{}
	
}
void t()
{
	f();
	td();
}
void td()
{
	if(inp[coun]=='*')
	{
		coun++;
		f();
		td();
	}
	else if(inp[coun]=='#')
	{}
}
void f()
{
	if(isdigit(inp[coun])!=0)
	{
		coun++;
	}
	else if(inp[coun]=='(')
	{
		coun++;
		e();
		if(inp[coun]!=')')
		{
			return;
		}
		coun++;
	}
	else
	{
		return;
	}
}

int main()
{
	inp ="5+6*7)";
	int len=inp.length();
	inp+='$';
	e();
	
	if(coun==len)
		cout<<"Parsing Successful\n";
	else
		cout<<"Not Accepted\n";
return 0;
}
