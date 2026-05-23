// Copyright 2021 NNTU-CS
#include "train.h"

Train::Car::Car(bool state) {
    light = state;
    next = nullptr;
    prev = nullptr;
}

Train::Train() {
    first = nullptr;
    countOp = 0;
}

Train::~Train() {
    if (first == nullptr)
        return;

    Car* current = first->next;

    while (current != first) {
        Car* temp = current;
        current = current->next;
        delete temp;
    }

    delete first;
}

void Train::addCar(bool light) {
    Car* newCar = new Car(light);

    if (first == nullptr) {
        first = newCar;
        first->next = first;
        first->prev = first;
        return;
    }

    Car* last = first->prev;

    last->next = newCar;
    newCar->prev = last;

    newCar->next = first;
    first->prev = newCar;
}

int Train::getLength() {
    if (first == nullptr)
        return 0;

    countOp = 0;

    int len = 1;

    Car* current = first;

    while (current->next != first) {
        current = current->next;
        countOp++;
        len++;
    }

    return len;
}

int Train::getOpCount() {
    return countOp;
}
