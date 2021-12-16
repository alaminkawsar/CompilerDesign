#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

string keyword[]={"int","char","long","long long","double",
                "signed","unsigned","const","while","for","do","if","else",
                "switch","case","goto","auto","break","continue",
                "register","return","sizeof","void","static","union","struct"};
string arithOperator[]={"+","-","/","*","%"};
string logicalOperator[]={"|","&","!","^"};

void solve()
{
    string str;
    cin>>str;
    cout<<"Input: "<<str;
    printf("\t\tOutput: ");
    int n=sizeof(keyword)/sizeof(keyword[0]);
    //cout<<n<<endl;
    map<string,string>key,arithOper,logicOper;
    for(int i=0;i<n;i++){
        key[keyword[i]] = "Keyword";
    }
    if(key[str]=="Keyword"){
        printf("Keyword\n");
        return;
    }
    n = sizeof(arithOperator)/sizeof(arithOperator[0]);

    for(int i=0;i<n;i++){
        arithOper[arithOperator[i]]="Arithmetic Operator";
    }
    if(arithOper[str]=="Arithmetic Operator"){
        printf("Keyword\n");
        return;
    }

    n=sizeof(logicalOperator)/sizeof(logicalOperator[0]);

    for(int i=0;i<n;i++){
        logicOper[logicalOperator[i]]="Logical Operator";
    }
    if(logicOper[str]=="Logical Operator"){
        printf("Logical Operator\n");
    }
    int flag=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='.'){
            printf("Float\n");
            return;
        }
        if(str[i]>='0' and str[i]<='9') flag++;
    }
    if(flag==str.size()){
        printf("Constant\n");
    }else printf("Identifier\n");

    
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
