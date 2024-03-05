#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
    NumberList list;
    list.Init();
    
    for(int i=0;i<15;i++){
        if(i%2 == 0){
            list.Add(i);
        }
        else{
            list.Add(100-i);
        }
    }

    list.Sort();
    list.Print();
    return 0;
}