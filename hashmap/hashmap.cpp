#include "hashmap.h"

Hashmap::Hashmap(){

}

Hashmap::Hashmap(int size){
    m_size = size;
    m_hash[100];
}

Hashmap::~Hashmap(){}

void Hashmap::add(string s, int n){
    int mFunction = n % m_size;
    m_hash[mFunction] = s;
}

bool Hashmap::contains(string s){

}

string Hashmap::get(int index){

}

void Hashmap::remove(string s){
    
}