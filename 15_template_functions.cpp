#include<iostream>

using namespace std;

/*
   Template Funcitons:
      1. Can have any data type
      2. In maximum teplate func, if greater than operation works on data type it is better unless T is class where we need to provide operator overloading 
*/

/********** Template Functions Example ***************/
  
template <class T>
T maximum(T x, T y) {
   return x > y ? x : y;
}

/*****************************************************/

class StackOverflow : public exception {};
class StackUnderflow : public exception {};

template <class T>
class Stack {

   private:  
      T *arr;
      int size;
      int top;

   public:
      Stack(int sz) {
         size = sz;
         arr = new T[size];
         top = -1;
      }
         
      void push(T) throw(StackOverflow);
      T pop() throw(StackUnderflow);

      
      ~Stack() {
         cout << "Destroying stack .... of size : " << size << endl;
         delete arr;
         arr = nullptr;
      }
      
};

template<class T>
void Stack<T>::push(T x) throw(StackOverflow) { // We can tell caller push can throw stackOverfllow exception
   
   cout << "Pushed " << x << " onto Stack " << endl;
   if (++top > size-1) // top starts from 0
      throw StackOverflow();
   arr[top] = x;

};

template<class T>
T Stack<T>::pop() throw(StackUnderflow) {

   T x;

   if (top == -1) {
      cout << "Stack is empty " << endl;
      throw StackUnderflow();
   }
   else
      x = arr[top--];

   return x;

};

int main() {

/********** Template Functions Example ***************/
   cout << "Bigger is : " << maximum(10, 20) << endl;
   cout << "Bigger is : " << maximum(3.5, 2.5) << endl;
   cout << "Bigger is : " << maximum('b', 'a') << endl;
/*****************************************************/

/********** Template Classes Example ***************/

   Stack<int> ssi(5); // Satck of size 5 of type int 
   Stack<double> ssd(3); // Satck of size 5 of type double 

   try {
      ssi.push(1);
      ssi.push(2);
      ssi.push(3);
      ssi.push(4);
      ssi.push(5);
   }
   catch(StackOverflow e) {
      cout << "Got exception of StackOverflow " << endl;
   }

   try {
      cout << "Popped Value is: " << ssi.pop() << endl;
      cout << "Popped Value is: " << ssi.pop() << endl;
      cout << "Popped Value is: " << ssi.pop() << endl;
   }
   catch(StackUnderflow) {
      cout << "Got exception of StackUnderflow " << endl;
   }

   try {  
      ssd.push(0.5);
      ssd.push(1.5);
      ssd.push(2.5);
   }
   catch(StackOverflow e) {
      cout << "Got exception of StackOverflow " << endl;
   }

   try {
      cout << "Popped Value is: " << ssd.pop() << endl;
      cout << "Popped Value is: " << ssd.pop() << endl;
      cout << "Popped Value is: " << ssd.pop() << endl;
      cout << "Popped Value is: " << ssd.pop() << endl;
   }
   catch(StackUnderflow e) {
      cout << "Got exception of StackUnderflow " << endl;
   }


   return 0;
}
