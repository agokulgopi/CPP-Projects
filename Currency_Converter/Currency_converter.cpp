#include <iostream>
using namespace std;

class CurrencyConverter{
private:
    double usdToEuroRate;
    double euroToUsdRate;
    double usdToPakRupeeRate;
    double usdToIndRupeeRate;

public:  // ✓ FIXED: Constructor and methods should be PUBLIC
    // ✓ FIXED: No return type, correct name
    CurrencyConverter(double usdToEuro, double euroToUsd, double usdToPak, double usdToInd){
        usdToEuroRate = usdToEuro;
        euroToUsdRate = euroToUsd;
        usdToPakRupeeRate = usdToPak;
        usdToIndRupeeRate = usdToInd;
    }
    
    // Method to convert USD to Euro
    double usdToEuro(double usdAmount){
        return usdAmount * usdToEuroRate;
    }
    
    // Method to convert Euro to USD
    double euroToUsd(double euroAmount){
        return euroAmount * euroToUsdRate;
    }
    
    // Method to convert USD to Pakistani Rupee
    double usdToPakRupee(double usdAmount){
        return usdAmount * usdToPakRupeeRate;
    }
    
    // Method to convert USD to Indian Rupee
    double usdToIndRupee(double usdAmount){
        return usdAmount * usdToIndRupeeRate;
    }

    // Display Exchange Rate Method
    void displayExchangeRate(){
        cout << "\n\t-------- Current Exchange Rate ----------\n";
        cout << "1 USD to Euro: " << usdToEuroRate << endl;
        cout << "1 Euro to USD: " << euroToUsdRate << endl;
        cout << "1 USD to Pakistani Rupee: " << usdToPakRupeeRate << endl;
        cout << "1 USD to Indian Rupee: " << usdToIndRupeeRate << endl;
    }
};

int main(){  // ✓ FIXED: Added int return type
    const double initialUsdToEuroRate = 0.85;
    const double initialEuroToUsdRate = 1.18;
    const double initialUsdToPakRate = 277.50;
    const double initialUsdToIndRate = 75.00;

    CurrencyConverter converter(initialUsdToEuroRate, initialEuroToUsdRate, 
                                initialUsdToPakRate, initialUsdToIndRate);

    int choice;
    double amount;
    
    do{
        converter.displayExchangeRate();  // ✓ FIXED: converter (not convertor)
        cout << "\n\t******* Currency Converter Main Menu ********\n";
        cout << "1. Convert USD to Euro \n";
        cout << "2. Convert Euro to USD \n";
        cout << "3. Convert USD to Pakistani Rupee\n";
        cout << "4. Convert USD to Indian Rupee\n";
        cout << "0. Exit\n";
        cout << "Please Enter Your Choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter the Amount of USD: ";
                cin >> amount;
                cout << amount << " USD is Equivalent to " 
                     << converter.usdToEuro(amount) << " Euro\n";  // ✓ FIXED
                system("pause");
                break;
            case 2:
                cout << "Enter the Amount of Euro: ";
                cin >> amount;
                cout << amount << " Euro is Equivalent to " 
                     << converter.euroToUsd(amount) << " USD\n";  // ✓ FIXED
                system("pause");
                break;
            case 3:
                cout << "Enter the Amount of USD: ";
                cin >> amount;
                cout << amount << " USD is Equivalent to " 
                     << converter.usdToPakRupee(amount) << " Pakistani Rupee\n";  // ✓ FIXED
                system("pause");
                break;
            case 4:
                cout << "Enter the Amount of USD: ";
                cin >> amount;
                cout << amount << " USD is Equivalent to " 
                     << converter.usdToIndRupee(amount) << " Indian Rupee\n";  // ✓ FIXED
                system("pause");
                break;
            case 0:
                cout << "Program End\n";
                break;
            default:
                cout << "Please Enter Valid Number\n";
                system("pause");
        }

    } while(choice != 0);
    
    return 0;  // ✓ Good practice
}