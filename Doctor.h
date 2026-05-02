#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "Person.h"
using namespace std;

class Doctor : public Person {
private:
    string specialization;
public:
    Doctor(int id = 0, string name = "", string phone = "", string specialization = "")
        : Person(id, name, phone), specialization(specialization) {}

    void display() override {
    cout << "Doctor  -> ID: " << id 
         << " | Name: " << name 
         << " | Phone: " << phone 
         << " | Specialization: " << specialization << endl;
    }

    string serialize() override {
        return "D," + to_string(id) + "," + name + "," + specialization + "," + phone;
    }
};