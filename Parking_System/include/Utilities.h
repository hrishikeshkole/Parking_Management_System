#ifndef Util_H
#define Util_H

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <vector>
#include "Parking.h"
#include "Four_Wheel.h"
#include "Transport_Wheel.h"
#include "Two_Wheel.h"

//Parking p;
//std::vector<Four_Wheel> vt1;

//For Four wheel
void addFourWheel(std::vector<Four_Wheel> &v);
void checkFourWheelSerial(std::vector<Four_Wheel> &v);
void acceptFourWheelPayment(std::vector<Four_Wheel> &v);

//For Two wheel
void addTwoWheel(std::vector<Two_Wheel> &v);
void checkTwoWheelSerial(std::vector<Two_Wheel> &v);
void acceptTwoWheelPayment(std::vector<Two_Wheel> &v);

//For Three wheel
void addThreeWheel(std::vector<Three_Wheel> &v);
void checkThreeWheelSerial(std::vector<Three_Wheel> &v);
void acceptThreeWheelPayment(std::vector<Three_Wheel> &v);

//For Transport wheel
void addTransportWheel(std::vector<Transport_Wheel> &v);
void checkTransportWheelSerial(std::vector<Transport_Wheel> &v);
void acceptTransportWheelPayment(std::vector<Transport_Wheel> &v);


int vehicleSelection(){
    system("cls");
    std::cout << std::endl;
    int ch;
    std::cout << std::setw(20) <<"1. Four Wheeler" << std::endl;
    std::cout << std::setw(19) <<"2. Two Wheeler" << std::endl;
    std::cout << std::setw(21) <<"3. Three Wheeler" << std::endl;
    std::cout << std::setw(25) <<"4. Transport Vehicle" << std::endl;
    std::cout << std::setw(26) << std::endl <<"Select Vehicle Type - " ;
    std::cin >> ch;
    return ch;
}//end vehicleSelection


void addFourWheel(std::vector<Four_Wheel> &v){

    std::string number;
    std::string name;

    std::cout << std::setw(98) << std::endl <<"Vehicle No. Guide <STATE>space<DISTRICT_CODE>space<Series>space<REG_NO> eg. - MH 09 EW 2325" << std::endl;
    std::cout << std::setw(30) << "Enter Vehicle Number - ";
    std::cin.ignore();
    std::getline(std::cin,number);

    std::cout << std::endl << std::setw(44) << "Vehicle Name Guide eg. - Suzuki Swift" << std::endl;
    std::cout << std::setw(28) << "Enter Vehicle Name - ";
    std::getline(std::cin,name);
    std::cout << std::endl;

    v.push_back(Four_Wheel{name,number});

    v.back().Park_in_FourWheel();

    std::cout << std::endl;
    std::cout << std::setw(50) << "Parking Granted...." << std::endl;
    std::cout << std::setw(58) << "Vehicle Parked Successfully.... " << std::endl;

    system("pause");
}//end addFourWheel

void checkFourWheelSerial(std::vector<Four_Wheel> &v){
    bool val {false};
    std::string number;
    std::cout << std::setw(98) << std::endl <<"Vehicle No. Guide <STATE>space<DISTRICT_CODE>space<Series>space<REG_NO> eg. - MH 09 EW 2325" << std::endl;
    std::cout << std::setw(30) << "Enter Vehicle Number - ";
    std::cin.ignore();
    std::getline(std::cin,number);

for(auto &vec: v){

    if(number == vec.getvehicle_num()){
        std::cout << "-----------------------------------" << std::endl;
        std::cout << std::setw(15) << "Vehicle Name" << std::setw(20) << "Vehicle Number" << std::endl;
        std::cout << "-----------------------------------" << std::endl << std::endl;
        std::cout << std::setw(15) << vec.getvehicle_name() << std::setw(20) << vec.getvehicle_num() << std::endl << std::endl;
        std::cout << std::setw(27) << "Vehicle is Present" << std::endl;
        std::cout << std::setw(27) << "in the Parking.." << std::endl;
        std::cout << "-----------------------------------" << std::endl << std::endl;
            val = true;
            break;
        }//end if
    }//end for

    if(!val)
    std::cout << std::setw(80) << "The vehicle is Not Present in the Parking.........." << std::endl;

}//end checkFourWheelSerial

void acceptFourWheelPayment(std::vector<Four_Wheel> &v){
     int i {-1}; bool found{false};
     std::string number;
     std::cout << std::setw(98) << std::endl <<"Vehicle No. Guide <STATE>space<DISTRICT_CODE>space<Series>space<REG_NO> eg. - MH 09 EW 2325" << std::endl;
     std::cout << std::setw(30) << "Enter Vehicle Number - ";
     std::cin.ignore();
     std::getline(std::cin,number);
     std::cout << std::endl;

    for(auto &vec: v){
        i++;
    if(number == vec.getvehicle_num()){
        found = true;
        vec.Park_out_FourWheel();
        vec.Parking_Charge();
        std::cout << std::setw(30) << std::right << "Payment Received...." << std::endl;
        std::cout << std::setw(30) << std::right << "Car Parked Out......" << std::endl;
        v.erase(v.begin() + i);
        system("pause");
        break;
    }//end if

    }//end for

    if(!found){
        std::cout << std::setw(70) << std::endl << "Vehicle is not present in the parking......" << std::endl << std::endl;
        system("pause");
    }
}//end acceptFourWheelPayment

void addTwoWheel(std::vector<Two_Wheel> &v){

    std::string number;
    std::string name;

    std::cout << std::setw(98) << std::endl <<"Vehicle No. Guide <STATE>space<DISTRICT_CODE>space<Series>space<REG_NO> eg. - MH 09 EW 2325" << std::endl;
    std::cout << std::setw(30) << "Enter Vehicle Number - ";
    std::cin.ignore();
    std::getline(std::cin,number);

    std::cout << std::endl << std::setw(44) << "Vehicle Name Guide eg. - Suzuki Swift" << std::endl;
    std::cout << std::setw(28) << "Enter Vehicle Name - ";
    std::getline(std::cin,name);
    std::cout << std::endl;

    v.push_back(Two_Wheel{name,number});

    v.back().Park_in_TwoWheel();

    std::cout << std::endl;
    std::cout << std::setw(50) << "Parking Granted...." << std::endl;
    std::cout << std::setw(58) << "Vehicle Parked Successfully.... " << std::endl;

    system("pause");
}//end addTwoWheel

void checkTwoWheelSerial(std::vector<Two_Wheel> &v){
    bool val {false};
    std::string number;
    std::cout << std::setw(98) << std::endl <<"Vehicle No. Guide <STATE>space<DISTRICT_CODE>space<Series>space<REG_NO> eg. - MH 09 EW 2325" << std::endl;
    std::cout << std::setw(30) << "Enter Vehicle Number - ";
    std::cin.ignore();
    std::getline(std::cin,number);

for(auto &vec: v){

    if(number == vec.getvehicle_num()){
        std::cout << "-----------------------------------" << std::endl;
        std::cout << std::setw(15) << "Vehicle Name" << std::setw(20) << "Vehicle Number" << std::endl;
        std::cout << "-----------------------------------" << std::endl << std::endl;
        std::cout << std::setw(15) << vec.getvehicle_name() << std::setw(20) << vec.getvehicle_num() << std::endl << std::endl;
        std::cout << std::setw(27) << "Vehicle is Present" << std::endl;
        std::cout << std::setw(27) << "in the Parking.." << std::endl;
        std::cout << "-----------------------------------" << std::endl << std::endl;
            val = true;
            break;
        }//end if
    }//end for

    if(!val)
    std::cout << std::setw(80) << "The vehicle is Not Present in the Parking.........." << std::endl;

}//end checkTwoWheelSerial

void acceptTwoWheelPayment(std::vector<Two_Wheel> &v){
     int i {-1}; bool found{false};
     std::string number;
     std::cout << std::setw(98) << std::endl <<"Vehicle No. Guide <STATE>space<DISTRICT_CODE>space<Series>space<REG_NO> eg. - MH 09 EW 2325" << std::endl;
     std::cout << std::setw(30) << "Enter Vehicle Number - ";
     std::cin.ignore();
     std::getline(std::cin,number);
     std::cout << std::endl;

    for(auto &vec: v){
        i++;
    if(number == vec.getvehicle_num()){
        found = true;
        vec.Park_out_TwoWheel();
        vec.Parking_Charge();
        std::cout << std::setw(30) << std::right << "Payment Received...." << std::endl;
        std::cout << std::setw(30) << std::right << "Car Parked Out......" << std::endl;
        v.erase(v.begin() + i);
        system("pause");
        break;
    }//end if

    }//end for

    if(!found){
        std::cout << std::setw(70) << std::endl << "Vehicle is not present in the parking......" << std::endl << std::endl;
        system("pause");
    }
}//end acceptTwoWheelPayment

void addThreeWheel(std::vector<Three_Wheel> &v){

    std::string number;
    std::string name;

    std::cout << std::setw(98) << std::endl <<"Vehicle No. Guide <STATE>space<DISTRICT_CODE>space<Series>space<REG_NO> eg. - MH 09 EW 2325" << std::endl;
    std::cout << std::setw(30) << "Enter Vehicle Number - ";
    std::cin.ignore();
    std::getline(std::cin,number);

    std::cout << std::endl << std::setw(44) << "Vehicle Name Guide eg. - Suzuki Swift" << std::endl;
    std::cout << std::setw(28) << "Enter Vehicle Name - ";
    std::getline(std::cin,name);
    std::cout << std::endl;

    v.push_back(Three_Wheel{name,number});

    v.back().Park_in_ThreeWheel();

    std::cout << std::endl;
    std::cout << std::setw(50) << "Parking Granted...." << std::endl;
    std::cout << std::setw(58) << "Vehicle Parked Successfully.... " << std::endl;

    system("pause");
}//end addThreeWheel

void checkThreeWheelSerial(std::vector<Three_Wheel> &v){
    bool val {false};
    std::string number;
    std::cout << std::setw(98) << std::endl <<"Vehicle No. Guide <STATE>space<DISTRICT_CODE>space<Series>space<REG_NO> eg. - MH 09 EW 2325" << std::endl;
    std::cout << std::setw(30) << "Enter Vehicle Number - ";
    std::cin.ignore();
    std::getline(std::cin,number);

for(auto &vec: v){

    if(number == vec.getvehicle_num()){
        std::cout << "-----------------------------------" << std::endl;
        std::cout << std::setw(15) << "Vehicle Name" << std::setw(20) << "Vehicle Number" << std::endl;
        std::cout << "-----------------------------------" << std::endl << std::endl;
        std::cout << std::setw(15) << vec.getvehicle_name() << std::setw(20) << vec.getvehicle_num() << std::endl << std::endl;
        std::cout << std::setw(27) << "Vehicle is Present" << std::endl;
        std::cout << std::setw(27) << "in the Parking.." << std::endl;
        std::cout << "-----------------------------------" << std::endl << std::endl;
            val = true;
            break;
        }//end if
    }//end for

    if(!val)
    std::cout << std::setw(80) << "The vehicle is Not Present in the Parking.........." << std::endl;

}//end checkThreeWheelSerial

void acceptThreeWheelPayment(std::vector<Three_Wheel> &v){
     int i {-1}; bool found{false};
     std::string number;
     std::cout << std::setw(98) << std::endl <<"Vehicle No. Guide <STATE>space<DISTRICT_CODE>space<Series>space<REG_NO> eg. - MH 09 EW 2325" << std::endl;
     std::cout << std::setw(30) << "Enter Vehicle Number - ";
     std::cin.ignore();
     std::getline(std::cin,number);
     std::cout << std::endl;

    for(auto &vec: v){
        i++;
    if(number == vec.getvehicle_num()){
        found = true;
        vec.Park_out_ThreeWheel();
        vec.Parking_Charge();
        std::cout << std::setw(30) << std::right << "Payment Received...." << std::endl;
        std::cout << std::setw(30) << std::right << "Car Parked Out......" << std::endl;
        v.erase(v.begin() + i);
        system("pause");
        break;
    }//end if

    }//end for

    if(!found){
        std::cout << std::setw(70) << std::endl << "Vehicle is not present in the parking......" << std::endl << std::endl;
        system("pause");
    }
}//end acceptThreeWheelPayment

void addTransportWheel(std::vector<Transport_Wheel> &v){

    std::string number;
    std::string name;

    std::cout << std::setw(98) << std::endl <<"Vehicle No. Guide <STATE>space<DISTRICT_CODE>space<Series>space<REG_NO> eg. - MH 09 EW 2325" << std::endl;
    std::cout << std::setw(30) << "Enter Vehicle Number - ";
    std::cin.ignore();
    std::getline(std::cin,number);

    std::cout << std::endl << std::setw(44) << "Vehicle Name Guide eg. - Suzuki Swift" << std::endl;
    std::cout << std::setw(28) << "Enter Vehicle Name - ";
    std::getline(std::cin,name);
    std::cout << std::endl;

    v.push_back(Transport_Wheel{name,number});

    v.back().Park_in_TransportWheel();

    std::cout << std::endl;
    std::cout << std::setw(50) << "Parking Granted...." << std::endl;
    std::cout << std::setw(58) << "Vehicle Parked Successfully.... " << std::endl;

    system("pause");
}//end addTransportWheel

void checkTransportWheelSerial(std::vector<Transport_Wheel> &v){
    bool val {false};
    std::string number;
    std::cout << std::setw(98) << std::endl <<"Vehicle No. Guide <STATE>space<DISTRICT_CODE>space<Series>space<REG_NO> eg. - MH 09 EW 2325" << std::endl;
    std::cout << std::setw(30) << "Enter Vehicle Number - ";
    std::cin.ignore();
    std::getline(std::cin,number);

for(auto &vec: v){

    if(number == vec.getvehicle_num()){
        std::cout << "-----------------------------------" << std::endl;
        std::cout << std::setw(15) << "Vehicle Name" << std::setw(20) << "Vehicle Number" << std::endl;
        std::cout << "-----------------------------------" << std::endl << std::endl;
        std::cout << std::setw(15) << vec.getvehicle_name() << std::setw(20) << vec.getvehicle_num() << std::endl << std::endl;
        std::cout << std::setw(27) << "Vehicle is Present" << std::endl;
        std::cout << std::setw(27) << "in the Parking.." << std::endl;
        std::cout << "-----------------------------------" << std::endl << std::endl;
            val = true;
            break;
        }//end if
    }//end for

    if(!val)
    std::cout << std::setw(80) << "The vehicle is Not Present in the Parking.........." << std::endl;

}//end checkTransportWheelSerial

void acceptTransportWheelPayment(std::vector<Transport_Wheel> &v){
     int i {-1}; bool found{false};
     std::string number;
     std::cout << std::setw(98) << std::endl <<"Vehicle No. Guide <STATE>space<DISTRICT_CODE>space<Series>space<REG_NO> eg. - MH 09 EW 2325" << std::endl;
     std::cout << std::setw(30) << "Enter Vehicle Number - ";
     std::cin.ignore();
     std::getline(std::cin,number);
     std::cout << std::endl;

    for(auto &vec: v){
        i++;
    if(number == vec.getvehicle_num()){
        found = true;
        vec.Park_out_TransportWheel();
        vec.Parking_Charge();
        std::cout << std::setw(30) << std::right << "Payment Received...." << std::endl;
        std::cout << std::setw(30) << std::right << "Car Parked Out......" << std::endl;
        v.erase(v.begin() + i);
        system("pause");
        break;
    }//end if

    }//end for

    if(!found){
        std::cout << std::setw(70) << std::endl << "Vehicle is not present in the parking......" << std::endl << std::endl;
        system("pause");
    }
}//end acceptTransportWheelPayment

#endif //Util_H
