#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char input[100],input2[100];
    cin>>input>>input2;
    //strcpy(input,input2);
    //strcpy(input,"mashallah");
    strncpy(input,input2,3);//n is how many chars of input2 in input
    cout<<input<<endl;
    /*if(strcmp(input,input2)== 0)
    {
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }*/
    //cout<<strlen(input)<<endl;
}