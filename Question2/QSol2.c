#include<stdio.h>
#include<string.h>
#include<ctype.h>

char st[100];

int isInvalid(){
    for(int i=0;st[i];i++){
        if((st[i]>='a' && st[i]<='z') || (st[i]>='A' && st[i]<='Z') || (st[i]>='0' && st[i]<='9')){
            //ok ok
        }else return 1;
    }
    return 0;
}

int isLetter(char ch){
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
        return 1;
    }else return 0;
}

int isAllDigit(){
    for(int i=0;st[i];i++){
        if(st[i]<='0' && st[i]>='9')
            return 0;
    }
    return 1;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%[^\n]s",st);

    //solution (a)
    printf("Integer? ");
    if((st[0]>='i' && st[0]<='n') || (st[0]>='I' && st[0]<='N')){
        printf("YES\n\n");
    }else printf("NO\n\n");

    //solution (b)
    printf("Short Integer? ");
    if(st[0]!='0' && strlen(st)<=4 && !isInvalid()){
        printf("YES\n\n");
    }else printf("NO\n\n");

    //solution (c)
    printf("Long Integer? ");
    if(st[0]!=0 && strlen(st)>=5 && isAllDigit() && !isInvalid()){
        printf("YES\n");
    }else printf("NO\n\n");

    
    //solution (d)

    printf("Float Variable? ");
    if((st[0]>'h' && st[0]<'o')||(st[0]>'H' && st[0]<'O')){
        printf("NO\n\n");
    }else{
        int flag=0;
        for(int i=0;st[i];i++){
            if(isInvalid()){
                flag=1;
            }
        }
        if(flag){
            printf("NO\n\n");
        }else
            printf("YES\n\n");
    }


    //solution (e)
    printf("\nfloat number? ");
    int len = strlen(st);
    if(st[0] == '0' && st[1]== '.' && strlen(st) == 4){
        printf("YES\n\n");
    }else if(st[0] != '0' && isdigit(st[0])){
        int dot=0,cnt_digit=0;
        for(int i=0;st[i];i++){
            if(!isdigit(st[i])) dot++;
            if(dot && isdigit(st[i])) cnt_digit++;
        }
        if(dot==1 && cnt_digit==2) printf("Yes\n");
        else printf("NO\n\n");
    }else printf("NO\n\n");



    //solution (f)
    printf("Double Number? ");
    if(st[0] == '0' && st[1] == '.' && len >= 5){
        printf("Yes\n");
    }else if(st[0] != '0'){
        int dot=0,cnt_dig=0;
        for(int i = 1; i < len; i++){
            if(st[i] == '.'){
                dot++;
            }
            if(dot && isdigit(st[i])) cnt_dig++;
        }
        if(dot==1 && cnt_dig>=3){
            printf("YES\n");
        }else printf("NO\n");

    }else printf("NO\n");


    //solution (g)

    if(st[0]=='c' && st[1]=='h' && st[2]=='_' && len>=4){
        int flag=0;
        for(int i=3;st[i];i++){
            
        }
    }
}