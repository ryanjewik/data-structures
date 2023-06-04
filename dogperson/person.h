
#indef PERSON_H // header guard
#define PERSON_H
#include <string>;
using namespace std;

class Person{
    public:
    Person();
    Person(string name);
    virtual ~Person(); // destructor
    string getName();
    void setName(string name);
    private:
    string m_name;
};
#endif




