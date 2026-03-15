#include <iostream>
#include <string>
using namespace std;

class Employee {
    protected:
        int empId;
        string name;
    public:
    //concrete method
    void InputBasicInfo() {
        cout<<"Enter Employee ID: ";
        cin>>empId;
        cout<<"Enter Employee Name: ";
        cin.ignore();
        getline(cin,name);
    }
    void DisplayBasicInfo() {
        cout<<"-----Basic Information----"<<endl;
        cout<<"Employee ID: "<<empId<<endl;
        cout<<"Employee Name: "<<name<<endl;
    }
    //pure virtual function
    virtual void inputInfo() = 0;
    virtual void calculateSalary() const=0;
};

//derived class for visiting employee
class visitingEmp : public Employee {
    private:
        int numberOfDays;
        float dailyWages;
    public:
    //@Override
    void inputInfo() {
        cout<<"Enter Daily Wages: ";
        cin>>dailyWages;
        cout<<"Enter Number of Days: ";
        cin>>numberOfDays;
    }
    //@Override
    void calculateSalary() const {
        float salary = dailyWages*numberOfDays;
        cout<<"Salary: "<<salary<<endl;
    }
};

//derived class for permanent employee
class permanentEmp : public Employee {
    private:
        int monthlySalary;
    public:
    void inputInfo() {
        cout<<"Enter Monthly Salary: ";
        cin>>monthlySalary;
    }
    void calculateSalary() const {
        cout<<"Salary: "<<monthlySalary<<" Per Month"<<endl;
    }
};

main() {
   Employee *emp;
   int choice;
   do{
        cout<<"-----Main Menu-----"<<endl;
        cout<<"1.Create Visiting Employee"<<endl;
        cout<<"2.Create Permanent Employee"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;
        switch(choice){
            case 1:{
                emp = new visitingEmp();
                break;
            }
            case 2:{
                emp = new permanentEmp();
                break;
            }
            case 0:{
                cout<<"Exiting..."<<endl;
                break;
            }
            default:{
                cout<<"Invalid Choice!, Please enter valid Number."<<endl;
                continue;
            }
        }
        if(choice != 0) {
            emp->InputBasicInfo();
            emp->inputInfo();
            cout<<"\nEmployee Information: "<<endl;
            emp->DisplayBasicInfo();
            emp->calculateSalary();
            delete emp; // free the allocated memory
        }
   }while(choice!=0); 
}
