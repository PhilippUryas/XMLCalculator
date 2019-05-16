#include "abstractcalculator.h"

AbstractCalculator::AbstractCalculator() {

}

AbstractCalculator::~AbstractCalculator() {

}



int AbstractCalculator::sum(int a, int b) {
    return a+b;
}

int AbstractCalculator::diff(int a, int b) {
    return a-b;
}

int AbstractCalculator::mult(int a, int b) {
    return a*b;
}

int AbstractCalculator::div(int a, int b) {
    return a/b;
}

