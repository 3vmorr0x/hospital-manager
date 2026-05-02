# Hospital Management System (C++ OOP)

A comprehensive, console-based Hospital Management System built with C++ as part of the Programming II course project. This application demonstrates the practical application of Object-Oriented Programming (OOP) and persistent data management using file handling.

## Technical Implementation (OOP Pillars)

The system architecture is designed around the core principles of software engineering:

1. [cite_start]**Abstraction & Inheritance**: Utilizes an abstract base class `Person` [cite: 30] [cite_start]to define shared attributes (`id`, `name`, `phone`) [cite: 32][cite_start], which is inherited by `Doctor` and `Patient` classes[cite: 31, 37, 43].
2. [cite_start]**Polymorphism**: Employs pure virtual functions such as `display()` and `serialize()` [cite: 34, 35] [cite_start]to manage a heterogeneous array of pointers, allowing dynamic behavior at runtime[cite: 66].
3. **Encapsulation**: Protects data integrity by using private/protected members and providing access through public getters and setters.
4. [cite_start]**Persistent File Handling**: All data is stored and retrieved from a single text file (`hospital_data.txt`)[cite: 21]. [cite_start]The system uses a comma-separated format for serialization[cite: 22, 25].
5. [cite_start]**Operator Overloading**: Overloads the `<<` and `>>` operators to streamline input/output operations for system objects[cite: 65].

## Functional Requirements (CRUD)

[cite_start]The system supports full CRUD operations for both Patients and Doctors:
* [cite_start]**Create**: Add new patient or doctor records[cite: 48, 54].
* [cite_start]**Read**: Display all stored records in an organized table[cite: 49, 55, 59].
* [cite_start]**Update**: Modify existing record details based on ID[cite: 51, 56, 59].
* [cite_start]**Delete**: Remove records from the system and update the storage file[cite: 52, 57, 59].
* [cite_start]**Search**: Quickly find specific records by ID or Name[cite: 50, 55, 59].

## File Data Structure

Data is stored using the following standardized formats:
- [cite_start]**Patient**: `P, ID, Name, Age, Gender, Phone` [cite: 24, 25]
- [cite_start]**Doctor**: `D, ID, Name, Specialization, Phone` [cite: 27, 28]

## How to Run

1. Ensure you have a C++ compiler installed (e.g., g++).
2. Compile the project: `g++ main.cpp -o hospital_manager`
3. Run the executable: `./hospital_manager`

---
**Developed by: Omar Ebrahim**
