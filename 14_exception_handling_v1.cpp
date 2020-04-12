#include<iostream>

/************* Exception Handling **************

# Types of Errors:

Due to Programmer's direct Mistakes:
   1. Syntax errors  ---> (e.g. ';' missing, Can be traced by 'Compiler')
   2. Logical errors ---> (Code Logic is not working, Can be traced by 'Debugger' like GDB)

   # This is also called exceptions:
      3. Run-Time errors ---> (e.g. Divide by Zero, Can be handled by Exception handler Code)

# NOTE:

   1. try and catch is generally used when after calling a function, function is unable to return valid value and throws exception to the caller function as shown at line 52

*/

using namespace std;

class Test {
   private:  
      int a, b;
      
   public:

      Test(int v1, int v2) {
         a = v1;
         b = v2;
      }

      void divNumbers() {
         int c;
         
         try { // Try the Block if any error throw exception and that can be catched inside catch block if not thrown line 37 is executed
            if (b == 0) {
               throw 1;
            }

            c = a/b;
            cout << "C is " << c << endl;
         }
         catch (int e) {
            cout << "Line: " << __LINE__ << " Exception thrown with code " << e << endl;
         }
      }

      friend int divideNum(); // friend functions can access all members of class upon object as if these are class functions
};

int divideNum() {

   Test objB(13,2);
   
   if (objB.b == 0) {
      throw 3;
   }

   return objB.a/objB.b;
}

int main() {

   Test objA(10, 4);

   objA.divNumbers();

   try {
      int c = divideNum();

      cout << "Returned c is : " << c << endl;
   }

   catch(int e) {
      cout << "Got exception from function: " << e << endl;
   }

   return 0;
}
