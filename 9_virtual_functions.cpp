#include<iostream>

using namespace std;

class Base {

   private:
      int val;

   public:

      Base() { 
         val = 10;
      }

      virtual int func() {
         cout << "\n" << __func__ << ": of Base Class is called " << endl;
         return val;
      }
};

class Derived : public Base {
   
   private: 
      int val1;

   public:

      Derived() {
         val1 = 20;
      }

      int func() {
         cout << "\n" << __func__ << ": of Derived class is called " << endl;
         return val1;
      }
}; 

int main() {
   
   Base objB;
   Derived objD;

   cout << "Val is : " << objB.func() << endl;
   cout << "Val is : " << objD.func() << endl;

   Base *ptrA = new Derived;    // ptr can only access which is defined in Base Class

   cout << "Val is: " << ptrA->func() << endl;    // This Will not call Override function which is present in Derived Class for that make Base Class function as Virtual 

   return 0;
}
