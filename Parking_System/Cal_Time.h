
//Following Two Function are used to calculate time difference
int ConvertTimeToMinutes(int,int,bool);
int ComputeTime(int,int,int,int,bool,bool);

int ConvertTimeToMinutes(int hour, int min, bool pm){
    if (hour == 12)
        hour = 0;
    int calc = hour*60 + min;
    if (pm)
        calc += 12*60;
    return calc;
}//end ConvertTime To Minutes

// Compare times and return the absolute time difference in minutes
int ComputeTime(int hour1, int hour2, int min1, int min2, bool pm1, bool pm2){
    int calc1 = ConvertTimeToMinutes(hour1, min1, pm1);
    int calc2 = ConvertTimeToMinutes(hour2, min2, pm2);
    if (calc2 > calc1)
    {
        return calc2 - calc1;
    }
    else
    {
        return calc1 - calc2;
    }
}
