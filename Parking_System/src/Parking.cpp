#include "Parking.h"

double Parking::total_amt {0.0};

void Parking::totalcollection(double amt){
    total_amt += amt;
}

double Parking::gettotalcollection(){
    return total_amt;
}

void Parking::setParkCharge(double val){
    park_charge = val;
}//end setParkCharge

double Parking::getParkCharge(){
    return park_charge;
}//end getParkCharge;

Parking::Parking(){
    park_charge = 0.0;
    in_time = "";
    out_time = "";
}//end Ctor

Parking::~Parking(){
    park_charge = 0.0;
    in_time = "";
    out_time = "";
}//end destructor

void Parking::setpark_in(std::string time){
    in_time = time;
}//end setpark_in

void Parking::setpark_out(std::string time){
    out_time = time;
}//end setpark_out

std::string Parking::getpark_in(){ return in_time; }//end getpark_in
std::string Parking::getpark_out(){ return out_time; }//end getpark_out


