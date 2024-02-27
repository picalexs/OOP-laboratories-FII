#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long convertToNumber(char *line){
    long long nr=0;
    int idx=0;
    while(line[idx]>= '0' && line[idx]<='9'){
        nr=nr*10 + line[idx] - '0';
        idx++;
    }
    return nr;
}

int main()
{
    FILE *file = fopen("in.txt","r");
    if(file==NULL){
        printf("Couldn't open the file!!");
        return 0;
    }

    int sum=0;
    char line[16]{};
    while(fgets(line,16,file)!=NULL){
        sum+=convertToNumber(line);
    }
    printf("The sum is: %d\n", sum);
    return 0;
}