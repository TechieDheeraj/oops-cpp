#include<iostream>

using namespace std;

class Test {
   public:  
      int *arr;
      int size;

      Test(int sz) {
         cout << "Allocating memory for arr of size " << sz << endl;
         arr = new int[sz] ;
      }

      ~Test() { // Can only be one Destructor ( To free up Heap Meory, Close Open files, Close Sockets
         cout << "Freeing up arr" << endl;
         delete arr;
       }
};

class Base {
   public:
      int data;
      
      Base() {
         cout << "Base class Constructor " << endl;
      }
      // Virtual Destructors
      virtual ~Base() { // Derived class Destructor will be called also if make virtual
         cout << "Base class Destructor " << endl;
      }
};


class Derived: public Base {
    public:
      int dataV1;
      
      Derived() {
         cout << "Derived class Constructor " << endl;
      }
      ~Derived() {
         cout << "Derived class Destructor " << endl;
      }
};

int main() {

/* NOTE :  
   1. Constructors are called in TOP-DOWN approach
   2. Destructors are called in DOWN-TOP approach
*/

   Test obj(10);

   Base objA;
   Derived objB; // Constructor of Base First, then Derived Class Constructor
                // Destructor of Derived First, then Base Class Constructor

   Base *ptr = new Derived();

   delete ptr; // By-default it will call Base class Destructor as ptr is of Base class type To call both destructors make Base class Destructor as Virtual

   return 0;
}
