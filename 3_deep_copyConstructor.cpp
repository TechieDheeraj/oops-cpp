#include<iostream>

using namespace std;

class Test { 

   private: 
      int val; 
      int *ptr;

   public:

// Default Constructor
      Test(int v) {
         val = v;
         ptr = new int[val];

         for(int i = 0; i < val; ++i)
            ptr[i] = i+1;
      }

// Deep Copy Constructor
      Test(Test &testObj) {
         val = testObj.val;
//         ptr = testObj.ptr; // It will point to the same memory 
         ptr = new int[val];

         for(int i = 0; i < testObj.val; ++i)
            ptr[i] = testObj.ptr[i];
      }

      void printData() {
         cout << "ptr: " << ptr << endl; 

         for(int i = 0; i < val; ++i)
            cout << ptr[i] << ", ";
         cout << "\n";
      }
};

int main() {

   Test objA(5);
   objA.printData();

   Test objB(objA);
   objB.printData();

   return 0;
}
