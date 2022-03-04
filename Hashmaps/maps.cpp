#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
    unordered_map<string,int>ourMap;
    //insert
    pair<string,int> p("abc",1);
    ourMap.insert(p); //insert value pairs in p
    //Another way of representation
    ourMap["def"] = 2;
    //value 2 corresponds to def key

    //find or access
    //Similar to arrays
    cout<<ourMap["abc"]<<endl;
    //Another way of representation is similar to vectors
    cout<<ourMap.at("abc")<<endl;
    // cout<<ourMap.at("ghi")<<endl;
    cout<<ourMap["ghi"]<<endl;

    //To check whether an element is present or not
    if(ourMap.count("ghi") > 0)
    {
        cout<<"ghi is present"<<endl;
    }
    //size function
    cout<<ourMap.size()<<endl;

    //erase
    ourMap.erase("ghi");
    //pass a key which is to be present , it deletes key and its corresponding value
    if (ourMap.count("ghi") > 0) //how many time does the key come, returns 0 or 1
    {
        cout << "ghi is present" << endl;
    }
}