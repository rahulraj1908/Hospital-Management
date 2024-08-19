#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Person {
protected:
    string name, gender, address;
    int age;
public:
    virtual void getDetails() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Gender: ";
        getline(cin, gender);
        cout << "Enter Address: ";
        getline(cin, address);
    }
    virtual void showDetails() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Address: " << address << endl;
    }
};

class Patient : public Person {
private:
    int patientID;
    string disease, admissionDate;
public:
    void getDetails() override {
        Person::getDetails();
        cout << "Enter Patient ID: ";
        cin >> patientID;
        cin.ignore();
        cout << "Enter Disease: ";
        getline(cin, disease);
        cout << "Enter Admission Date: ";
        getline(cin, admissionDate);
    }
    void showDetails() const override {
        Person::showDetails();
        cout << "Patient ID: " << patientID << endl;
        cout << "Disease: " << disease << endl;
        cout << "Admission Date: " << admissionDate << endl;
    }
    void saveToFile() {
        ofstream outFile("patients.txt", ios::app);
        if (outFile.is_open()) {
            outFile << patientID << "," << name << "," << age << "," << gender << ","
                    << address << "," << disease << "," << admissionDate << "\n";
            outFile.close();
        } else {
            cout << "Error opening file!" << endl;
        }
    }
    void loadFromFile() {
        ifstream inFile("patients.txt");
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            inFile.close();
        } else {
            cout << "Error opening file!" << endl;
        }
    }
};

class Staff : public Person {
protected:
    int staffID;
    string designation;
    double salary;
public:
    void getDetails() override {
        Person::getDetails();
        cout << "Enter Staff ID: ";
        cin >> staffID;
        cin.ignore();
        cout << "Enter Designation: ";
        getline(cin, designation);
        cout << "Enter Salary: ";
        cin >> salary;
        cin.ignore();
    }
    void showDetails() const override {
        Person::showDetails();
        cout << "Staff ID: " << staffID << endl;
        cout << "Designation: " << designation << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Doctor : public Staff {
private:
    string specialization, availability;
public:
    void getDetails() override {
        Staff::getDetails();
        cout << "Enter Specialization: ";
        getline(cin, specialization);
        cout << "Enter Availability: ";
        getline(cin, availability);
    }
    void showDetails() const override {
        Staff::showDetails();
        cout << "Specialization: " << specialization << endl;
        cout << "Availability: " << availability << endl;
    }
    void saveToFile() {
        ofstream outFile("doctors.txt", ios::app);
        if (outFile.is_open()) {
            outFile << staffID << "," << name << "," << age << "," << gender << ","
                    << address << "," << designation << "," << salary << ","
                    << specialization << "," << availability << "\n";
            outFile.close();
        } else {
            cout << "Error opening file!" << endl;
        }
    }
    void loadFromFile() {
        ifstream inFile("doctors.txt");
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            inFile.close();
        } else {
            cout << "Error opening file!" << endl;
        }
    }
};

class Nurse : public Staff {
private:
    string shift;
    int experience;
public:
    void getDetails() override {
        Staff::getDetails();
        cout << "Enter Shift: ";
        getline(cin, shift);
        cout << "Enter Experience (in years): ";
        cin >> experience;
        cin.ignore();
    }
    void showDetails() const override {
        Staff::showDetails();
        cout << "Shift: " << shift << endl;
        cout << "Experience: " << experience << " years" << endl;
    }
    void saveToFile() {
        ofstream outFile("nurses.txt", ios::app);
        if (outFile.is_open()) {
            outFile << staffID << "," << name << "," << age << "," << gender << ","
                    << address << "," << designation << "," << salary << ","
                    << shift << "," << experience << "\n";
            outFile.close();
        } else {
            cout << "Error opening file!" << endl;
        }
    }
    void loadFromFile() {
        ifstream inFile("nurses.txt");
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            inFile.close();
        } else {
            cout << "Error opening file!" << endl;
        }
    }
};

class Appointment {
private:
    int appointmentID, patientID, doctorID;
    string date, time;
public:
    void scheduleAppointment() {
        cout << "Enter Appointment ID: ";
        cin >> appointmentID;
        cout << "Enter Patient ID: ";
        cin >> patientID;
        cout << "Enter Doctor ID: ";
        cin >> doctorID;
        cin.ignore();
        cout << "Enter Date (dd/mm/yyyy): ";
        getline(cin, date);
        cout << "Enter Time (hh:mm): ";
        getline(cin, time);
    }
    void showAppointmentDetails() const {
        cout << "Appointment ID: " << appointmentID << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Doctor ID: " << doctorID << endl;
        cout << "Date: " << date << endl;
        cout << "Time: " << time << endl;
    }
    void saveToFile() {
        ofstream outFile("appointments.txt", ios::app);
        if (outFile.is_open()) {
            outFile << appointmentID << "," << patientID << "," << doctorID << ","
                    << date << "," << time << "\n";
            outFile.close();
        } else {
            cout << "Error opening file!" << endl;
        }
    }
    void loadFromFile() {
        ifstream inFile("appointments.txt");
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            inFile.close();
        } else {
            cout << "Error opening file!" << endl;
        }
    }
};

class Inventory {
private:
    int itemID, quantity;
    string itemName;
    double price;
public:
    void addItem() {
        cout << "Enter Item ID: ";
        cin >> itemID;
        cin.ignore();
        cout << "Enter Item Name: ";
        getline(cin, itemName);
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Price: ";
        cin >> price;
        cin.ignore();
    }
    void updateItem() {
        cout << "Enter new Quantity: ";
        cin >> quantity;
        cout << "Enter new Price: ";
        cin >> price;
        cin.ignore();
    }
    void showInventory() const {
        cout << "Item ID: " << itemID << endl;
        cout << "Item Name: " << itemName << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: $" << price << endl;
    }
    void saveToFile() {
        ofstream outFile("inventory.txt", ios::app);
        if (outFile.is_open()) {
            outFile << itemID << "," << itemName << "," << quantity << ","
                    << price << "\n";
            outFile.close();
        } else {
            cout << "Error opening file!" << endl;
        }
    }
    void loadFromFile() {
        ifstream inFile("inventory.txt");
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            inFile.close();
        } else {
            cout << "Error opening file!" << endl;
        }
    }
};

int main() {
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Nurse> nurses;
    vector<Appointment> appointments;
    vector<Inventory> inventories;

    int choice;
    while (true) {
        cout << "Hospital Management System Menu:\n";
        cout << "1. Add Patient\n";
        cout << "2. Show All Patients\n";
        cout << "3. Add Doctor\n";
        cout << "4. Show All Doctors\n";
        cout << "5. Add Nurse\n";
        cout << "6. Show All Nurses\n";
        cout << "7. Schedule Appointment\n";
        cout << "8. Show All Appointments\n";
        cout << "9. Add Inventory Item\n";
                cout << "10. Show Inventory\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            Patient p;
            p.getDetails();
            p.saveToFile();
            patients.push_back(p);
            break;
        }
        case 2: {
            Patient p;
            p.loadFromFile();
            break;
        }
        case 3: {
            Doctor d;
            d.getDetails();
            d.saveToFile();
            doctors.push_back(d);
            break;
        }
        case 4: {
            Doctor d;
            d.loadFromFile();
            break;
        }
        case 5: {
            Nurse n;
            n.getDetails();
            n.saveToFile();
            nurses.push_back(n);
            break;
        }
        case 6: {
            Nurse n;
            n.loadFromFile();
            break;
        }
        case 7: {
            Appointment a;
            a.scheduleAppointment();
            a.saveToFile();
            appointments.push_back(a);
            break;
        }
        case 8: {
            Appointment a;
            a.loadFromFile();
            break;
        }
        case 9: {
            Inventory i;
            i.addItem();
            i.saveToFile();
            inventories.push_back(i);
            break;
        }
        case 10: {
            Inventory i;
            i.loadFromFile();
            break;
        }
        case 11:
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

