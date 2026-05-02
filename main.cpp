#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "Person.h"
#include "Doctor.h"
#include "Patient.h"
using namespace std;

Person* database[1000];
int count = 0;
const string filename = "hospital_data.txt";

void save_to_File() {
    ofstream file(filename, ios::trunc);
    for (int i = 0; i < count; i++) {
        file << database[i]->serialize() << endl;
    }
    file.close();
}

void load_from_file() {
    ifstream file(filename);
    if (!file) return;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string type, idStr, name, phone, extra1, extra2;
        
        getline(ss, type, ',');
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        
        if (type == "P") {
            getline(ss, extra1, ',');
            getline(ss, extra2, ',');
            getline(ss, phone, ',');
            database[count++] = new Patient(stoi(idStr), name, phone, stoi(extra1), extra2);
        } else if (type == "D") {
            getline(ss, extra1, ',');
            getline(ss, phone, ',');
            database[count++] = new Doctor(stoi(idStr), name, phone, extra1);
        }
    }
    file.close();
}

void add_person() {
    int id, age;
    string name, phone, gender, spec, choice;
    cout << "Choose Section: p- Patient, d- Doctor: ";
    cin >> choice;

    cout << "Enter ID, Name, Phone: ";
    cin >> id; cin.ignore(); getline(cin, name); cin >> phone;

    if (choice == "p") {
        cout << "Enter Age, Gender: ";
        cin >> age >> gender;
        database[count++] = new Patient(id, name, phone, age, gender);
    } else {
        cout << "Enter Specialization: ";
        cin.ignore(); getline(cin, spec);
        database[count++] = new Doctor(id, name, phone, spec);
    }
    save_to_File();
}

void display_all() {
    cout << "\n--- Hospital Records ---\n";
    for (int i = 0; i < count; i++) {
        cout << *database[i];
    }
}

void search_person() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;
    for (int i = 0; i < count; i++) {
        if (database[i]->Get_id() == id) {
            database[i]->display();
            return;
        }
    }
    cout << "Not found.\n";
}

void delete_person() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    for (int i = 0; i < count; i++) {
        if (database[i]->Get_id() == id) {
            delete database[i];
            for (int j = i; j < count - 1; j++) database[j] = database[j+1];
            count--;
            save_to_File();
            cout << "Deleted.\n";
            return;
        }
    }
}

int main() {
    cout << "hello in our hospital manager ! ";
    load_from_file();
    int first_choice;
    while (true) {
        cout << "\n1-Create 2-Update 3-Display 4-Delete 5-Search 6-Exit\nChoice: ";
        cin >> first_choice;
        if (first_choice == 1)
        {
            add_person();
        }
        else if (first_choice == 3)
        {
            display_all();
        }
        else if (first_choice == 4)
        {
            delete_person();
        }
        else if (first_choice == 5)
        {
            search_person();
        }
        else if (first_choice == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid choice! try again .. \n";
        }
    }
    return 0;
}