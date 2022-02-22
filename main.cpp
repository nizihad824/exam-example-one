
//Probeklauser 2

#include<bits/stdc++.h>
using namespace std;

enum DaylightSaving {summerTime,winterTime,unknown};
class Clock{
private:
    unsigned int hour;
    unsigned int minute;
    DaylightSaving daylightSaving;
public:
    class HourTooBig:public exception{};
    class MinuteTooBig:public exception{};

//public overloaded inline standard constructor initialising the clock(time) by an initialisation list to
//midnight 00:00 o'clock with unknown daylight saving
    Clock(){

    }
    //inline Clock(unsigned int hour=0,unsigned int minute=0):minute(minute),hour(hour),daylightSaving(unknown){}

   inline Clock(unsigned int hour,unsigned int minute ,DaylightSaving daylightSaving):hour(hour),minute(minute)
            ,daylightSaving(daylightSaving)
    { if(hour>23 )
            throw HourTooBig();
        if (minute>59)
            throw MinuteTooBig();
    }
    void    set_daylightSaving(DaylightSaving){
        this->daylightSaving=daylightSaving;
    }
    DaylightSaving get_daylightSaving(){
        return daylightSaving;
    }

    //  public definition of an overloaded unary increment operator ++ incrementing the clock by one minute.
    void operator ++( int){
        if (minute>60 )
        {
            minute=0;
            hour++;

            if(hour>24){
                hour =0;
        }
        }
        else {
            minute++;
        }
    }


//public definition of a friend binary operator == to overload the comparison of the clock times for
//two given references to objects of type Clock.
    friend bool  operator==(Clock &c1,Clock &c2)
    {
        if ((c1.hour == c2.hour)&&(c1.minute=c2.minute))
            return true;
        else
            return false ;
    }

    friend ostream &operator<<(ostream &o,Clock &c ){

        o<<setw(2)<<setfill('0')<<(c.minute/60)<<":"<<setw(2)<<setfill('0')<<c.minute%60;
        return o;
    }
};

int main(){

    Clock *clock1= new Clock(00,05,winterTime);
    Clock clock2(23,05,summerTime);
    Clock *clock3;

    clock1->set_daylightSaving(summerTime);

    for (int i;i<120;i++){
        clock2++;
    }
    try{
        unsigned int hour,minute;
        cout<<"hour  :";
        cin>>hour;
        cout<<"minute  :";
        cin>>minute;
         clock3= new Clock(hour,minute,unknown);
         if(clock2==*clock3){
             cout<<"same string"<<endl;
         }

    }
    catch(Clock::MinuteTooBig)
    {clock3=new Clock;}
    catch(Clock::HourTooBig)
    {clock3=new Clock;}

    cout<<*clock1<<endl;
    cout<<clock2<<endl;
    cout<<"clock3"<<clock3<<endl;
    return 0;
}