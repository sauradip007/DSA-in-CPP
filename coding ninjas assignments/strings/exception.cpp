#include<iostream>
#include<cstring>
using namespace std;
class except{
    public:
    char a;
    public:
    except()
    {
        cout<<"Enter character : "<<endl;
        cin>>a;
    }
    class Error{};
    void create()
    {
        if (a == '\t')
        {
            throw Error();

        }
        else{
            int ch = tolower(a);
            char c = ch;
            cout<<"The lower case char is : "<<c<<endl;
        }
    }
};
int main()
{
    except ob;
    try{
        
        ob.create();

    }
    catch(except :: Error)
    {
        cout<<"\nNo character entered exception"<<endl;
    }
}