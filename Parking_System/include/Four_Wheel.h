#ifndef FOUR_WHEEL_H
#define FOUR_WHEEL_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Parking.h"

//Parking Space 20//Following Two Function are used to calculate time difference
int ConvertTimeToMinutes_FW(int,int,bool);
int ComputeTime_FW(int,int,int,int,bool,bool);

class Four_Wheel: public Parking {
    private:
        std::string v_name;
        std::string v_num;
    public:
        Four_Wheel(std::string vname, std::string vnum); //Parameterized Ctor;
        void Park_in_FourWheel();
        void Park_out_FourWheel();
        void Parking_Charge();
        std::string getvehicle_name();
        std::string getvehicle_num();

        ~Four_Wheel(); //destructor
};

#endif // FOUR_WHEEL_H
