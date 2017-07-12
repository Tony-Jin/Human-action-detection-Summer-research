#ifndef DATA_H_
#define DATA_H_

#include <fstream>
#include <iostream>

namespace cy {
    class Data {
    private:
        float Time;

        float AccX;
        float AccY;
        float AccZ;
        float Acc;

        float AngleVelocityX;
        float AngleVelocityY;
        float AngleVelocityZ;
        float AngleVelocity;

        int MagneticX;
        int MagneticY;
        int MagneticZ;

        float AngleX;
        float AngleY;
        float AngleZ;

        int Pressure;

        float Temperature;
        float Altitude;

    private:
        void AccCalculation(void);
        void AngleVelocityCalculation(void);

    public:
        Data(float*, int*);
    };
}

#endif  // DATA_H_