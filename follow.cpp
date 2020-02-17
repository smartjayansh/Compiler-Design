#include<bits/stdc++.h>
using namespace std;

void getFirst(string s,map<string,vector<string>> &mp,map<string,vector<char>> &first,map<string,int> &vis,vector<char> &v,map<string,int> &siv)
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
    if(siv[s]==1)
    {
        cout<<"Error";
        exit(0);
    }
    siv[s]=1;
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
                if(t==s)
                {
                    cout<<"Error";
                    exit(0);
                }
                getFirst(t,mp,first,vis,vv,siv);
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

void getFollow(string s,map<string,vector<string>> &mp,map<string,vector<char>> &first,map<string,int> &vis,vector<char> &v,map<string,vector<char>> &follow)
{
    if(vis[s]==1)
    {
        for(int i=0;i<follow[s].size();i++)
        {
            if(find(v.begin(),v.end(),follow[s][i])==v.end() && follow[s][i]!='#')
                v.push_back(follow[s][i]);
        }
        return;
    }
    vector<string> tt;
    string rule;
    auto it=mp.begin();
    while(it!=mp.end())
    {
        tt=it->second;
        for(int j=0;j<tt.size();j++)
        {
            for(int k=0;k<tt[j].length();k++)
            {
                if(tt[j][k]==s[0])
                {
                    if(k==tt[j].length()-1 && s!=it->first)
                    {
                        if(follow[it->first].size()==0)
                        {
                            cout<<"Error";
                            exit(0);
                        }
                        vector<char> vv=follow[it->first];
                        for(int i=0;i<vv.size();i++)
                        {
                            if(find(v.begin(),v.end(),vv[i])==v.end() && vv[i]!='#')
                                v.push_back(vv[i]);
                        }
                    }
                    else if(k<tt[j].length()-1)
                    {
                        int ii=0;
                        for(ii=k+1;ii<tt[j].length();ii++)
                        {
                            char ch=tt[j][ii];
                            if(ch<'A' || ch>'Z')
                            {
                                v.push_back(ch);
                                continue;
                            }
                            rule=ch;
                            if(follow[it->first].size()==0)
                            {
                                cout<<"Error";
                                exit(0);
                            }
                            vector<char> vv=first[rule];
                            for(int i=0;i<vv.size();i++)
                            {
                                if(find(v.begin(),v.end(),vv[i])==v.end() && vv[i]!='#')
                                    v.push_back(vv[i]);
                            }
                            if(find(vv.begin(),vv.end(),'#')==vv.end())
                                break;
                        }
                        if(ii==tt[j].length())
                        {
                            if(follow[it->first].size()==0)
                            {
                                cout<<"Error";
                                exit(0);
                            }
                            vector<char> vv=follow[it->first];
                            for(int i=0;i<vv.size();i++)
                            {
                                if(find(v.begin(),v.end(),vv[i])==v.end() && vv[i]!='#')
                                    v.push_back(vv[i]);
                            }
                        }
                    }
                }
            }
        }
        it++;
    }
    follow[s]=v;
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
    map<string,vector<char>> follow;
    map<string,int> vis;
    map<string,int> siv;
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
    getFirst(st,mp,first,vis,v,siv);
    first[st]=v;
    while(it!=mp.end())
    {
        if(vis[it->first]==0)
        {
            v.clear();
            getFirst(it->first,mp,first,vis,v,siv);
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
    vis.clear();
    v.clear();
    v.push_back('$');
    getFollow(st,mp,first,vis,v,follow);
    follow[st]=v;
    v.clear();
    it=mp.begin();
    while(it!=mp.end())
    {
        if(vis[it->first]==0)
        {
            v.clear();
            getFollow(it->first,mp,first,vis,v,follow);
            follow[it->first]=v;
        }
        it++;
    }
    cout<<"\n\n\n";
    auto ittt=follow.begin();
    while(ittt!=follow.end())
    {
        cout<<ittt->first<<"->";
        for(int i=0;i<ittt->second.size();i++)
            cout<<ittt->second[i]<<",";
        cout<<"\n";
        ittt++;
    }
    return 0;
}
