#include<iostream>

using namespace std;

class ClassB; // Must declared here because giving ClassB as friend inside ClassA and ClassB is getting defined later
class ClassA {
   
   private:
      int a;

   public:
      ClassA() {
         a = 10;
      }

   friend class ClassB; // Now ClassB can access ClassA Members upon Object
   friend void getVal(); // Now getVal can access ClassA Members upon Object
};

class ClassB {
   
   private:
      ClassA obj1;

   public:
      void printData() {
         cout << "Related classA val: " << obj1.a << endl;
      }
};

void getVal() {
   
   ClassA obj2;
   cout << "classA Values is: " << obj2.a << endl;
}

int main() {

   ClassB objB;

   objB.printData();
   cout << "Inside Friend Function --> "; 
   getVal();

   return 0;

}
