#include <iostream>
#include <ostream>
#include <string>

using namespace std;

struct Person
{
    int key;
    string nombre;
    Person(int key, string nombre): key(key), nombre(nombre) {}
};

bool operator<(Person p1, Person p2){
     return p1.key < p2.key ;
}

bool operator>(Person p1, Person p2){
     return p1.key > p2.key ;
}

ostream& operator<<(ostream& os, Person p){
    os<<p.key<<"-"<<p.nombre;
    return os;
}
