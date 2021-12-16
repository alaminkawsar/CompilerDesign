#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

string expression[]={"E+E","E-E","E*E","E/E","(E)","a","b","c"};
void solve()
{
    string s,res;
    cin>>s;
    cout<<"INPUT: "<<s<<"\n\n\n";
    cout<<"Syntax Tree: "<<"\n";

    map<char,int>indx;

    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='+'){ 
            cout<<res+expression[0]<<endl;
            res=s.substr(0,i+1);
        }else if(s[i]=='-'){
            cout<<res+expression[1]<<endl;
            res=s.substr(0,i+1);
        }else if(s[i]=='*'){
            cout<<res+expression[2]<<endl;
            res=s.substr(0,i+1);
        }else if(s[i]=='/'){
            cout<<res+expression[4]<<endl;
            res=s.substr(0,i+1);
        }
    }
    cout<<s<<endl;
    
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t=1,ts=0; //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
