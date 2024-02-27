#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main() {
    char sentence[256];
    scanf("%[^\n]", sentence);
    string str = sentence;
    string words[100];

    bool isWord = true;
    int pozStartWord = 0;
    int wordIndex = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0')) {
            words[wordIndex++] = str.substr(pozStartWord, i - pozStartWord + 1);
        }
        if (str[i] == ' ') {
            pozStartWord = i + 1;
        }
    }
    
    for (int i = 0; i < wordIndex; i++) {
        cout << words[i] << endl;
    }

    return 0;
}
