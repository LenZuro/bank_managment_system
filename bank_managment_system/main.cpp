//
//  main.cpp
//  bank_managment_system
//
//  Created by Len Zuro on 1/15/24.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

class temp {
    int accountNum;
    char name[25];
    char Lname[25];
    char nicName[25];
    char P_no[25];
    char email[100];
    float amount;
    int newAmount;
    std::fstream file,file1;
    
    public : int search;

    // Function Declarations

    void createAccount(void);
    void depositAmount(void);
    void withdrawAmount(void);
    void checkInfo(void);
    
};

int main(){
    temp obj;
    char choice;
    std::cout << "\n\n\n\t\t....::::Dark Matter Bank::::....";
    std::cout << "\n\t\t :: press 1 to Login              :: ";
    std::cout << "\n\t\t :: press 2 to Create a Account   :: ";
    std::cout << "\n\t\t :: press 0 to Exit               :: ";
    std::cout << "\n\t\t :: ............................. ::\n\t\t\t\t";
    std::cin >> choice;
    
    switch (choice) {
        case '1':
            std::cout << "Enter your Account Number :: ";
                std::cin >> obj.search;
            while(1){
                
                std::cout <<"\n\n\n\t\t ....:::: User's Account::::....";
                std::cout << "\n\t\t:: Press 1 to Deposit    :: ";
                std::cout << "\n\t\t:: Press 2 to Withdraw   :: ";
                std::cout << "\n\t\t:: Press 3 to Check Info :: ";
                std::cout << "\n\t\t:: Press 0 to Exit       :: ";
                std::cout << "\n\t\t........................ ::\n\t\t\t\t";
                std::cin >> choice;
                
                switch (choice) {
                    case '1' :
                        obj.depositAmount();
                        break;
                    case '2' :
                        obj.withdrawAmount();
                        break;
                    case '3' :
                        obj.checkInfo();
                        break;
                    case '0' :
                        return 0;
                        break;
                    default :
                        std::cout << "Invaild Choice.......";
                        break;
                }
                system("pause");
                system("cls");
            }
            break;
        case '2' :
            obj.createAccount();
            break;
        case '0' :
            system("exit");
            break;
        default :
            std::cout << "Invaild Choice........";
            break;
    }
    return 0;
}

void temp :: createAccount() {
    accountNum = rand()*rand()+rand()*rand();
    std::cout << "Please Enter Your Name :: ";
    std::cin >> name;
    std::cout << "Enter Your Last Name :: ";
    std::cin >> Lname;
    std::cout << "Enter your Nic Name :: ";
    std::cin >> nicName;
    std::cout << "Enter your Phone Number :: ";
    std::cin >> P_no;
    std::cout << "Enter your Eamil :: ";
    std::cin >> email;
    std::cout << "Enter Current Cash Amount :: ";
    std::cin >> amount;
    std::cout << std::endl << accountNum << " This is your account number.... \n";
    std::cout << "Save this in a secure way.... \n\n";
    
    file.open("data.txt" , std::ios::out|std::ios::app);
    file << accountNum << "\t" << name << "\t" << Lname << "\t" << nicName << "\t" << P_no << "\t" << email << "\t" << amount << std::endl;
    file.close();
}

void temp :: depositAmount() {
    std::cout << "Enter the amount you would like to deposit ::";
    std::cin >> newAmount;
    
    file.open("data.txt" , std::ios::in);
    file1.open("data1.txt" , std::ios::out | std::ios::app);
    file >> accountNum >> name >> Lname >> nicName >> P_no >> email >> amount;
    
    while (!file.eof()) {
        if(accountNum == search) {
            std::cout << "\nCurrent Balance Amount :: " << amount;
            amount = amount + newAmount;
            std::cout << "\nTotal Updated Balcance :: " << amount << std::endl;
            file1 << accountNum << "\t" << name << "\t" << Lname << "\t" << nicName << "\t" << P_no << "\t" << email << "\t" << amount<< std::endl;
        }else{
            file1 << accountNum << "\t" << name << "\t" << Lname << "\t" << nicName << "\t" << P_no << "\t" << email << "\t" << amount<< std::endl;
        }
        file >> accountNum >> name >> Lname >> nicName >> P_no >> email >> amount;
    }
    file.close();
    file1.close();
    remove("data.txt");
    rename("data1.txt" , "data.txt");
}

void temp :: withdrawAmount() {
    std::cout << "Enter the amount you would like to withdraw ::";
    std::cin >> newAmount;
    
    file.open("data.txt" , std::ios::in);
    file1.open("data1.txt" , std::ios::out | std::ios::app);
    file >> accountNum >> name >> Lname >> nicName >> P_no >> email >> amount;
    
    while (!file.eof()) {
        if(accountNum == search) {
            std::cout << "\nCurrent Balance Amount :: " << amount;
            amount = amount - newAmount;
            std::cout << "\nTotal Updated Balcance :: " << amount << std::endl;
            file1 << accountNum << "\t" << name << "\t" << Lname << "\t" << nicName << "\t" << P_no << "\t" << email << "\t" << amount<< std::endl;
        }else{
            file1 << accountNum << "\t" << name << "\t" << Lname << "\t" << nicName << "\t" << P_no << "\t" << email << "\t" << amount<< std::endl;
        }
        file >> accountNum >> name >> Lname >> nicName >> P_no >> email >> amount;
    }
    file.close();
    file1.close();
    remove("data.txt");
    rename("data1.txt" , "data.txt");
}

void temp :: checkInfo() {
    std::fstream file;
    file.open("data.txt" , std::ios::in);
    if(!file){
        std::cout << "Error Opening File! ";
    }
    file >> accountNum >> name >> Lname >> nicName >> P_no >> email >> amount;
    while(!file.eof()){
            if(accountNum == search){
                std::cout << "\n---------------------------\n";
                std::cout << std::endl << "\t::: account Number ::: ";
                std::cout << "\t   " << accountNum <<std::endl;
                std::cout << "\t::: User Name      ::: ";
                std::cout << "\t   "<< name << "\n";
                std::cout << "\t::: Father Name    ::: ";
                std::cout << "\t   "<< Lname << "\n";
                std::cout << "\t::: CNIC number    ::: ";
                std::cout << "\t   " << nicName << "\n";
                std::cout << "\t::: Phone Number   ::: ";
                std::cout << "\t   " << P_no << "\n";
                std::cout << "\t::: Email          ::: ";
                std::cout << "\t   " << email << "\n";
                std::cout << "\t::: Current amount ::: ";
                std::cout << "\t   " << amount << std::endl;
                std::cout << "\n---------------------------\n\n";
            
            }
            file>>accountNum>>name>>Lname>>nicName>>P_no>>email>>amount;
        }
        
        file.close();
}
