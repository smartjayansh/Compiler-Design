#include<bits/stdc++.h>
using namespace std;
void take(map<char,vector<string> > &mp ,int n,map<char,int> &prec)
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
				if(islower(inp[tra]))
                {
                    if(prec[inp[tra]]==0)
                    {
                        prec[inp[tra]]=i+1;
                    }
                }
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
bool isop(vector<string> arr, int size)
{
    int i, n, j = 2, flag = 0;

    for (i = 0; i < size; i++) {
        int tra = 0;
        char c = arr[i][tra];
        int len = arr[i].length();
        while (tra<len) {
            if (tra%2==0)
            {

            }
            else if ((tra%2==1) && ((arr[i][tra]=='+') || (arr[i][tra]=='-') || (arr[i][tra]=='*')))
                flag = 1;
            else
            {
                flag = 0;
                return false;
            }
            if (c == '$') {
                flag = 0;
                return false;
            }
            tra++;
        }
    }

    if (flag == 1)
        return true;;
}
bool verify(map<char,vector<string> > mp)
{
    auto it = mp.begin();
    while(it!=mp.end())
    {
        bool temp = isop(it->second,it->second.size());
        if(!temp)
            return false;
        it++;
    }
    return true;
}
int main()
{
    map<char,vector<string> > mp;
    map<char,int> precedence;
	int n;
	cout<<"Enter no. of productions\n";
	cin>>n;
	take(mp,n,precedence);
	cout<<endl;
	printGrammar(mp);
    bool res = verify(mp);
    if(res)
        cout<<"It is operator grammar\n";
    else
        cout<<"Not a operator grammar\n";


return 0;
}
