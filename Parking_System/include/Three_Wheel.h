#ifndef THREE_WHEEL_H
#define THREE_WHEEL_H


#include <iomanip>
#include <string>
#include <sstream>
#include "Parking.h"

//Parking Space 15

//Following Three Function are used to calculate time difference
int ConvertTimeToMinutes_THW(int,int,bool);
int ComputeTime_THW(int,int,int,int,bool,bool);

class Three_Wheel: public Parking {
    private:
        std::string v_name;
        std::string v_num;
    public:
        Three_Wheel(std::string vname, std::string vnum); //Parameterized Ctor;
        void Park_in_ThreeWheel();
        void Park_out_ThreeWheel();
        void Parking_Charge();
        std::string getvehicle_name();
        std::string getvehicle_num();

        ~Three_Wheel(); //destructor
};

#endif // THREE_WHEEL_H
