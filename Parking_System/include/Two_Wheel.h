#ifndef TWO_WHEEL_H
#define TWO_WHEEL_H


#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Parking.h"

//Parking Space 30

//Following Two Function are used to calculate time difference
int ConvertTimeToMinutes_TW(int,int,bool);
int ComputeTime_TW(int,int,int,int,bool,bool);

class Two_Wheel: public Parking {
    private:
        std::string v_name;
        std::string v_num;
    public:
        Two_Wheel(std::string vname, std::string vnum); //Parameterized Ctor;
        void Park_in_TwoWheel();
        void Park_out_TwoWheel();
        void Parking_Charge();
        std::string getvehicle_name();
        std::string getvehicle_num();

        ~Two_Wheel(); //destructor
};

#endif // TWO_WHEEL_H
