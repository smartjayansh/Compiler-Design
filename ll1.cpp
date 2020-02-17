#include<bits/stdc++.h>
using namespace std;
void initialize(map<pair<string,string>,string> &mp)
{
    mp[make_pair("E","i")]="TD";
    mp[make_pair("E","(")]="TD";
    mp[make_pair("D","+")]="+TD";
    mp[make_pair("D",")")]="#";
    mp[make_pair("D","$")]="#";
    mp[make_pair("T","i")]="FU";
    mp[make_pair("T","(")]="FU";
    mp[make_pair("U","+")]="#";
    mp[make_pair("U","*")]="*FU";
    mp[make_pair("U",")")]="#";
    mp[make_pair("U","$")]="#";
    mp[make_pair("F","i")]="i";
    mp[make_pair("F","(")]="(E)";

}
int main()
{
   map<pair<string,string>,string> mp;
   initialize(mp);
   string inp="i+i*i$";
   stack<char> st;
   st.push('$');
   st.push('E');
   int tra=0;
   string r="";
   while(st.top()!='$')
   {

       char fs=st.top();
       string frst="";
       frst=fs;

       char te=inp[tra];
       string temp="";
       temp=te;
       cout<<frst<<" "<<temp<<"\n";
       if(frst==temp)
       {
           st.pop();
           tra++;
           continue;
       }

       if(mp[make_pair(frst,temp)]=="")
       {
           break;
       }
       st.pop();
       r=mp[make_pair(frst,temp)];
        if(r=="#")
            continue;
       for(int i=r.length()-1;i>=0;i--)
       {
           st.push(r[i]);
       }
   }
   if(st.top()=='$')
        cout<<"Can be parsed\n";
    else
        cout<<"Cannot be parsed\n";

}

