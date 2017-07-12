//
// Created by anima on 2017/7/12.
//
#include "Data.h"
#include <cmath>

namespace cy{
    using namespace std;

    void Data::AccCalculation() {
        Acc = sqrt(AccX*AccX + AccY*AccY + AccZ*AccZ);
    }

    void Data::AngleVelocityCalculation(void) {
        AngleVelocity = sqrt(AngleVelocityX*AngleVelocityX + AngleVelocityY*AngleVelocityY + AngleVelocityZ*AngleVelocityZ);
    }
}
