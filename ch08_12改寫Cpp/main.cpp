#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
int main(){
    int i;
    string str1[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    string str2[7]={"White","Red","Green","Yellow","Pink","Purple","Orange"};
    string str3[7]={};
    for(i=0;i<7;i++) {
        str3[i]=str2[i]+" "+str1[i];
        cout<<str3[i]<<endl;
    }
}
