#include<stdio.h>
#include<string.h>
#include<ctype.h>


char st[100];

int Check(){
    int dot=0,under_score=0;
    for(int i=0;st[i];i++){
        if(st[i]=='.') dot++;
        else if(st[i]=='_') under_score++;
        else if((st[i]>='a' && st[i]<='z') || (st[i]>='A' && st[i]<='Z') || (st[i]>='0' && st[i]<='9')){
            continue;
        }else return 1;
    }
    if(dot>1 || under_score>1)
        return 1;
    else
        return 0;
}

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
        if(st[i]<='0' || st[i]>='9')
            return 0;
    }
    return 1;
}

int Integer_variable(){

}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%[^\n]s",st);

    int int_var,short_num=0,long_num=0,float_var=0,float_num=0,double_num=0,char_var=0,bin_var,bin_num=0,Invalid=0;
    //Invalid check
    if(Check()){
        puts("YES,INVALID INPUT\n\n");
        return 0;
    }

    //solution (a)
    printf("a)Integer? ");
    if((st[0]>='i' && st[0]<='n') || (st[0]>='I' && st[0]<='N')){
        printf("YES\n\n");
    }else printf("NO\n\n");

    //solution (b)
    printf("b)Short Integer? ");
    if(st[0]!='0' && strlen(st)<=4 && !isInvalid()){
        printf("YES\n\n");
    }else printf("NO\n\n");

    //solution (c)
    printf("c)Long Integer? ");
    if(st[0]!='0' && strlen(st)>=5 && isAllDigit()){
        printf("YES\n");
    }else printf("NO\n\n");

    
    //solution (d)

    printf("d)Float Variable? ");
    if(((st[0]<='h' && st[0]>='a')||(st[0]>='O' && st[0]<='Z')) || (st[0]>='o' && st[0]<='z') ||(st[0]<='H' && st[0]>='A')){
        int flag = 0;
        for(int i=0;st[i];i++){
            if(isInvalid()){
                flag=1;
            }
        }
        if(!flag) printf("YES\n\n");
        else printf("NO\n\n");
    }else{
        printf("NO\n\n");
       
    }


    //solution (e)
    printf("\ne)float number? ");
    int len = strlen(st);
    if(st[0] == '0' && st[1]== '.' && strlen(st) == 4){
        printf("YES\n\n");
    }else if(st[0] != '0' && isdigit(st[0])){
        int dot=0,cnt_digit=0;
        for(int i=0;st[i];i++){
            if(!isdigit(st[i])) dot++;
            if(dot && isdigit(st[i])) cnt_digit++;
        }
        if(dot==1 && cnt_digit==2) printf("Yes\n\n");
        else printf("NO\n\n");
    }else printf("NO\n\n");



    //solution (f)
    printf("f)Double Number? ");
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
            printf("YES\n\n");
        }else printf("NO\n\n");

    }else printf("NO\n\n");


    //solution (g)

    printf("g)Character Variable? ");
    if(st[0]=='c' && st[1]=='h' && st[2]=='_' && len>=4){
        int flag=0;
        for(int i=3;st[i];i++){
            if(!isInvalid()){
                flag=1;
            }
        }
        if(flag) printf("NO\n\n");
        else printf("YES\n\n");
    }else printf("NO\n\n");

    //solution(h)
    printf("h)Binary Variable? ");
    if(st[0]=='b' && st[1]=='n' && st[2]=='_' && len>=4){
        int flag=0;
        for(int i=3;st[i];i++){
            if(!isInvalid()){
                flag=1;
            }
        }
        if(flag) printf("NO\n\n");
        else printf("YES\n\n");
    }else printf("NO\n\n");

    //solution (i)
    printf("i)Binary Number? ");
    if(st[0]=='0' && len>=2){
        int flag=0;
        for(int i=0;st[i];i++){
            if(st[i]=='0' || st[i]=='1'){
                continue;
            }else flag=1;
        }
        if(flag)
            printf("NO\n\n");
        else printf("YES\n\n");
    }else printf("NO\n\n");



}