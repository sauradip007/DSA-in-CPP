#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
template<typename V>
class MapNode{ //linked list
    public:
    string key;
    V value;
    MapNode* next;
    public:
    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode()
    {
        delete next;
    }

}; //Map node
template<typename V>
class ourMap{
    MapNode<V>** buckets; //buckets array
    int count; //number of entries currently present
    int numBuckets; //size of bucket array
    public:
    ourMap()
    {
        count = 0; //elements currently present in array
        numBuckets = 5;
        buckets = new MapNode<V>* [numBuckets];
        for(int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL; //initialising array with NULL
        }
    }
    //linked list head is a pointer
    ~ourMap(){
        for(int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

    int size()
    {
        return count;
    }
   
    int getBucketIndex(string key){
        int hashCode = 0;
        //considering string to be a p based number
        int currentCoeff = 1;
        //p^0
        for(int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i]*currentCoeff;
            hashCode = hashCode % numBuckets; //same modulus prop as below dw about it 
            currentCoeff *= 37; //considering p based no to be 37
            currentCoeff = currentCoeff % numBuckets //using modulus property ((n1%r)* (n2%r) * (n3%r)) % r = (n1*n2*n3)%r
        }

        return hashCode % numBuckets; //compression function
    }
    void rehash(){
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[2*numBuckets];
        for(int i = 0; i < 2*numBuckets; i++)
        {
            buckets[i] = NULL;
            //initialising new array to null
        }
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;
        //now it behaves an entirely new hashmap which is completely empty
        for(int i = 0; i < oldBucketCount ; i++)
        {
            MapNode<V>* head = temp[i];
            //traversing the LL
            while(head != NULL)
            {
                string key = head->key;
                V value = head->value;
            }
        }
    }
    void insert(string key, V value){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex]; //array stores address of head
        while(head != NULL)
        {
            if(head->key == key)
            {
                head->value = value;
                return;
            }//if key is found it is overwritten
            head = head->next;
        }
            head = buckets[bucketIndex];
            //else a new node is created and linked to head
            MapNode<V>* node = new MapNode<V>(key,value);
            node->next = head;
            buckets[bucketIndex] = node; //the array bucketindex is made to point to this new node created and inserted
            count++; //on insertion of a new node , count is incremented

            //Rehashing
            //we check load factor
            double loadFactor = (1.0 * count)/numBuckets;
            if(loadFactor > 0.7)
            {
                rehash();
            }
        

    }
    V getValue(string key) // search function
    {
        int bucketIndex = getBucketIndex(key); //go to the index of the key in buckets array
        MapNode<V> *head = buckets[bucketIndex];
        while(head != NULL)
        {
            if(head->key == key){
                return head->key;
            }
            head = head->next;
        }
        return 0; //element not found
    }
    V remove(string key)
    {
        int bucketIndex = getBucketIndex(string key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V>* prev = NULL; //prev node of deleted node
        while(head != NULL)
        {
            if(head->key == key) //key matches
            {
                if(prev == NULL){
                    buckets[bucketIndex] = head->next;
                    //make bucket array point to head->next if head is the required key to be deleyed

                }
                else{
                prev->next = head->next;
                }
                V value = head->value; //stores deleted ley value
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        //if we come out of while loop, the key could not be found
        return 0; //element could not be found
    }

};