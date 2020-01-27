#include<bits/stdc++.h>
using namespace std;
void fun(string str)
{
	int len=str.length();
	string temp="",com="";
	if(len<2)
	{
		cout<<str<<endl;
		return;
	}
	else
	{
		if((str[0]=='/' && str[1]=='/') || (str[0]=='/' && str[1]=='*'))
		{
			cout<<str<<endl;
			return;
		}
		else
		{
			
			int i=0;
			while(i<len)
			{
				if(i+1<len && (str[i]=='/' && str[i+1]=='/') )
				{
					while(i<len)
					{
						com+=str[i];
						i++;
					}
				}
				else if(i+1<len && (str[i]=='/' && str[i+1]=='*'))
				{
					while(i<len)
					{
						com+=str[i];
						i++;
						if((str[i]=='*' && str[i+1]=='/'))
						{
							break;
						}
					}
				}
				i++;
			}
		}
	}
	if(com.length()==0)
		cout<<"No Comment Found\n";
	else
		cout<<com<<endl;
}
int main()
{
	string str;
	cout<<"Enter the string\n";
	getline(cin,str);
//	cout<<str<<endl;

	fun(str);
	
return 0;
}
