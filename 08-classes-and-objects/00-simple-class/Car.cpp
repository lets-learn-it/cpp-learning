#include <iostream>
#include "Car.h"

// initialize static variable
int Car::totalCars = 0;

void Car::FillFuel(float amount) {
  fuel = amount;
}

void Car::Accelerate() {
  speed++;
  fuel -= 0.5f;
}

void Car::Brake() {
  speed = 0;
}

void Car::AddPassengers(int count) {
  passengers = count;
}

void Car::Dashboard() const {
  std::cout << "=============================" << std::endl
            << "| Fuel:       |" << fuel << std::endl
            << "| Speed:      |" << speed << std::endl
            << "| Passengers: |" << passengers << std::endl
            << "| Total Cars: |" << totalCars << std::endl
            << "=============================" << std::endl;
}

Car::Car() {
  fuel = 0;
  passengers = 0;
  ++totalCars;
}

// parameterized constructor
Car::Car(float amount, int passengers) {
  this->fuel = amount;
  this->passengers = passengers;
  ++totalCars;
}

// copy constructor
Car::Car(Car &car) {
  this->fuel = car.fuel;
  this->passengers = car.passengers;
  this->speed = car.speed;
  ++totalCars;
}

Car::~Car() {
  std::cout << "destructor" << std::endl;
  --totalCars;
}

// static member function
// no need to add static keyword
void Car::showCount() {
  std::cout << "Total cars:" << totalCars << std::endl;
}
