#include<iostream>

using namespace std;

class MyException : public exception { // Can inherit not mandatory and also can override method "what()"
   
   public:
      string what() {
         return "My Exception";
      }
};

//int division(int x, int y) throw(MyException) { // We Can tell caller which type of exception this function throws
//int division(int x, int y) throw() { // empty bracket in throw means this function doesn't throw any exception 

int division(int x, int y) {
   
   if (y == 0)
      throw MyException();
   else if (y == 1)
      throw 0.5;
   else if (y == 2)
      throw string("Invalid exception");
   else if (y == 3)
      throw 5; 
   else if (y == 4)
      throw 'a';

   return x/y;
}

int main() {

   int x, y;

   cout << "Enter Value of x and y " << endl;
   cin >> x >> y;

/*
   NOTE:
        1. You can have try and catch inside try block as nested one

        try {
         division(x, y);
            try {
               division(x,y);
            }
            catch(int e) {
               cout << "Got Integer exception " << e << endl;
            }
        }
        catch(int e) {
            cout << "Got Integer exception " << e << endl;
        }
*/

   try {
      division(x, y);
   }
   catch(MyException e) {
      cout << "throws Class exception" << endl;
   }
   catch(double e) {
      cout << "throws double exception : " << e <<endl;
   }
   catch(string e) {
      cout << "throws string exception : " << e << endl;
   }
   catch(int e) {
      cout << "throws integer exception" << endl;
   }
   catch(...) { // Catch All and argument is elipse, must write this catch block at end
      cout << "All exception are handled here: " << endl;
   }
     
   return 0;
}
