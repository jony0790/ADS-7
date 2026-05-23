// Copyright 2022 NNTU-CS
#pragma once

class Train {
 private:
    struct Car {
        bool light;
        Car* next;
        Car* prev;

        Car(bool state);
    };

    int countOp;
    Car* first;

 public:
    Train();
    ~Train();

    void addCar(bool light);

    int getLength();

    int getOpCount();
};
