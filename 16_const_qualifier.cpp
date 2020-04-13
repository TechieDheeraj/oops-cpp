#include<iostream>

#define VAL 10;  // Scope is global to program and No memory is declared for this

using namespace std;

class Demo {
   private:
      int x = 10;
      int y = 20;

   public:
      void changeVal() const {  //  const can prevent function to change class members
//         x++; // Invalid as const is used
         cout << "x is : " << x << " y is : " << y << endl;
      }
};

int main() {

   int count = 20;
   int extra = 30;

   const int val = 10;  // Scope is local to main function and memory is declared

   const int *ptrA = &count;  // Read from right to Left -> pointer int constant -> Can't modify count but ptrA can point to other memory

//   ++*ptrA; // Invalid as trying to change count
    ptrA = &extra; // Valid as ptrA is pointing to extra now. 
//   ++*ptrA; // Invalid as trying to change extra 

   int const *ptrB = &count; // Read from right to Left -> pointer constant int -> Can't modify count but ptrB can point to other memory

//   ++*ptrB; // Invalid as trying to change count
   ptrB = &extra; // Valid as ptrB is pointing to extra now. 
//   ++*ptrB; // Invalid as trying to change extra 

   int * const ptrC = &count;  // Read from right to Left -> pointer constant int -> Can't modify ptrC but can modify count; 

   ++*ptrC; // Valid as trying to change count
//   ptrC = &extra; // Invalid as trying to change ptrC. 
   ++*ptrC; // Valid as trying to change count not extra 

   const int * const ptrD = &count;  // Read from right to Left -> pointer constant int const -> Can't modify ptrC also can't modify count;

//   ++*ptrD; // Invalid as trying to change count
//   ptrD = &extra; // Invalid as trying to change ptrD. 
//   ++*ptrD; // Invalid as trying to change count 

   Demo d;

   d.changeVal();

   return 0;
}
