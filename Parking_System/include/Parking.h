#ifndef PARKING_H
#define PARKING_H
#include <iostream>
#include <iomanip>
#include <string>

class Parking
{
    private:
        double park_charge;
        std::string in_time;
        std::string out_time;
        static double total_amt; //static variable
    public:
       double getParkCharge();
       void setParkCharge(double val);
       void setpark_in(std::string time);
       void setpark_out(std::string time);
       std::string getpark_in();
       std::string getpark_out();
       void totalcollection(double amt);
       double gettotalcollection();
       Parking();
       ~Parking();
};

#endif // PARKING_H
