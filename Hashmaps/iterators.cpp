#include<iostream>
#include<vector>
using namespace std;
#include<unordered_map>
int main()
{
    unordered_map<string,int>ourmap;
    ourmap["abc"] = 1;
    ourmap["abc1"] = 2;
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc4"] = 5;
    ourmap["abc5"] = 6;

    unordered_map<string,int>::iterator it = ourmap.begin();
    while(it != ourmap.end())
    {
        cout<<"Key : " <<it->first<<"Value : "<<it->second<<endl;
    //a pair is created with inbuilt first(key) and second(value) objects
        it++;

    }
    //find
    unordered_map<string, int>::iterator it2 = ourmap.find("abc"); // returns iterator
    ourmap.erase(it2); //deletes wherever it is pointing to
    ourmap.erase(it2,it2 + 4); //deletes it2 and next 2 elements stops before 4 
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    vector<int>::iterator it1 = v.begin();
    while(it1 != v.end())
    {
        cout<<*it1<<endl;
        it1++;
    }
}