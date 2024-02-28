#include <string>
#include <stdio.h>
using namespace std;

bool compareWords(string w1, string w2) {
    if (w1.length() == w2.length()) {
        return w1 < w2;
    }
    return w1.length() > w2.length();
}

void sortWords(string words[], int wordsIdx){
    for(int i=0;i<wordsIdx-1;i++){
        for(int j=i+1;j<wordsIdx;j++)
        {
            if(!compareWords(words[i],words[j])){
                swap(words[i],words[j]);
            }
        }
    }
}

int main() {
    char sentence[256];
    fgets(sentence, 256, stdin);
    string str = sentence;
    string words[100];

    bool isWord = true;
    int startWordIdx = 0;
    int wordIdx = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ' && (i + 1 == str.size() || str[i + 1] == ' ')) {
            words[wordIdx++] = str.substr(startWordIdx, i - startWordIdx + 1);
        }
        if (str[i] == ' ') {
            startWordIdx = i + 1;
        }
    }

    words[wordIdx-1].pop_back();//sterger \n de la ultimul cuvant
    sortWords(words,wordIdx);
    
    for (int i = 0; i < wordIdx; i++) {
        printf("%s\n", words[i].c_str());
    }
    return 0;
}
