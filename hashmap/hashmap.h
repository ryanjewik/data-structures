#ifndef HASHMAP_H
#define HASHMAP_H
#include <cstdlib>
#include <iostream>
using namespace std;

class Hashmap{
    public:
    Hashmap();
    Hashmap(int size);
    virtual ~Hashmap();
    void add(string s, int n);
    bool contains(string s);
    string get(int index);
    void remove(string s);

    private:
    int m_size;
    string m_hash[];

};

#endif