#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Student {
    private:
        int rollno, age;
        string name;
    public:
    Student(int stdRollno, string stdName, int stdAge) {
        rollno = stdRollno;
        name = stdName;
        age = stdAge;
    }
    void setRollno(int stdRollno) {
        rollno = stdRollno;
    }
    int getRollno() {
        return rollno;
    }
    void setName(string stdName) {
        name = stdName;
    }
    string getName() {
        return name;
    }
    void setAge(int stdAge) {
        age = stdAge;
    }
    int getAge() {
        return age;
    }
    void displayStudent() {
        cout << "\t\tRoll No: " << rollno << endl;
        cout << "\t\tName: " << name << endl;
        cout << "\t\tAge: " << age << endl;
    }
};

//create function to add new student
void addNewStudent(vector<Student> &students) {
    int rollno,age;
    string name;
    cout << "\t\tEnter Roll No: ";
    cin >> rollno;

    //Check if student already exists
    for(int i=0; i<students.size(); i++) {
        if(students[i].getRollno() == rollno) {
            cout << "\t\t Student Already Exists! " << endl;
            return;
        }
    }
    cout << "\t\tEnter Name: ";
    cin >> name;
    cout << "\t\tEnter Age: ";
    cin >> age;
    
    Student newStudent(rollno, name, age);
    students.push_back(newStudent);
}

//Function to display all students
void displayAllStudents(vector<Student> &students) {
    if(students.empty()) {
        cout << "\t\tNo Students Found!" << endl;
        return;
    }
    for(int i=0; i<students.size();i++) {
        students[i].displayStudent();
        cout << endl;
    }
}

//Function to Search Student
void searchStudent(vector<Student> &students) {
    int rollno;
    cout << "\t\tEnter Roll No to Search: ";
    cin >> rollno;

    for(int i=0; i<students.size(); i++){
        if(students[i].getRollno() == rollno) {
            cout << "\t\t-----Student Found!-----" << endl;
            students[i].displayStudent();
            return;
        }
    }
    cout << "\t\t-----Student Not Found!-----" << endl;
}

//Function to Update Student
void updateStudent(vector<Student> &students){
    string name;
    bool found = false;
    int choice;

    cout << "\t\tEnter Name to Update Record: ";
    cin.ignore();
    getline(cin,name);

    for(int i = 0; i < students.size(); i++) {
        if(students[i].getName() == name) {
            found = true;

            cout << "\t\t ---Student Found!---" << endl;
            cout << "\t\t1. Update Rollno" << endl;
            cout << "\t\t2. Update Name" << endl;
            cout << "\t\t3. Update Age" << endl;
            cout << "\t\tEnter Your Choice: ";
            cin >> choice;

            switch (choice){
                case 1:{
                    int rno;
                    cout << "\t\tEnter New Rollno: ";
                    cin >> rno;
                    students[i].setRollno(rno);
                    break;
                }
                case 2:{
                    string newName;
                    cout << "\t\tEnter New Name: ";
                    cin.ignore();
                    getline(cin,newName);
                    students[i].setName(newName);
                    break;
                }
                case 3:{
                    int age;
                    cout << "\t\tEnter New Age: ";
                    cin >> age;
                    students[i].setAge(age);
                    break;
                }
                default:{
                    cout << "\t\tInvalid Choice!" << endl;
                }
            }

            break;   // stop searching once found
        }
    }

    if(!found){
        cout << "\t\tRecord not Found!" << endl;
    }
}

//Function to Delete Student
void deleteStudent(vector<Student> &students) {
    string name;
    cout << "Enter Name to Delete:";
    cin.ignore();
    getline(cin,name);

    for(int i=0; i<students.size(); i++) {
        if(students[i].getName() == name) {
            students.erase(students.begin() + i);
            cout << "\t\tRecord Deleted Successfully!" << endl;
            return;

        }
    }
    cout << "\t\tRecord not Found!" << endl;
}

int main() {
    vector<Student> students;
    students.push_back(Student(1, "Alice", 20));
    char choice;
    do{
        int op;
        cout<<"\n\t\t--------------------------------";
        cout<<"\n\t\t*** Student Management System ***";
        cout<<"\n\t\t--------------------------------";
        cout<<"\n\t\t 1. Add New Student"<<endl;
        cout<<"\t\t 2. Display All Student "<<endl;
        cout<<"\t\t 3. Search Student"<<endl;
        cout<<"\t\t 4. Update Student"<<endl;
        cout<<"\t\t 5. Delete Student "<<endl;
        cout<<"\t\t 6. Exit"<<endl;
        cout<<"\t\t Enter Your Choice : ";
        cin >> op;

        switch(op) {
            case 1:{
                addNewStudent(students);
                break;
            }
            case 2:{
                displayAllStudents(students);
                break;
            }
            case 3:{
                searchStudent(students);
                break;
            }
            case 4:{
                updateStudent(students);
                break;
            }
            case 5:{
                deleteStudent(students);
                break;
            }
            case 6:{
                cout << "\t\tExiting..." << endl;
                return 0;
            }   
        }
        cout << "\t\tDo you want to Continue[y/n]: ";
        cin >> choice;
    }while(choice == 'Y' || choice == 'y');
    return 0;
}