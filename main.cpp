#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Struct to store customer information
struct ConcertInfo {
    string cusname;
    int phonenum;
    int numtickets;
    string email;
    char sit;
};

void interface()
{
    cout << "\t\t\t\t\t\t\tLIVE CONCERT\n" << endl;	
    cout << "\t\t\t\t\t\t\tTHE WEEKEND\n" << endl;	   
    cout << "\t\t\t\t\t\t\tAT JASIN\n" << endl;	
    cout << "\t\t\t\t\t\tdate: 16 SEPTEMBER 2023\n" << endl;	    
    cout << "\t\t\t\t-------------------------------------------------------" << endl;
    cout << "\t\t\t\t|                 Welcome to our ticket               |" << endl;
    cout << "\t\t\t\t|                 concert registration                |" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t|                  Please follow all the              |" << endl;
    cout << "\t\t\t\t|                  instruction provided               |" << endl;
    cout << "\t\t\t\t|                       Thanks you !                  |" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t-------------------------------------------------------" << endl;
    cout << "\t\t\t\t|                      SEAT OPTION                    |" << endl;
    cout << "\t\t\t\t|                                                     |" << endl;
    cout << "\t\t\t\t|               Sit A - Premium - RM 50               |" << endl;
    cout << "\t\t\t\t|               Sit B - Medium - RM 35                |" << endl;
    cout << "\t\t\t\t|               Sit C - Budget - RM 20                |" << endl;
    cout << "\t\t\t\t-------------------------------------------------------" << endl;
    cout <<"\t\nPlease press enter to continue purchasing the ticket."<< endl;
}

int totalPrice(ConcertInfo customers[], int size, ofstream& outputFile2) {
    int totalBuy = 0;

    for (int i = 0; i < size; i++) {
        if (customers[i].sit == 'A' || customers[i].sit == 'a')
            totalBuy += customers[i].numtickets * 50;
        else if (customers[i].sit == 'B' || customers[i].sit == 'b')
            totalBuy += customers[i].numtickets * 35; // Changed from 30 to 35
        else if (customers[i].sit == 'C' || customers[i].sit == 'c')
            totalBuy += customers[i].numtickets * 20; // Changed from 25 to 20
        else {
            outputFile2 << "\t\tSorry, wrong seat code.\t\t\n";
            outputFile2 << "\t\tPlease enter again.\t\t\n";
           	outputFile2 << "\n***********************************************************" << endl ;
            return -1;
        }
    }

    return totalBuy;
}

// Stage function (file)
void displaystage() {
    ifstream infile;
    infile.open("stage.txt");
    string display;

    while (!infile.eof()) {
    	getline(infile,display);
        cout << display << endl;
    }
    system("pause");
    infile.close();
}

int main() {
    // Interface
    interface();
    cin.get();
    system("CLS");

    //Display Stages txt
    char stages;
    cout << "Do you want to view the stage layout (Y/N)? " << endl;
    cin >> stages;
    cin.ignore(); // Ignore the newline character

    if (stages == 'Y' || stages == 'y') {
        displaystage();
    }
    
    system("CLS");

    // Continue or not
    char cont;

    do {
        ofstream outputFile("customerInfo.txt", ios::app); // Open the file in append mode
        ofstream outputFile2("receipt.txt", ios::app); // Open the file in append mode

        if (!outputFile.is_open() || !outputFile2.is_open()) {
            cout << "Failed to open the file." << endl;
            return 1;
        }

        const int arraySize = 1; // Size of the struct array
        ConcertInfo customers[arraySize];

        // Get user input for each customer
        for (int i = 0; i < arraySize; i++) {
            cout << "Enter customer name: ";
            getline(cin, customers[i].cusname);

            cout << "Enter customer phone number: ";
            cin >> customers[i].phonenum;
            cin.ignore();

            cout << "Enter how many tickets want to buy: ";
            cin >> customers[i].numtickets;
            cin.ignore();

            cout << "Enter customer email: ";
            getline(cin, customers[i].email);

            cout << "Enter seat type (A/B/C): ";
            cin >> customers[i].sit;
            cin.ignore();
        }

        // Write data to the file for each customer
        for (int i = 0; i < arraySize; i++) {
            outputFile << "\t\t\t  Customer Info\n\n\n" << endl;
        	outputFile << "___________________________________________________________" << endl ;
            outputFile << "Customer Name: " << customers[i].cusname << endl;
            outputFile << "Phone Number: " << customers[i].phonenum << endl;
            outputFile << "Number of Tickets: " << customers[i].numtickets << endl;
            outputFile << "Email: " << customers[i].email << endl;
            outputFile << "Seat Type: " << customers[i].sit << endl;
        	outputFile << "___________________________________________________________" << endl ;
            outputFile << endl;
        }

        // Calculate total price and write it to the receipt file
        int total = totalPrice(customers, arraySize, outputFile2);

        for (int i = 0; i < arraySize; i++) {
            if (total != -1) {
                outputFile2 << "\t\t\t     CONCERT TICKET " << endl;
                outputFile2 << "\t\t\t   enjoy your concert!!!\n\n\n" << endl;
             	outputFile2 << "__________________________________________________________" << endl ; 
                outputFile2 << "Customer Name: " << customers[i].cusname << endl;
                outputFile2 << "Phone Number: " << customers[i].phonenum << endl;
                outputFile2 << "Email: " << customers[i].email << endl;
                outputFile2 << "Seat Type: " << customers[i].sit << endl;
                outputFile2 << "Number of ticket purchased: " << customers[i].numtickets << endl;
                outputFile2 << "Total Price: RM " << total << endl;
             	outputFile2 << "__________________________________________________________" << endl ; 
                outputFile2 << "\n\n\n Dear customer, thank you for your purchasing\n" << endl;
            	outputFile2 << "***********************************************************" << endl ;
            }
            outputFile2 << endl;
        }
        
        system("CLS");

        // Close the files
        outputFile.close();
        outputFile2.close();

        cout << "Do you want to continue (Y/N): ";
        cin >> cont;
        cin.ignore();

        system("CLS"); // Clear the console screen

    } while (cont == 'Y' || cont == 'y');

    cout << "Data has been written into our system." << endl;
    cout << "Your receipt will be generated soon." << endl;
    cout << "Enjoy your concert. Thank you!" << endl;

    return 0;
}
