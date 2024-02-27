#include <iostream>
#include <string>
#include <cstdio>  // Include cstdio for scanf
using namespace std;

int main() {
    char word[256];
    string words[100];
    int idx=0;
    while(scanf("%s",word)!=EOF){
        words[idx++]=word;
    }
    
    for (int i = 0; i < idx; i++) {
        cout << words[i] << endl;
    }

    return 0;
}
