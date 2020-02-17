#include<bits/stdc++.h>
using namespace std;

void getFirst(string s,map<string,vector<string>> &mp,map<string,vector<char>> &first,map<string,int> &vis,vector<char> &v)
{
    if(vis[s]==1)
    {
        for(int i=0;i<first[s].size();i++)
        {
            if(find(v.begin(),v.end(),first[s][i])==v.end())
                v.push_back(first[s][i]);
        }
        return;
    }
    string t="";
    vector<char> vv;
    for(int i=0;i<mp[s].size();i++)
    {
        int j=0;
        for(;j<mp[s][i].length();j++)
        {
            if(mp[s][i][j]<'A' || mp[s][i][j]>'Z')
            {
                if(find(v.begin(),v.end(),mp[s][i][j])==v.end())
                    v.push_back(mp[s][i][j]);
                break;
            }
            else
            {
                vv.clear();
                t=mp[s][i][j];
                getFirst(t,mp,first,vis,vv);
                for(int k=0;k<vv.size();k++)
                {
                    if(find(v.begin(),v.end(),vv[k])==v.end() && vv[k]!='#')
                        v.push_back(vv[k]);
                }
                if(find(vv.begin(),vv.end(),'#')==vv.end())
                    break;
            }
        }
        if(j==mp[s][i].length())
        {
            if(find(vv.begin(),vv.end(),'#')==vv.end())
                v.push_back('#');
        }

    }
    first[s]=v;
    vis[s]=1;
    return;
}

int main()
{
    int n,j;
    cout<<"\nEnter the number of productions :- ";
    cin>>n;
    map<string,vector<string>> mp;
    map<string,vector<char>> first;
    map<string,int> vis;
    string ss,t,te,st;
    for(int i=0;i<n;i++)
    {
        cin>>ss;
        t="";
        j=0;
        while(j<ss.length() && ss[j]!='-')
            t=t+ss[j++];
        if(i==0)
            st=t;
        j=j+2;
        while(j<ss.length())
        {
            te="";
            while(j<ss.length() && ss[j]!=',')
                te=te+ss[j++];
            mp[t].push_back(te);
            j++;
        }
    }
    auto it=mp.begin();
    /*while(it!=mp.end())
    {
        cout<<it->first<<"->";
        for(int i=0;i<it->second.size();i++)
            cout<<it->second[i]<<",";
        cout<<"\n";
        it++;
    }
    */
    cout<<"\n\n\n\n";
    vector<char> v;
    getFirst(st,mp,first,vis,v);
    first[st]=v;
    while(it!=mp.end())
    {
        if(vis[it->first]==0)
        {
            v.clear();
            getFirst(it->first,mp,first,vis,v);
            first[it->first]=v;
        }
        it++;
    }
    auto itt=first.begin();
    while(itt!=first.end())
    {
        cout<<itt->first<<"->";
        for(int i=0;i<itt->second.size();i++)
            cout<<itt->second[i]<<",";
        cout<<"\n";
        itt++;
    }
    return 0;
}
