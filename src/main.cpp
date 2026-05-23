// Copyright 2022 NNTU-CS
#include <iostream>
#include "train.h"

int main() {
    Train train;

    train.addCar(true);
    train.addCar(false);
    train.addCar(true);
    train.addCar(false);

    int length = train.getLength();

    std::cout << "Train length: " << length << std::endl;
    std::cout << "Operations: " << train.getOpCount() << std::endl;

    return 0;
}
