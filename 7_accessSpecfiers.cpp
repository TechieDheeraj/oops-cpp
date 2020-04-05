#include<iostream>

using namespace std;

/*
   Access Specifier Table:

-----------------|--------------|---------------|-------------|
      Types      |   Private    |   Protected   |   Public    |   
-----------------|--------------|---------------|-------------|
   Base Class    |     Yes      |      Yes      |    Yes      |
-----------------|--------------|---------------|-------------|
   Class Object  |     No       |      No       |    Yes      |
-----------------|--------------|---------------|-------------|
   Derived Class |     No       |      Yes      |    Yes      |
-----------------|--------------|---------------|-------------|

*/

class Base {
   
   private:
      int a;

   protected:
      int b;

   public:
      int c;

   Base() {
      a = 10;
      b = 20;
      c = 30;
   }
   
   int getPrivate() {
      return a;
   }
   int getProtected() {
      return b;
   }
};

class Derived: public Base {      // isA relation with Base Class

//   a = 40; Can't access Private Members of Base class
   public:
      void setBaseValues() {
         b = 50;
         c = 60;
      }

      void displayValues() {
         cout << getPrivate() << ", " << b << ", " << c << endl;
      }
};

int main() {

/* From a Class Object */
   Base objA; // Created Base class Object ( Shows hasA relation with Base class)

//   objA.a = 70; Can't access Private Members of Base class
//   objA.b = 80; Can't access Protected Members of Base class
   objA.c = 90;

/* From a Derived Class*/
   Derived objB; // Created Derived class Object
   objB.setBaseValues();

   objB.displayValues();

   return 0;
}
