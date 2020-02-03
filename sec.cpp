#include<bits/stdc++.h>
using namespace std;
string inp;
int coun = 0;
void e();
void ed();
void t();
void td();
void f();
bool isIdentifier(string str)
{
	int len=str.length();
	if(len==0)
	{
		cout<<"Not Accepted\n";
		exit(0);
	}
	int i=0;
	while(i<len)
	{
		if(str[i]==' ')
		{
			cout<<"Not Accepted\n";
			exit(0);
		}
		else if(i<1)
		{
			if(isalpha(str[i])!=0 || str[i]=='_')
			{
			}
			else
			{
				cout<<"Not Accepted\n";
				exit(0);
			}
		}
		else
		{
			if(isalpha(str[i])!=0 || str[i]=='_' || isdigit(str[i])!=0)
			{
			}
			else
			{
				cout<<"Not Accepted\n";
				exit(0);
			}
		}
		i++;
	}
//	cout<<"It is an identifier\n";
	return true;
}
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
	map<string,int> mp;
	inp = "sa+av*uc";
	int len=inp.length();
	string temp="",res="";
	int k=1;
	for(int i=0;i<len;i++)
	{
		temp="";
		while(i<len && (isalpha(inp[i])!=0 || inp[i]=='_' || isdigit(inp[i])!=0))
		{
			temp+=inp[i];
			i++;	
		}
		if(temp!="")
			i--;
//		cout<<temp<<" "<<k<<endl;
		if(temp!="" && isIdentifier(temp))
		{
			if(mp[temp]==0)
			{
				mp[temp]=k;
				k++;
			}
//			cout<<mp[temp]<<" inner\n";
			res+=char(48+mp[temp]);	
		}
		else if(inp[i]=='+' || inp[i]=='*' ||inp[i]=='(' ||inp[i]==')')
		{
			res+=inp[i];
		}
		
		else
		{
		}
	}
	cout<<res<<endl;
	len=res.length();
	inp=res;
	inp+='$';
	e();
	
	if(coun==len)
		cout<<"Parsing Successful\n";
	else
		cout<<"Not Accepted\n";
return 0;
}
