#include <iostream>
#include "Car.h"
using namespace std;

int main() {
  // using default constructor
  Car car1;
  car1.FillFuel(2);
  car1.Accelerate();
  car1.AddPassengers(10);
  car1.Dashboard();

  // using parameterized constructor
  Car car2(4.5f, 20);
  car2.Dashboard();

  // destory car1
  car1.~Car();

  Car::showCount();

  // const object
  const Car car3;
  car3.Dashboard();  // Dashboard  function is const

  // copy constructor
  Car car4(car1);
  car4.Dashboard();
  return 0;
}