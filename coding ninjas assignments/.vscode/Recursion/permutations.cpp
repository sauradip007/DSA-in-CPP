#include<iostream>
using namespace std;
void permutations(string p , string up)
{
    if(p.empty())
    {
        cout<<p<<endl;
        return;
    }
    char ch = up[0];
    for(int i = 0 ; i <= p.size(); i++)
    {
        string f = p.substr(0,i);
        string s = p.substr(i,p.size());
        permutations(f + ch + s, up.substr(1));
    }

}
int main()
{
    string input;
    permutations("","abc");
}