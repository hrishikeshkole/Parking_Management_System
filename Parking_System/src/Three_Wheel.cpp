#include "Three_Wheel.h"
#include <iomanip>
#include <string>

Three_Wheel::Three_Wheel(std::string vname, std::string vnum){
    v_name = vname;
    v_num = vnum;
}//Parameterized Constructor

Three_Wheel::~Three_Wheel(){}

void Three_Wheel::Park_in_ThreeWheel(){
    std::string time;
    std::cout << std::setw(77) << "Time Guide <HH>space:space<MM>space<Time_Format> for eg. - 10 : 20 AM " << std::endl;
    std::cout << std::setw(28) << "Enter Park_In Time - ";
    std::getline(std::cin,time);
    Parking::setpark_in(time);
}//end Park_in_ThreeWheel

void Three_Wheel::Park_out_ThreeWheel(){
    std::string time;
    std::cout << std::setw(77) << "Time Guide <HH>space:space<MM>space<Time_Format> for eg. - 10 : 20 AM " << std::endl;
    std::cout << std::setw(29) << "Enter Park_Out Time - ";
    std::getline(std::cin,time);
    std::cout << std::endl;
    Parking::setpark_out(time);
}//end Park_out_ThreeWheel

void Three_Wheel::Parking_Charge(){
    const double THW_FARE {25.00}; // Three_Wheeler Parking Fare / Per Hour
    std::string pin = Parking::getpark_in();
    std::string pout = Parking::getpark_out();

    std::string colon1,TT1,colon2,TT2;
    int HH1{0},MM1{0},HH2{0},MM2{0};
    bool t1{false},t2{false};

    std::istringstream iss1 {pin}; //park_in Time
    std::istringstream iss2 {pout}; //park_out Time
    iss1 >> HH1 >> colon1 >> MM1 >> TT1;
    iss2 >> HH2 >> colon2 >> MM2 >> TT2;

    if(TT1 == "PM")
        t1 = true;

    if(TT2 == "PM")
        t2 = true;

    int hours = ComputeTime_THW(HH1,HH2,MM1,MM2,t1,t2) / 60;


    double charges = hours * THW_FARE;

    Parking::setParkCharge(charges);

    std::cout << "-------------------" << " Parking Charges " << "----------------------" << std::endl
              << std::setw(40) << std::left << "Vehicle Name - " << getvehicle_name() << std::endl
              << std::setw(40) << std::left << "Vehicle Number - " << getvehicle_num() << std::endl
              << std::setw(40) << std::left << "Parked for - " << hours << " Hours" << std::endl
              << std::setw(40) << std::left << "Collect Payment - " << std::setprecision(2) << std::fixed << charges << " Rs" << std::endl;
    std::cout << "------------------------------------------------------------"<< std::endl;

    Parking::totalcollection(charges); //adding to daily collection

}//end Parking_Charge

std::string Three_Wheel::getvehicle_name(){ return v_name; }//end getvehical_name

std::string Three_Wheel::getvehicle_num(){ return v_num; }//end getvehical_num


int ConvertTimeToMinutes_THW(int hour, int min, bool pm){
    if (hour == 12)
        hour = 0;
    int calc = hour*60 + min;
    if (pm)
        calc += 12*60;
    return calc;
}//end ConvertTimeToMinutes_THW

// Compare times and return the absolute time difference in minutes
int ComputeTime_THW(int hour1, int hour2, int min1, int min2, bool pm1, bool pm2){
    int calc1 = ConvertTimeToMinutes_THW(hour1, min1, pm1);
    int calc2 = ConvertTimeToMinutes_THW(hour2, min2, pm2);
    if (calc2 > calc1)
    {
        return calc2 - calc1;
    }
    else
    {
        return calc1 - calc2;
    }
}//end ComputeTime_THW

