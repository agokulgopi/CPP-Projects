#include <iostream>
using namespace std;

class publication{
protected:
    float price;
public:
    publication() : price(0.0) {
    }
    
    void getData(){
        cout << "Enter Price: ";
        cin >> price;
    }
    
    void putData(){
        cout << "Price: " << price << endl;
    }
};

class Book : public publication{
private:
    int pageCount;
public:
    Book() : pageCount(0) {
    }
    
    void getData(){
        cout << "Enter Book Page Count: ";
        cin >> pageCount;
        publication::getData();  // Get price
    }
    
    void putData(){
        cout << "Page Count: " << pageCount << endl;
        publication::putData();  // Display price
    }
};

class Tape : public publication{
private:
    float time;
public:
    Tape() : time(0.0) {
    }
    
    void getData(){  // ✓ FIXED: Correct method name
        cout << "Enter Tape Time in Minutes: ";
        cin >> time;
        publication::getData();  // Get price
    }
    
    void putData(){
        cout << "Playing Time: " << time << " minutes" << endl;
        publication::putData();  // Display price
    }
};

int main(){  // ✓ FIXED: Added int return type
    Book b;
    Tape t;
    int op;
    char choice;
    
    do{
        cout << "\n===== Publication Information System =====" << endl;
        cout << "1. Book Information" << endl;
        cout << "2. Tape Information" << endl;
        cout << "==========================================" << endl;
        cout << "Enter Your Choice: ";
        cin >> op;
        
        switch(op){
            case 1:
                cout << "\n------ Book Information ------" << endl;
                b.getData();
                cout << "\n------ Display Book Information ------" << endl;
                b.putData();
                break;
            case 2:
                cout << "\n------ Tape Information ------" << endl;
                t.getData();  // ✓ Now calls Tape::getData() correctly!
                cout << "\n------ Display Tape Information ------" << endl;
                t.putData();
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
        
        cout << "\nDo you want to Continue [Y/N]? ";
        cin >> choice;
        
    } while(choice == 'y' || choice == 'Y');
    
    cout << "Thank you for using the system!" << endl;
    return 0;
}