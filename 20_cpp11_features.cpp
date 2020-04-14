#include<memory>
#include<iostream>
#include<stdarg.h>

using namespace std;

class Test {
   
   private:
      int x = 10;  // In-Class member initalization
      int y = 20;

   public:

      Test(int a, int b) {
         x = a;
         y = b;
      }

      Test():Test(1, 1) {  // In-Class constructor calling
      }

      int mul() {
         return x * y;
      }
}; 

class Rectangle {

   public:
      int length;
      int breadth;

      Rectangle(int a, int b) {
         length = a;
         breadth = b;
      }

      int area() {
         return length * breadth;
      }

};

/************************ final Keyword ************************/

// class Parent final { // final keyword is used to Restrict inheritence
class Parent { // final keyword is used to Restrict inheritence
   
   public:
      //virtual void show() final {  // final keyword is used to Restrict Overriding 
      virtual void show() {  // final keyword is used to Restrict Overriding 
      }
};

class Child : public Parent {

   public:  
      void show() { // Can't Override as is is restricted in Parent class by using final
      }
};

/**************************************************************/

int sum(int n, ...) {  // n is number of arguments
   
   va_list list;

   va_start(list, n);

   int x = 0;
   int s = 0;

   for(int i=0; i < n ; ++i) {
      x = va_arg(list, int);
      s+=x;
   }
   
   return s;
}

int main() {

/************************ Lambda Expressions ************************/

   int a = 10, b = 11;

   []() { cout << "Hello world" << endl; }();

   auto f = []() { cout << "Hello world again " << endl; };

   f();

   [](int x, int y) { cout << "Sum is " << x+y << endl; }(10, 5);

   int z = [](int x, int y) { return x+y; }(10,5);

   cout << "z is : " << z << endl;

   int s = [](int x, int y)->int{return x+y;}(10, 5);
   cout << "s is : " << s << endl;

//   [capture_list](parameter_list)->return_type{body;}(calling);  Lambda expression
   [a,b]() { cout << "a is: " << a << " " << "b is: " << b << endl; }();
   [&a, &b]() { cout << "a is: " << ++a << " " << "b is: " << ++b << endl; }(); // With reference can change the values

   cout << "a: " << a << " " << b << endl;

/************************ Smart Pointers ************************

   1. unique_ptr -> Only 1 pointer at a time to One Object
   2. shared_ptr -> Maintains ref_counter (use_count();) to check how many pointers pointing
   3. weak_ptr   -> Multiple pointer can point to same object but doesn't maintains ref_counters 

*/

/**************************** unique_ptr **************************/

   unique_ptr<Rectangle> ptr1(new Rectangle(10, 5)); // Upon Object at a time one pointer will be pointing to Rectangle Object, we can delete ptr1 and create new pointer with name ptr2 and transfer the control to ptr2 but ptr1 and ptr2 both can't share same object

   cout << "ptr1->area() " << ptr1->area() << endl; 

   unique_ptr<Rectangle> ptr2;
   ptr2 = move(ptr1); // ptr1 will leave control and become null

   cout << "ptr2->area() " << ptr2->area() << endl; 

/**************************** shared_ptr **************************/

   shared_ptr<Rectangle> ptr3(new Rectangle(20, 5));

   cout << "ptr3: " << ptr3->area() << " ref_count : " << ptr3.use_count() << endl;
   shared_ptr<Rectangle> ptr4;

   ptr4 = ptr3; // Not possible in unique_ptr

   cout << "ptr4: " << ptr4->area() << " ref_count : " << ptr4.use_count() << endl;

/**************************** In-Class Constructor calling *********/

   Test ObjA;

   cout << "Multiplication of val is : " << ObjA.mul() << endl;

/********** retrieving sum with variable args using elipses **********/


   cout << "Sum is : " << sum(4, 2, 3, 4, 5) << endl;

   return 0;
}
