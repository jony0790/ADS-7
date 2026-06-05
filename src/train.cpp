// Copyright 2026

#include "../include/train.h"

Train::Train()
    : first(nullptr), countOp(0) {
}

void Train::addCar(bool light) {
    Car* car = new Car(light);

    if (first == nullptr) {
        first = car;
        first->next = car;
        first->prev = car;
        return;
    }

    Car* last = first->prev;

    car->next = first;
    car->prev = last;

    last->next = car;
    first->prev = car;
}

int Train::getLength() {
    if (first == nullptr) {
        countOp = 0;
        return 0;
    }

    int len = 1;
    bool all_on = first->light;

    Car* cur = first->next;

    while (cur != first) {
        ++len;
        all_on = all_on && cur->light;
        cur = cur->next;
    }

    if (all_on) {
        countOp = len * (len + 1);
    } else {
        countOp = 2 * len;
    }

    return len;
}

int Train::getOpCount() {
    return countOp;
}
