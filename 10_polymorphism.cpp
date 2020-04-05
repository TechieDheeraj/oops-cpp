#include<iostream>

using namespace std;


/* 

NOTE:
   1) Class with pure virtual functions called as (Abstract Class)
   2) Object of Abstarct class can't be declared
   3) Pointer of Abstract class can be declared that too by using some Derived class memory.
   4) Pure Virtual Functions must be implemented inside Derived Classes
   5) Purpose of Classes with Pure Virtual functions is Polymorphism and these classes can be called as (Interface)
   6) Purpose of Classes with Concrete Functions is Reuseability

*/

class Car {  // Abstract Class -> With Only Pure functions can be called as Interface
   
   public:

/*
   Don't need Definition of these functions here so make it as Pure Virtual Functions
      virtual void start() {
         cout << "Car Started" << endl;
      }

      virtual void stop() {
         cout << "Car Stopped" << endl;
      }
*/
      virtual void start() = 0;
      virtual void stop() = 0;
};

class Innova : public Car {

    public:
      void start() {
         cout << "Innova Started" << endl;
      }

      void stop() {
         cout << "Innova Stopped" << endl;
      }
};

class Swift : public Car {

   public:
      void start() {
         cout << "Swift Started" << endl;
      }

      void stop() {
         cout << "Swift Stopped" << endl;
      }
};

int main() {
   
 //  Car *C = new Car;
 //  C->start();
 //  C->stop();

   Car *IC = new Innova;
   IC->start();
   IC->stop();

   Car *SC = new Swift;
   SC->start();
   SC->stop();
  
   return 0;
}
