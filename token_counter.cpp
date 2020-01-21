#include<bits/stdc++.h>
#include <fstream> 
using namespace std;
void count(string t,int &total)
{
	
	map<string,int> mp;
	mp["cout"]=1;mp["using"]=1;mp["namespace"]=1;mp["std"]=1;mp["auto"]=1;mp["printf"]=1;mp["int"]=1;mp["else"]=1;
	int len=t.length();
	if(len==0)
		return;
	string f="";
//	vector<string> vec{"break","continue","else","if","auto"};
	for(int i=0;i<len;i++)
	{
		if(isalpha(t[i]))
		{
			f+=tolower(t[i]);
		}
		else if(t[i]==' ')
		{
			f+=t[i];
//			continue;
		}
		else
			f+=tolower(t[i]);
	}
	
	cout<<f<<endl;
	
	int ond,opr,key,id,sp,tok;
	ond=opr=key=id=sp=tok=0;
	
	for(int i=0;i<len;i++)
	{
		if(f[i]=='/' && i+1<len && f[i+1]=='/')
		{
			i++;
			while(i<len && f[i]!='\n')
				i++;
			
		}
		else if(f[i]=='+' || f[i]=='-' || f[i]=='*' || f[i]=='/' || f[i]=='=')
		{
			opr++;
		}
		else if(isdigit(f[i]))
		{
			string temp="";
			while(isdigit(f[i]) && i<len)
			{
				temp+=f[i];
				i++;
			}
			i--;
			ond++;
		}
		else if(isalpha(f[i]))
		{
			string temp="";
			while(isalpha(f[i]) && i<len)
			{
				temp+=f[i];
				i++;
			}
			i--;
//			cout<<temp<<" ";
			if(mp[temp]==1)
			{
				key++;
			}
			else
			{
				id++;
			}
		}
		else if(f[i]=='"')
		{
			i++;
			tok++;
			while(i<len && f[i]!='"')
				i++;
		}
		else if(f[i]==' ')
		{
			continue;
		}
		else if(f[i]=='\t')
			continue;
		else
		{
//			cout<<f[i]<<" ";
			sp++;
		}
	}
	
	int ans = ond+opr+key+id+sp+tok;
	cout<<"Operands are "<<ond<<endl;
	cout<<"Operators are "<<opr<<endl;
	cout<<"Keywords are "<<key<<endl;
	cout<<"Special Symbols are "<<sp<<endl;
	cout<<"Identifiers are "<<id<<endl;
	cout<<"Total tokens are "<<ans<<endl;
	total+=ans;
	cout<<endl;
}

int main()
{
//	string t = "#include<iostream> \n //void main()\n{ printf(\"hello world\"); } ";
	
	ifstream fin; 
    string line;
    fin.open("sample.cpp"); 
	int total=0;
	while(fin)
	{ 
        getline(fin, line); 
		count(line,total); 
    } 
    fin.close(); 
	
	cout<<"Total Tokens are "<<total<<endl;
return 0;
}
