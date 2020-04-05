#include<iostream>

using namespace std;

class A {

   public:

      int valA;

      A() {
         cout << "Default Constructor of A" << endl;
      }

      A(int a) {
         cout << "Constructor of A with param " << a << endl;
         valA = a;
      }

      ~A() {
         cout << "Default Destructor of A" << endl;
      }

      int getVal() {
         return valA;
      }
};

/*      
      Ways of Inheritence :

 class B : public A     -> All members of class A will be copied as it is in class B
 class B : protected A  -> All protected, public members of class A will become protected in class B, means objB can't access any members of class B bcoz it's protected
 class B : private A    -> All protected, public members of class A will become private in class B, means objB can't access any members of class B bcoz it's private

 B objB;  ->  Creating Class B Object

*/

 class B : virtual public A { // Virtual is used to avoid Diamond problem from multiple inheritence

   public:

      int valB;

      B() {
         cout << "Default Constructor of B" << endl;
      }

      B(int a, int b):A(a) {
         cout << "Constructor of B with params " << a << ", " << b << endl;
         valB = b;
      }  

      ~B() {
         cout << "Default Destructor of B" << endl;
      }
};

class C : virtual public A {

   public:

      int valC;

      C() {
         cout << "Default Constructor of C" << endl;
      }

      //C(int a, int c): A(a) {
      C(int a, int c){
         cout << "Constructor of C with params " << a << ", " << c << endl;
         valC = c;
      }

      ~C() {
         cout << "Default Destructor of C" << endl;
      }
};

class D : public B, public C {  // Will Follow Order ( B first then C )

   public:

      int valD;

      D() {
         cout << "Default Constructor of D" << endl;
      }

      D(int a, int b, int c, int d):C(a, c), A(a), B(a, b) {     // Will Follow Order as per on line 81 
         cout << "Constructor of D with params " << a << ", " << b << ", " << c << ", " << d << endl;
         valD = d;
      }

      ~D() {
         cout << "Default Destructor of D" << endl;
      }
};

int main() {

   // A objA(10);
   //B objB(10, 20); // Base Class Constuctor first & Destructor Later
   //C objC(10, 20, 30);
    D objD(10, 20, 30, 40);

   cout << " Value is : " << objD.getVal() << endl;

   return 0;
}

