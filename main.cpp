#include<iostream>
#include<iomanip>
using namespace std;

enum DaylightSaving
{
    summerTime,
    winterTime,
    unknown
};

class Clock
{
private:
    unsigned int hour;
    unsigned int minute;
    DaylightSaving daylightSaving;
public:
    class HourTooBig: public exception
    {

    };
    class MinuteTooBig: public exception
    {

    };
    Clock():hour(0),minute(0),daylightSaving(unknown){}
    Clock(unsigned int hour, unsigned int minute, DaylightSaving daylightSaving)
    :hour(hour),minute(minute),daylightSaving(daylightSaving)
    {
        if(hour>23)
            throw HourTooBig();
        if(minute>59)
            throw MinuteTooBig();
    }
    void set_daylightSaving(DaylightSaving daylightSaving)
    {
        this->daylightSaving=daylightSaving;
    }
    DaylightSaving get_daylightSaving()
    {
        return daylightSaving;
    }
    void operator++()
    {
        if(minute==59)
            {
                minute=0;
                if(hour==23)
                    hour=0;
                else
                     hour++;
            }
        else
            minute++;
    }

    friend bool operator==(Clock& t1, Clock& t2)
    {
        return t1.hour==t2.hour && t1.minute==t2.minute;
    }
    friend ostream& operator<<(ostream&, Clock&);

};

ostream& operator<<(ostream& out, Clock& c)
{
    return out<<setw(2)<<setfill('0')<<c.hour<<":"<<setw(2)<<setfill('0')<<c.minute;
}

int main()
{
    Clock *clock1=new Clock(0,5,winterTime);
    Clock clock2(23,9,summerTime);
    Clock *clock3;
    clock1->set_daylightSaving(summerTime);
    for(int i=0;i<120;i++)
    {
        clock2++;
    }
    try
    {
        unsigned int h, m;
        cout<<"hour: ";
        cin>>h;
        cout<<"minute: ";
        cin>>m;
        clock3=new Clock(h,m, unknown);
        if(clock2==(*clock3))
            cout<<"same time"<<endl;
    }
    catch (Clock::HourTooBig hr)
    {
        clock3=new Clock();
    }
    catch(Clock::MinuteTooBig mi)
    {
        clock3=new Clock();
    }
    cout<<*clock1<<endl;
    cout<<clock2<<endl;
    cout<<*clock3<<endl;
    return 0;
}
