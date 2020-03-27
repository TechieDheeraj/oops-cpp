#include<iostream>

using namespace std;

class Rectangle {

   private:  
      int length;
      int breadth;

   public:
     
// Constructor Overloading -> Multiple Constructors with same name

      Rectangle() { // Default Constructor OR Non-Parameterized Constructor
         cout << "Default Constructor is called" << endl;
         length = 1;
         breadth = 1;
      }

      Rectangle(int l, int b) { // Parameterized Constructor
         cout << "Parameterized Constructor is called" << endl;
         setLength(l);
         setBreadth(b);
      }

      Rectangle(Rectangle &rect) { // Copy Constructor ( Shallow Copy Constructor )
         cout << "Copy Constructor is called" << endl;
         length = rect.length;
         breadth = rect.breadth;
      }

      Rectangle

      int area() {
         return length*breadth;
      }

      void setLength(int len) {

         if (len < 0)
            this->length = 1;
         else
            this->length = len;
      }

      void setBreadth(int br) {

         if (br < 0)
            this->breadth = 1;
         else
            this->breadth = br;
      }

      int getLength() {
         return length;
      }

      int getBreadth() {
         return breadth;
      }

};

int main() { 

   Rectangle objA; // Default Constructor is called
   Rectangle objB(22, 33);
   Rectangle objC(objB);

   cout << "In ObjA : " << objA.getLength() << " , " << objA.getBreadth() << endl;
   cout << "In ObjB : " << objB.getLength() << " , " << objB.getBreadth() << endl;
   cout << "In ObjC : " << objC.getLength() << " , " << objC.getBreadth() << endl;
 

   return 0;
}
