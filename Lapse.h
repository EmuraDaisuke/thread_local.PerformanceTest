#pragma once



#include <iostream>
#include <chrono>



class Lapse final {
    public:
        ~Lapse()        { std::cout << (Now() - mLapse) << std::endl; }
        
        Lapse()         :mLapse(Now()){}
    
    private:
        double Now()    { using namespace std::chrono; return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count()) / 1000000000; }
    
    
    private:
        double mLapse;
};
