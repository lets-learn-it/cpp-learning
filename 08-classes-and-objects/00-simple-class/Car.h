#pragma once

class Car {
  private:
    // can be initialized here.
    // compiler will add to default constructor
    float fuel{0};
    float speed = 0;

    // constructor can initialize it.
    int passengers;

    // static variables (cant be initialized here)
    static int totalCars;
  public:
    // default constructor
    Car();

    // destructor
    // it cant be overloaded
    ~Car();

    // overloaded parameterized constructor
    Car(float, int);

    // copy constructor
    // object arg should be passed as reference
    // because if passed by value, it will create copy of object
    // which will end up in loop
    Car(Car &car);

    void FillFuel(float amount);
    void Accelerate();
    void Brake();
    void AddPassengers(int count);

    // this function not changing object
    // can be marked as const so that const objects can use it
    void Dashboard() const;

    // static member function
    static void showCount();
};