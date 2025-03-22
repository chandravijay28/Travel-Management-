#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>

using namespace std;

void menu();

class ManageMenu {
protected:
    string username;
public: 
    ManageMenu()
    {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\t Enter Your Name : ";
        cin >> username;
        system("CLS");
        menu();
    }
    ~ManageMenu(){}
};

class Customers {
public:
    string name,gender,address;
    int age, mobileNo;
    static int CustomerID;
    char all[999];

    void getDetails() {
        ofstream out("old-customer.txt",ios::app);
        {
            cout << "Enter CustomerID: ";
            cin >> CustomerID;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter MobileNo.: ";
            cin >> mobileNo;
            cout << "Enter address: ";
            cin >> address;
            cout << "Enter Gender: ";
            cin >> gender;
        }
        out << "\nCustomer ID: " << CustomerID << "\name: " << name << "\
        age: " << age << "\nMobileNo.: " << mobileNo << "\nAddress:" << address << "\nGender: " << gender;
        out.close();
        cout << "\nSAVED \nNOTE: Customer ID is unique for each customer.";
    }
    void showDetails() {
        ifstream in("old-customer.txt");
        {
            if(!in) {
                cout << "File Error!" << endl;
            }
            while(!(in.eof())) {
                in.getline(all,999);
                cout << all << endl;
            }
            in.close();
        }
    }
};

int Customers :: CustomerID;

class Cabs {
public:
    int cabChoice;
    int kilometers;
    float cabCost;
    static float lastcabCost;

    void cabDetails() {
        cout << "We Collaborate with fastest, safest and most reliable cabs in the city." << endl;
        cout << "-----------ABC Cabs-----------\n" << endl;
        cout << "1. Rent a Standard Cab Rs.10 for 1km " << endl;
        cout << "2. Rent a Luxury Cab Rs.17 for 1km " << endl;

        cout << "\nTo Calculate the cost for your journey: " << endl;
        cout << "Enter which kind of Cab you need: " << endl;
        cin >> cabChoice;
        cout << "Enter kilometers you have to travel: " << endl;
        cin >> kilometers;

        int hireCab;

        if(cabChoice == 1) {
            cabCost = kilometers*10;
            cout << "You have to pay Rs." << cabCost << " for your journey." << endl;
            cout << "Press 1 to hire a cab: OR";
            cout << "Press 2 to select another cab: ";
            cin >> hireCab;

            system("CLS");

            if(hireCab == 1) {
                lastcabCost = cabCost;
                cout << "\nYou have successfully hired a Standard cab." << endl;
                cout << "GoTo Menu and take the receipt" << endl;
            }
            else if(hireCab == 2) {
                cabDetails();
            }
            else {
                cout << "Invalid Input! Redirecting to previous menu \nPlease Wait!" << endl;
                Sleep(999);
                system("CLS");
                cabDetails();
            }
        }
        else if(cabChoice == 2) {
            cabCost = kilometers*17;
            cout << "You have to pay Rs." << cabCost << " for your journey." << endl;
            cout << "Press 1 to hire a cab: OR";
            cout << "Press 2 to select another cab: ";
            cin >> hireCab;

            system("CLS");

            if(hireCab == 1) {
                lastcabCost = cabCost;
                cout << "\nYou have successfully hired a Luxury cab." << endl;
                cout << "GoTo Menu and take the receipt" << endl;
            }
            else if(hireCab == 2) {
                cabDetails();
            }
            else {
                cout << "Invalid Input! Redirecting to previous menu \nPlease Wait!" << endl;
                Sleep(999);
                system("CLS");
                cabDetails();
            }
        }
        else {
            cout << "Invalid Input! Redirecting to Main menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "\nPress 1 to Redirect Main Menu: "; 
        cin >> hireCab;
        system("CLS");
        if(hireCab == 1) {
            menu();
        }
        else {
            menu();
        }
    }
};

class Booking {
public:
    int choiceHotel;
    int packChoice;
    static float hotelCost;

    void hotels() {
        string hotelNo[] = {"Hidden Heaven", "Mountain Pearls"};
        for(int i = 0;i<3;i++) {
            cout << (i+1) << ". Hotel" << hotelNo[i] << endl;
        }
        cout << "\nCurrently we collaborated with above Hotels!" << endl;
        cout << "Press any key to back or\nEnter number of hotel you want to book: ";
        cin >> choiceHotel;

        system("CLS");

        if(choiceHotel == 1) {
            cout << "----------------WELCOME TO HOTEL HIDDEN HEAVEN------------\n" << endl;
            cout << "The Garden, food and beverages. Enjoy all you can drink, Stay Cool and get chilled in the summer sum.\n" << endl;
            cout << "Packages offered by Hotel Hidden Heaven: \n" << endl;
            cout << "1. Standard Package: Rs. 5000/- per night\n" << endl;
            cout << "2. Deluxe Package: Rs. 8000/- per night\n" << endl;
            cout << "3. Suite Package: Rs. 12000/- per night\n" << endl;

            cout << "\nPress  another key to back or\nEnter number of package you want to book: ";
            cin >> packChoice;

            if(packChoice == 1) {
                hotelCost = 5000;
                cout << "\nYou have successfully booked Standard Package at Hotel Hidden Heaven for Rs. 5000/- per night.\n" << endl;
                cout << "GoTo Menu and take the receipt" << endl;
            }
            else if(packChoice == 2) {
                hotelCost = 10000;
                cout << "\nYou have successfully booked Deloxe Package at Hotel Hidden Heaven for Rs. 8000/- per night.\n" << endl;
                cout << "GoTo Menu and take the receipt" << endl;
            }
            else if(packChoice == 3) {
                hotelCost = 12000;
                cout << "\nYou have successfully booked Luxury Package at Hotel Hidden Heaven for Rs. 5000/- per night.\n" << endl;
                cout << "GoTo Menu and take the receipt" << endl;
            }
            else {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            int gotomenu;
            cout << "\nPress 1 to redirect main menu: ";
            cin >> gotomenu;
            if (gotomenu == 1){   
                menu();
            }
            else {
                menu();
            }
        }
        else if(choiceHotel == 2) {
            cout << "----------------WELCOME TO HOTEL HIDDEN HEAVEN------------\n" << endl;
            cout << "The Garden, food and beverages. Enjoy all you can drink, Stay Cool and get chilled in the summer sum.\n" << endl;
            cout << "Packages offered by Hotel Hidden Heaven: \n" << endl;
            cout << "1. Standard Package: Rs. 5000/- per night\n" << endl;
            cout << "2. Deluxe Package: Rs. 8000/- per night\n" << endl;
            cout << "3. Suite Package: Rs. 12000/- per night\n" << endl;

            cout << "\nPress  another key to back or\nEnter number of package you want to book: ";
            cin >> packChoice;

            if(packChoice == 1) {
                hotelCost = 5000;
                cout << "\nYou have successfully booked Standard Package at Hotel Hidden Heaven for Rs. 5000/- per night.\n" << endl;
                cout << "GoTo Menu and take the receipt" << endl;
            }
            else if(packChoice == 2) {
                hotelCost = 10000;
                cout << "\nYou have successfully booked Deloxe Package at Hotel Hidden Heaven for Rs. 8000/- per night.\n" << endl;
                cout << "GoTo Menu and take the receipt" << endl;
            }
            else if(packChoice == 3) {
                hotelCost = 12000;
                cout << "\nYou have successfully booked Luxury Package at Hotel Hidden Heaven for Rs. 5000/- per night.\n" << endl;
                cout << "GoTo Menu and take the receipt" << endl;
            }
            else {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            int gotomenu;
            cout << "\nPress 1 to redirect main menu: ";
            cin >> gotomenu;
            if (gotomenu == 1){   
                menu();
            }
            else {
                menu();
            }
        }
    }
};

float Cabs :: lastcabCost;
float Booking :: hotelCost;

class Charges : public Booking,Cabs,Customers {
public:
    void printBill() {
        ofstream outf("receipt.txt");
        {
            outf << "--------------ABC Travel Agency-----------------" << endl;
            outf << "------------------Receipt------------------" << endl;
            outf << "Customer ID: " << Customers :: CustomerID << endl << endl; 
            outf << "Description\t\t Total" << endl;
            outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
            outf << "Travel (Cab) cost:\t " << fixed << setprecision(2) << Cabs::lastcabCost << endl;
            outf << "______________________________________________" << endl;
            outf << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::hotelCost+Cabs::lastcabCost << endl;
            outf << "______________________________________________" << endl;
            outf << "Thank you for choosing ABC Travel Agency!" << endl;
        } 
        outf.close();
    }
    void showBill() {
        ifstream inf("receipt.txt");
        {
            if(!inf) {
                cout << "File opening error!" << endl;
            }
            while(!(inf.eof()))
            {
                inf.getline(all,999);
                cout << all << endl;
            }
        }
        inf.close();
    }
};

void menu() {

    int mainChoice;
    int inChoice;
    int gotomenu;

    cout << "\t\t          ABC Travel Agency             \n" << endl;
    cout << "---------------------Main Menu-----------------------" << endl;
    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\tCabs Management     -> 2\t|" << endl;
    cout << "\t|\tBooking Management  -> 3\t|" << endl;
    cout << "\t|\tCharges & Bill      -> 4\t|" << endl;
    cout << "\t|\tExit                -> 5\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\nEnter Your Choice: ";
    cin >> mainChoice;

    system("CLS");

    Customers a2;
    Cabs a3;
    Booking a4;
    Charges a5;

    if(mainChoice == 1) {
        cout << "-------Customers------\n" << endl;
        cout << "1. Enter New Customer" << endl;
        cout << "2. See Old Customers" << endl;

        cout << "\nEnter Choice: ";
        cin >> inChoice;

        system("CLS");
        if(inChoice == 1) {
            a2.getDetails();
        }
        else if(inChoice == 2) {
            a2.showDetails();
        }
        else {
            cout << "Invalid Choice" << endl;
            Sleep(1100);
            system("CLS");
            menu(); 
        }
        cout << "\nPress 1 to Redirect main menu: ";
        cin >> gotomenu;
        system("CLS");
        if(gotomenu == 1) {
            menu();
        }
        else {
            menu();
        }
    }
    else if(mainChoice == 2) {
        a3.cabDetails();
    }
    else if(mainChoice == 3) {
        cout << "--> Book a loxury Hotel using the system <--" << endl;
        a4.hotels();
    }
    else if(mainChoice == 4) {
        cout << "-->Get Your Receipt <--";
        a5.printBill();

        cout << "Your receipt is already printed you can get it from file path\n" << endl;
        cout << "to display your receipt in the screen, Enter 1: or Enter another key to back main menu; ";

        cin >> gotomenu;

        if(gotomenu == 1) {
            system("CLS");
            a5.showBill();
            cout << "\nPress 1 to redirect main menu: ";
            cin >> gotomenu;
            system("CLS");
            if (gotomenu == 1){
                menu();
            }
            else {
                menu();
            }
        }
        else {
            system("CLS");
            menu();
        }
    }
    else if(mainChoice == 5) {
        cout << "--> Exit the system <--" << endl;
        Sleep(999);
        system("CLS");
        menu();
    }
    else {
        cout << "Invalid Input! Redirecting to Previous Menu" << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
}

int main() {
    ManageMenu startObj;
    return 0;
}