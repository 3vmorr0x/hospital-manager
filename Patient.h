#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "Person.h"
using namespace std;

class Patient : public Person {
private:
    int age;
    string gender;
public:
    Patient(int id = 0, string name = "", string phone = "", int age = 0, string gender = "") : Person(id, name, phone), age(age), gender(gender) {}

    void display() override {
    cout << "Patient -> ID: " << id 
         << " | Name: " << name 
         << " | Phone: " << phone 
         << " | Age: " << age 
         << " | Gender: " << gender << endl;
    }

    string serialize() override {
        return "P," + to_string(id) + "," + name + "," + to_string(age) + "," + gender + "," + phone;
    }
};