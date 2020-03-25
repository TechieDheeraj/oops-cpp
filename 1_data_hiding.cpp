#include<iostream>

using namespace std;

/* 
  DATA HIDING:
  
  Property Functions:
    1. Mutators (Set Functions)
    2. Accessors (Get Functions)
*/

class Rectangle {

   private :
      int length;
      int breadth;

   public: 

      Rectangle() {
         this->length = 10;
         this->breadth = 20;
      }

      int area() {
         return length*breadth;
      }

      void setLength(int len) {

         if(len < 0)
            this->length = 1;
         else
            this->length = len;
      }

      void setBreadth(int br) {

         if(br < 0)
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

   Rectangle rect;
   int len, br;

   cout << "Enter Length of Rectangle" << endl;
   cin >> len; 
   rect.setLength(len);
   cout << "Length is " << rect.getLength() << endl;

   cout << "Enter breadth of Rectangle" << endl;
   cin >> br; 
   rect.setBreadth(br);
   cout << "Breadth is " << rect.getBreadth() << endl;

   cout << "Area of Rectangle is " << rect.area() << endl;

// Providing -ve Value and Mutator func should take care that
   cout << " \n\t ***** Giving -VE Value *******\n" << endl;

   rect.setLength(-2);
   rect.setBreadth(-5);
   cout << "Length " << rect.getLength() << " Breadth " << rect.getBreadth() << endl;

   cout << "Area of Rectangle is " << rect.area() << endl;

   return 0;
}
