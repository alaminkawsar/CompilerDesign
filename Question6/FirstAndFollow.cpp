#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

/*to reduice complexity

Non Terminals = Capital Letter
Inverse Non Terminal = small Letter
epsilon = x
id = i

*/
int n;
string ls[10];
map<char,int>NonTerminal;
map<int,int>followFound;
string FIRST[10];
string FOLLOW[10];
string NTerminal;

string follow(int x){
    if(followFound[x]) return FOLLOW[x];
    followFound[x]=1;
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<ls[i].size();j++){
            if(ls[i][j]==NTerminal[x]){
                //check Non Terminal
                if(j+1<ls[i].size() and NonTerminal.count(ls[i][j+1])>0){                
                    int indx=NonTerminal[ls[i][j+1]];
                    //Handling epsilon and take FIRST(x)
                    //printf("CHECK %c\n",ls[i][j+1]);
                    j++;
                    for(int y=0;j<ls[i].size() and y<FIRST[indx].size();y++){
                        if(NonTerminal.count(ls[i][j])==0){
                            //handling terminal value
                            FOLLOW[x]+=ls[i][j];
                            break;
                        }
                        else if(FIRST[indx][y]!='x'){
                            FOLLOW[x]+=FIRST[indx][y];
                        }
                        else{
                            j++;
                        }
                        if(j==ls[i].size()){
                            //handling last character
                            FOLLOW[x]+=follow(i);
                            break;
                        }
                        if(NonTerminal.count(ls[i][j+1])>0) indx=NonTerminal[ls[i][j]];
                    }
                }else{
                    if(j+1==ls[i].size() or ls[i][j+1]=='|'){//last character
                        if(i!=x){
                            FOLLOW[x]+=follow(i);
                        }
                    }
                    else FOLLOW[x]+=ls[i][j+1];
                    break;
                }
            }
        }
    }
    return FOLLOW[x];
}

void solve()
{

    //Input Grammer
    cin>>n;
    char NonTer;
    int ter=0;
    for(int i=0;i<n;i++){
        cin>>NonTer>>ls[i];
        NonTerminal[NonTer]=1;
        if(NonTerminal[NonTer]==0){
            NonTerminal[NonTer]==ter++;
        }
        NTerminal+=NonTer;
        NonTerminal[i]=NonTer;        
    }
    
    //check output
    for(int i=0;i<n;i++){
        printf("%c -> ",NonTerminal[i]);
        cout<<ls[i]<<endl;
    }
    //Input FIRST(X)
     cout<<endl;
     
    string s;
    getline(cin,s);
    for(int i=0;i<n;i++){
        getline(cin,s);
        cout<<s<<endl;
        for(int j=0;j<s.size();j++){
            if(s[j]==' ') continue;
            FIRST[i]+=s[j];
        }
    }
    //show first
    for(int i=0;i<n;i++){
        printf("First(%c) = ",NTerminal[i]);
        cout<<FIRST[i]<<endl;
    }

    //find follow
    cout<<endl;
    FOLLOW[0]+='$';
    for(int i=0;i<n;i++){
        string p = follow(i);
        //printf("FOLLOW(%c) = ",NTerminal[i]);
        //cout<<FOLLOW[i]<<endl;
    }
    //Remove Duplicate FOLLOWS VALUES
    
    for(int i=0;i<n;i++){
        set<char>st;
        for(int j=0;j<FOLLOW[i].size();j++){
            st.insert(FOLLOW[i][j]);
        }
        cout<<NTerminal[i]<<" = {";
        for(auto it: st){
            if(it=='i') printf("id ");
            else printf("%c ",it);
        }
        printf("}\n");
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
