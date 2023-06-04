#include "dog.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Dog::Dog(){
    m_age = 0;
    m_name = "";
    m_owner = NULL;
}

Dog::Dog(string name, int age, string ownerName){
    m_name = name;
    m_age = age;
    m_owner = new Person(ownerName);
}

Dog::~Dog(){
    if(m_owner != NULL){
        delete m_owner;
    } 
}

void Dog::speak(){
    cout << "Bark! I am a dog. My name is " << m_name <<"." <<endl;
    cout <<"I have been alive for " << m_age << " years." << endl;
    cout <<"I belong to " << m_owner->getName() << endl;
}

string Dog::getName(){
    return m_name;
}

int Dog::getAge(){
    return m_age;
}

void Dog::setName(string name){
    m_name = name;
}

void Dog::setAge(int age){
    m_age = age;
}

