
//
// Created by rozi on 6/8/20.
//

#ifndef HW5_HASHNODE_H
#define HW5_HASHNODE_H
#include <utility>
#include <string>
#include <iostream>


template <class V>
class HashNode{ //Simple template class, key always string and value can be anything.
private:
    std::string key;
    V value;
public:
    HashNode(std::string, V);
    HashNode();
    std::string getKey() const;
    void setKey(const std::string&);
    V getVal() const;
    void setVal(const V&);
};

template<class V>
HashNode<V>::HashNode(std::string key, V val)
    :key(std::move(key)), value(val){
}

template<class V>
std::string HashNode<V>::getKey() const{
    return this->key;
}

template<class V>
void HashNode<V>::setKey(const std::string& newKey) {
    this->key = newKey;

}

template<class V>
V HashNode<V>::getVal() const{
    return this->value;
}

template<class V>
void HashNode<V>::setVal(const V& newVal) {
    this->value = newVal;

}

template<class V>
HashNode<V>::HashNode()= default;

template<class V>
std::ostream& operator<<(std::ostream&os, const HashNode<V>& node){
    os<<"{"<<node.getKey()<<" : "<<node.getVal()<<"}";
    return os;
}


#endif //HW5_HASHNODE_H
