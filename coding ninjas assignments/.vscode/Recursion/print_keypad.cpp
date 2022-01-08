#include<iostream>
using namespace std;
void print_keypad(int num)
{
    string output;
    int small = num / 10;
    if (small == 0)
    {
        cout << output << endl;
        return;
   }
   
//    print_keypad(num % 10);
   string map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
   
   int smaller = num % 10;
   string s = map[smaller];
   string  p = map[small];
   print_keypad(num / 10);
for(int i = 0 ; i <= p.size(); i++)
{
    output+=p[i];
}
   for(int i = 0 ; i <= s.size(); i++)
   {
       print_keypad(num/10);
       output += s[i];
   }
  

}
int main()
{
    int num;
    cin >> num;

    print_keypad(num);

    return 0;
}