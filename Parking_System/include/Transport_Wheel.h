#ifndef TRANSPORT_WHEEL_H
#define TRANSPORT_WHEEL_H

#include <iomanip>
#include <string>
#include <sstream>
#include "Parking.h"

//Parking Space 10

//Following Transport Function are used to calculate time difference
int ConvertTimeToMinutes_TSW(int,int,bool);
int ComputeTime_TSW(int,int,int,int,bool,bool);

class Transport_Wheel: public Parking {
    private:
        std::string v_name;
        std::string v_num;
    public:
        Transport_Wheel(std::string vname, std::string vnum); //Parameterized Ctor;
        void Park_in_TransportWheel();
        void Park_out_TransportWheel();
        void Parking_Charge();
        std::string getvehicle_name();
        std::string getvehicle_num();

        ~Transport_Wheel(); //destructor
};

#endif // TRANSPORT_WHEEL_H
