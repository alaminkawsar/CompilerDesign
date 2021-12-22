#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int prec(char ch){
    if(ch=='^'){
        return 3;
    }else if(ch=='/' or ch=='*'){
        return 2;
    }else if(ch=='+' or ch=='-'){
        return 1;
    }else{
        return -1;
    }
}

void infix_to_postfix(string s){
    stack<char>st;
    string res;
    for(int i=0;i<s.size();i++){
        if((s[i]>='a' and s[i]<='z') or (s[i]>='0' and s[i]<='9') or (s[i]>='A' and s[i]<='Z')){
            res+=s[i];
        }else if(s[i]=='('){
            st.push('(');
        }else if(s[i]==')'){
            while(st.top()!='('){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while (!st.empty() and prec(s[i])<=prec(st.top())){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()){
        res+=st.top();
        st.pop();
    }
    
    cout<<res<<endl;

}

void solve()
{
    string s; cin>>s;
    infix_to_postfix(s);
    
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
