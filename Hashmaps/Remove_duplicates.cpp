#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int>removeDup(int* a, int n){
    vector<int>output;
    unordered_map<int,bool>seen;
    for(int i = 0; i < n; i++)
    {
        //if number has arrived already dont insert in vector , if it hasnt arrived yet i.e. unique occurence , add to vector
        if(seen.count(a[i]) > 0){
            continue;//duplicate
        }
        seen[a[i]] = true; //not duplicate, unique , we havent seen it
        output.push_back(a[i]);


    }
    return output;
}
int main()
{
    int a[12] = {1,2,3,2,3,2,1,4,3,6,5,5};
    vector<int>output = removeDup(a,12);
    for(int i = 0 ; i < output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
}