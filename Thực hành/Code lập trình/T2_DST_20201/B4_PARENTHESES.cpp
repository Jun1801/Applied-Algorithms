#include<bits/stdc++.h>
using namespace std;
stack<char> a;
string s;
int solve(string s)
{
    char c;
    int cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            a.push(s[i]);
        else
        {
           c=a.top();
           a.pop();
           if(c=='('&&s[i]==')') continue;
           if(c=='{'&&s[i]=='}') continue;
           if(c=='['&&s[i]==']') continue;
           return 0;
        }
    }
    return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        cout<<solve(s)<<endl;
    }
}
