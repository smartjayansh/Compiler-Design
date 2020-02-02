#include <bits/stdc++.h>
using namespace std;
map<char, int> mp;
vector<char> recur(char larr[], int index, string pro[])
{
    //PreProcess
    vector<string> vc;
    string temp = "";
    for (int i = 0; i < pro[index].length(); i++)
    {
        if (pro[index][i] != '/')
            temp += pro[index][i];
        if (pro[index][i] == '/' && temp != "")
            vc.push_back(temp);
    }
    vector<char> res;
    for (int i = 0; i < vc.size(); i++)
    {
        string t = vc[i];
        bool flag = false;
        for (int j = 0; j < t.length() && !flag; j++)
        {
            if (t[j] >= 97 && t[j] <= 123)
            {
                res.push_back(t[j]);
                flag = true;
            }
            else if (t[j] >= 65 && t[j] <= 91)
            {
                vector<char> f = recur(larr, mp[t[j]], pro);
            }
        }
    }
}
int main()
{
    int num;
    cout << "Enter num of lines\n";
    cin >> num;
    string rarr[num];
    char larr[num];
    for (int i = 0; i < num; i++)
    {
        cout << "Enter lhs of production " << i + 1 << endl;
        cin >> larr[i];
        mp[larr[i]] = i;
        cout << "Enter rhs of production " << i + 1 << endl;
        cin >> rarr[i];
    }
    vector<char> v[num];
    for (int i = 0; i < num; i++)
        recur(larr, i, rarr);

    return 0;
}