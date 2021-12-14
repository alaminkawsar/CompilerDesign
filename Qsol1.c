#include<stdio.h>
#include<string.h>
char st[100];

int isLetter(char ch){
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
        return 1;
    }else return 0;
}
int isDigit(char ch){
    if(ch>='0' && ch<='9') return 1;
    else return 0;
}


void activityA(){

    int wordCount=0, letterCount=0, digitCount=0, otherCount=0;

    for(int i=0;st[i];i++){
        if(st[i]!=' ' && (st[i+1]==' ' || st[i+1]=='\0')){
            wordCount++;
        }
    }

    for(int i=0;st[i];i++){
        if(isLetter(st[i])){
            letterCount++;
        }
    }

    for(int i=0;st[i];i++){
        if(isDigit(st[i])){
            digitCount++;
        }
    }

    int spaceCount=0;
    for(int i=0;st[i];i++){
        if(st[i]==' ') spaceCount++;
    }

    otherCount = strlen(st)-(spaceCount+digitCount+letterCount);


    printf("Word Count= %d\n",wordCount);
    printf("Letter Count= %d\n",letterCount);
    printf("Digit Count= %d\n",digitCount);
    printf("Other Count= %d\n",otherCount);
}

void activityB(){

    printf("Letters are: ");
    for(int i=0;st[i];i++){
        if(isLetter(st[i])){
            printf("%c ",st[i]);
        }
    }
    printf("\nDigits are: ");

    for(int i=0;st[i];i++){
        if(isDigit(st[i])){
            printf("%c ",st[i]);
        }
    }
    printf("\nOthers are: ");
    for(int i=0;i<st[i];i++){
        if(!isDigit(st[i]) && !isLetter(st[i]) && st[i]!=' '){
            printf("%c ",st[i]);
        }
    }
    printf("\n");

    
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%[^\n]s",st);
    activityA();

    printf("\n");

    activityB();


}