#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

std::string res(int val){ if(val > 1) return " Attempts "; else return " Attempt ";}

template <typename T>
int Login(){

    T passwd = "admin@123";
    T user = "admin";
    T pass;
    T username;
    int passcount = 5;

while(1){
    system("cls");
    std::cout << std::endl;
    std::cout << std::setw(75) <<"To Access Parking Management System" << std::endl;
    std::cout << std::setw(74) <<"Log In With Admin Credentials !!" << std::endl << std::endl;

    std::cout << std::setw(45) << "Enter User ID -> ";
    std::cin >> username;
    std::cout << std::setw(45) << "Enter Password -> ";
    std::cin >> pass;

    std::cout << std::endl;

    if(username == user && passwd == pass) { //comparing user-name and Password
        return 1;
    } else{
        passcount--;

    if(passcount == 0){
        system("Color 04");
        std::cout << std::endl << std::setw(77) << "Too Many Wrong Attempts Done!!!!" << std::endl;
        std::cout << std::setw(68) << "Access Denied" << std::endl;
        return 0;
    }else{
        if(passcount == 1){
            system("Color 06");
            std::cout << std::setw(46) << passcount << res(passcount) << "Remaining...." << std::endl ;
            std::cout << std::setw(70) << " Last Chance... Good Bye...." << std::endl;
            system("pause");
        }else{
            std::cout << std::setw(46) << passcount << res(passcount) << "Remaining...." << std::endl ;
            system("pause");
        }

    }

    }//outer else

}//end while


}//end Login
