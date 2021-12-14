#include<stdio.h>
char st[100];
int n;

void WordCount(){
    int wordCount=0, letterCount=0, digitCount=0, otherCount=0;
    
    if(st[0]!=' ') wordCount++;
    for(int i=0;st[i];i++){
        if(st[i]!=' ' && st[i+1]==' '){
            wordCount++;
        }
    }
    printf("Word Count= %d\n",wordCount);
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%[^\n]s",st);
    WordCount();
    //printf("%s",st);

}