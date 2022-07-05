#include <iostream>
#include <iomanip>
#include <windows.h>
#include <vector>
#include "Login_Module.h"
#include "Parking.h"
#include "Four_Wheel.h"
#include "Two_Wheel.h"
#include "Three_Wheel.h"
#include "Four_Wheel.h"
#include "Utilities.h"

using namespace std;

int main(void){

    int ch;

    Parking p;

    std::vector<Four_Wheel> vt1;
    std::vector<Two_Wheel> vt2;
    std::vector<Three_Wheel> vt3;
    std::vector<Transport_Wheel> vt4;

    if( Login<string>() ){

        while(1){
        system("cls");
        cout << setw(58) << endl <<"WELCOME TO" << endl;
        cout << setw (65) << "PARKING MANAGEMENT SYSTEM" << endl << endl;

        cout << setw(27) << "1. Add New Vehicle." << endl;
        cout << setw(44) << "2. Accept Payment / Release Vehicle." << endl;
        cout << setw(38) << "3. Display All Vehicle Status." << endl;
        cout << setw(42) << "4. Check Vehicles Using Serial No." << endl;
        cout << setw(34) << "5. Total Daily Collection." << endl;
        cout << setw(16) << "6. Exit." << endl;

        cout << setw(28) << endl << "Enter Your Choice - ";
        cin >> ch;

        switch(ch){

            case 1:{
                int choice = vehicleSelection();

                if(choice == 1){
                    if(vt1.size() < 20){
                        addFourWheel(vt1);
                    }else{
                        cout << endl << setw(25) << "Parking Full.." << endl << endl;
                        system("pause");
                    }//end if-else
                }else if(choice == 2){
                    if(vt2.size() < 30){
                        addTwoWheel(vt2);
                    }else{
                        cout << endl << setw(25) << "Parking Full.." << endl << endl;
                        system("pause");
                    }//end if-else
                }else if(choice == 3){
                    if(vt3.size() < 15){
                        addThreeWheel(vt3);
                    }else{
                        cout << endl << setw(25) << "Parking Full.." << endl << endl;
                        system("pause");
                    }//end if-else
                }else if(choice == 4){
                    if(vt4.size() < 10){
                        addTransportWheel(vt4);
                    }else{
                        cout << endl << setw(25) << "Parking Full.." << endl << endl;
                        system("pause");
                    }//end if-else
                }else{
                    cout << "Enter Correct Choice" << endl;
                    system("pause");
                }//end if else
            }//case 1 block
                break;

            case 2:{

                int choice = vehicleSelection();

                if(choice == 1){
                    acceptFourWheelPayment(vt1);
                }else if(choice == 2){
                    acceptTwoWheelPayment(vt2);
                }else if(choice == 3){
                    acceptThreeWheelPayment(vt3);
                }else if(choice == 4){
                    acceptTransportWheelPayment(vt4);
                }else{
                    cout << "Enter Correct Choice" << endl;
                    system("pause");
                }//end if else

            }//case 2 block
                break;

            case 3:{
                cout << endl << std::setw(30) << "Parking statistics" << endl;
                cout << "-----------------------------------" << endl;
                cout << setw(15) << "Vehicle Type" << setw(20) << "Vehicle Count" << endl;
                cout << "-----------------------------------" << endl;
                cout << setw(18) << "Four Wheelers - " << setw(14) << vt1.size()<< endl;
                cout << setw(17) << "Two Wheelers - " << setw(15) << vt2.size() << endl;
                cout << setw(19) << "Three Wheelers - " << setw(13) << vt3.size() << endl;
                cout << setw(23) << "Transport Vehicles - " << setw(9) << vt4.size() << endl;
                cout << "-----------------------------------" << endl;
                system("pause");
            }//case 3 block
                break;

            case 4:{
                int choice = vehicleSelection();

                if(choice == 1){
                    checkFourWheelSerial(vt1);
                    system("pause");
                }else if(choice == 2){
                    checkTwoWheelSerial(vt2);
                    system("pause");
                }else if(choice == 3){
                    checkThreeWheelSerial(vt3);
                    system("pause");
                }else if(choice == 4){
                    checkTransportWheelSerial(vt4);
                    system("pause");
                }else{
                    cout << "Enter Correct Choice" << endl;
                    system("pause");
                }//end if else
            }//case 4 block
                break;

            case 5:
                cout << setw(30)<< endl << "Total Daily Collection - " << p.gettotalcollection() << " Rs" << endl;
                system("pause");
                break;

            case 6:
                exit(1);
                system("pause");
                break;

            default :
                cout << "Enter Correct Choice" << endl;
                system("pause");
                break;
        }//end switch

       }//end while

    }else{
        exit(1);
    }// end if-else

    return 0;
}
