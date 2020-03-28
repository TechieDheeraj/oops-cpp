#include<iostream>

using namespace std;

class Rectangle { // Base Class
   
   private:
      int length;
      int breadth;

   public:
      int getLength();
      int getBreadth();
      void setLength(int l);
      void setBreadth(int b);
      int getarea();
      Rectangle();
      Rectangle(int l, int b);
};

class Cuboid : public Rectangle { // Derived Class

   private:
      int height;

   public:
      int getHeight();
      void setHeight(int h);
      int getVolume();
      Cuboid();
      Cuboid(int h);
      // Cuboid(int l, int b, int h); taking all params of cuboid and internally calling Rectangle class method functions 
      Cuboid(int l, int b, int h):Rectangle(l, b) { // Will call Param constructor of base class
         cout << "Second Param Const of Cuboid called " << endl;
         setHeight(h);
      }
      friend ostream & operator <<(ostream &out, Cuboid &cube);
};

// Rectangle Class Functions 

Rectangle::Rectangle() {
   cout << "Default const of Rect Called" << endl;
   length = 1;
   breadth = 1;
}

void Rectangle::setLength(int l) {
   if (l > 0)
      length = l;
   else
      length = 1;
}

void Rectangle::setBreadth(int b) {
   if (b > 0)
      breadth = b;
   else
      breadth = 1;
}

Rectangle::Rectangle(int l, int b) {
   cout << "Param Const of Rect Called" << endl;
   setLength(l);
   setBreadth(b);
}

int Rectangle::getLength() {
   return length;
}

int Rectangle::getBreadth() {
   return breadth;
}

int Rectangle::getarea() {
   return length * breadth;
}

// Cuboid Class Functions

Cuboid::Cuboid() {
   cout << "Default const of Cuboid Called" << endl;
   height = 0;
}
 
void Cuboid::setHeight(int h){

   if(h > 0)
      height = h;
   else
      height = 1;
}

Cuboid::Cuboid(int h) {
   cout << "First Param Const of Cuboid Called" << endl;
   setHeight(h);
}

/*
Cuboid::Cuboid(int l=0, int b=0, int h=0) {  // Declared at line 31 -> Will call default constructor of base class first
   cout << "Param const of Cuboid " << endl;
   setHeight(h);
   setLength(l);
   setBreadth(b);
}
*/

int Cuboid::getHeight(){
   return height;
}

int Cuboid::getVolume() {
   return getLength() * getBreadth() * getHeight();
}
      
ostream & operator <<(ostream &out, Cuboid &cube) {
   out << "Cuboid (l,b,h) -> " << cube.getLength() << ", " << cube.getBreadth() << ", " << cube.getHeight();
   return out;
}

int main() {

   Rectangle rect(3, 4);
   rect.setLength(6);

   cout << "Area of rect is " << rect.getarea() << endl;
//   Cuboid cube(2,4,6); // (For Line:30) This Statement will call Default Constructor of Base Class first and then param constructor of derived class
   Cuboid cubeA(6);
   cubeA.setHeight(7);
   cout << cubeA << endl; // print cuboid data
   cout << "Volume is " << cubeA.getVolume() << endl;

   Cuboid cubeB(2,4,6); 
   cubeB.setHeight(7);
   cout << cubeB << endl; // print cuboid data
   cout << "Volume is " << cubeB.getVolume() << endl;

   return 0;
}
