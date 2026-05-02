#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Person {
protected:
    int id;
    string name;
    string phone;
public:
    Person(int id = 0, string name = "", string phone = "") : id(id), name(name), phone(phone) {}
    virtual ~Person() {}

    virtual void display() = 0;
    virtual string serialize() = 0;

    void Set_id(int id) { this->id = id; }
    int Get_id() { return id; }
    void Set_name(string name) { this->name = name; }
    string Get_name() { return name; }
    void Set_phone(string phone) { this->phone = phone; }
    string Get_phone() { return phone; }

    friend ostream& operator<<(ostream& os, Person& p) {
        p.display();
        return os;
    }
};