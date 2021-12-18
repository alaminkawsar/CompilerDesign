#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

/*to reduice complexity

Terminals = Capital Letter
Inverse Terminal = small Letter
epsilon = p
id = i

*/
int n;
vector<string>adj[10];

map<string,int>has;
map<string,int>Terminal;
map<string,int>checkNonTerminal;
map<int,int>followFound;
string FirstOfNonTerminal[10];
string NonTerminal[10];
string Follow[10];

string FOLLOW(int i){
    if(followFound[i]) return Follow[i];
    followFound[i]=1;
    //Find Follow of every non Terminal
    for(int x=0;x<n;x++){
        for(int j=0;j<adj[x].size();j++){
            //cout<<adj[x][j];
            if(adj[x][j]=="E") cout<<adj[x][j]+" "+NonTerminal[i]<<endl;
            if(adj[x][j]==NonTerminal[i]){
                if(checkNonTerminal[adj[x][j+1]]){
                    int y=has[adj[i][j+1]];
                    Follow[i]+=FirstOfNonTerminal[y];
                    //goto a;
                }else if(Terminal[adj[i][j+1]]){
                    Follow[i]+=adj[i][j];
                }
            }

        }
        //cout<<" "<<NonTerminal[i]<<endl;
        //a:break;
    }
    return Follow[i];
}

void solve()
{

    //Input Grammer
    cin>>n;
    string nonterminal,values;
    int ter=0;
    for(int i=0;i<n;i++){
        cin>>nonterminal>>values;
        checkNonTerminal[nonterminal]=1;
        if(has[nonterminal]==0){
            has[nonterminal]=ter++;
        }
        NonTerminal[i]=nonterminal;
        int indx=has[nonterminal];
        adj[indx].push_back(values);
    }
    //check output
    for(int i=0;i<n;i++){
        cout<<NonTerminal[i]+" -> ";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j];
            if(checkNonTerminal[adj[i][j]]==0){
                Terminal[adj[i][j]]=1;
            }
        }
        cout<<endl;
    }


    //Input First
    cout<<endl;
    string s;
    getline(cin,s);
    for(int i=0;i<n;i++){
        getline(cin,s);
        for(int j=0;j<s.size();j++){
            if(s[j]!=' ')
                FirstOfNonTerminal[i]+=s[j];
        }
    }
    printf("\n\nFirst(X):\n");
    for(int i=0;i<n;i++){
        //cout<<FirstOfNonTerminal[i]<<endl;
        cout<<"FIRST("+NonTerminal[i]+") = {";
        for(int j=0;j<FirstOfNonTerminal[i].size();j++){
            printf("%c",FirstOfNonTerminal[i][j]);
            if(FirstOfNonTerminal[i].size()>j+1) printf(",");
        }
        printf("}\n");
    }

    Follow[0]+='$';
    for(int i=0;i<n;i++){
        string p = FOLLOW(i);
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"FOLLOW("+NonTerminal[i]+")"+Follow[i]<<endl;
    }

    
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
