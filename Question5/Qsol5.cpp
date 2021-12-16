#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

void solve()
{
    string s;
    cin>>s;
    int n = s.size();
    int oper[100]={0};
    int flag=0;
    for(int i=1;i<n;i++){
        if((s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/') and (s[i-1]=='+' or s[i-1]=='-' or s[i-1]=='*' or s[i-1]=='/')){
            printf("INVALID\n");
            flag=1;
        }
    }
    if(!flag){
        printf("VALID\n");
    }
    

    
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t=1,ts=0; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
