//
// Created by rozi on 6/8/20.
//

#ifndef HW5_HASHTABLE_H
#define HW5_HASHTABLE_H

#include <list>
#include <vector>
#include <string>
#include "HashNode.h"

template<class V>
class HashTable{
private: //Basically, the hash table is an array of 10k elements, each one of them being a linked list of HashNode pointers.
    std::list<HashNode<V>*> arr[10000];
public:
    HashTable(); //Default constructor
    void insert(const std::string&, V); //Inserts element in the hashtable
    static int hashFunction(const std::string&); //Static hashing function
    V operator[](const std::string&) const; //Overloading the [] operator, allowing you to do things like std::cout<<table["key"]
    V findVal(const std::string&) const;
    HashNode<V>* searchNode(const std::string&) const; //Searched for a node based on a key.
    std::vector<std::string> keys() const; //Returns a vector of all keys.
    std::vector<V> values() const; //Returns a vector of all values.
    bool pop(const std::string&); //Removes an element from the hash table.
    bool keyExists(const std::string&) const; //Checks if a key exists.
    bool isEmpty() const;
    void print() const;
    ~HashTable();

};

template<class V>
int HashTable<V>::hashFunction(const std::string& key){
    int hash = 0;
    for(char i : key){
        hash += i*59+3;
    }
    hash = hash % 10000;
    return hash; //Simple hash function, computes a hash for the key and maps it to an index from 0 to 10k.
}


template<class V>
HashTable<V>::HashTable()= default;

template<class V>
HashNode<V> *HashTable<V>::searchNode(const std::string & key) const{
    int hash = hashFunction(key); //Hashes the key
    for(auto node: arr[hash]){ //Iterates through the linked list that corresponds to the specific hash.
        if(node->getKey() == key){
            return node; //If it finds the node, returns the node.
        }
    }
    return nullptr;
}

template<class V>
void HashTable<V>::insert(const std::string& key, V val) {
    int hash = hashFunction(key); //Gets the key's hash.
    HashNode<V>* existentNode = searchNode(key); //Checks if the node exists.
    if(existentNode == nullptr){ //If the node does not exist, create the new node.
        auto*node = new HashNode<V>(key, val);
        this->arr[hash].push_back(node); //Then push it to the list.
    } else {
        existentNode->setVal(val); //If it does exist, just replace the value.
    }

}

template<class V>
V HashTable<V>::operator[](const std::string &key) const{ //Overloading the operator to allow the accessing via key.
    int hash = hashFunction(key);
    V val;
    for(auto node: arr[hash]){
        if(node->getKey() == key){
            val = node->getVal();
        }
    }
    return val;
}

template<class V>
std::vector<std::string> HashTable<V>::keys() const{ //Just returns a vector of keys.
    std::vector<std::string> keyVector;
    for(auto & i : arr){ //Iterates through the array
        for(auto node: i){ //For each array element, iterate through the linked list
            keyVector.push_back(node->getKey()); //For each element add it to the vector.
        }
    }
    return keyVector;
}

template<class V>
std::vector<V> HashTable<V>::values() const{ //Same as the keys() but for values.
    std::vector<V> valVector;
    for(auto & i : arr){
        for(auto node: i){
            valVector.push_back(node->getVal());
        }
    }
    return valVector;
}

template<class V>
bool HashTable<V>::pop(const std::string & key) {
    HashNode<V>* existentNode = searchNode(key);
    int hash = hashFunction(key);
    if(existentNode != nullptr){ //If the node exists
        this->arr[hash].remove(existentNode); //First, remove it from the linked list.
        delete existentNode; //Second, delete the node itself.
        return true;
    } else {
        return false;
    }
}

template<class V>
bool HashTable<V>::keyExists(const std::string &key) const{ //Just simply checks if a key exists.
    int hash = hashFunction(key);
    for(auto node: arr[hash]){
        if(node->getKey() == key){
            return true;
        }
    }
    return false;
}

template<class V>
HashTable<V>::~HashTable() {
    for(auto key: this->keys()){
        this->pop(key);
    }

}

template<class V>
V HashTable<V>::findVal(const std::string& key) const {
    int hash = hashFunction(key);
    V val;
    for(auto node: arr[hash]){
        if(node->getKey() == key){
            val = node->getVal();
        }
    }
    return val;
}

template<class V>
void HashTable<V>::print() const {
    for(auto key: this->keys()){
        std::cout<<"("<<key<<", " << this->findVal(key) <<") ";
    }
}

template<class V>
bool HashTable<V>::isEmpty() const{
    return this->keys().empty();
}




#endif //HW5_HASHTABLE_H
