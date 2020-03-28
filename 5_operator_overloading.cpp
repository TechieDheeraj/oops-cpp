#include<iostream>

using namespace std;

class Complex {
   
   private:
      int real;
      int img;

   public:
      
      Complex(int real=0, int img=0) {
         this->real = real;
         this->img = img;
      }

      Complex add(Complex x) {  // Do the same addition operation by writing function
         Complex temp;

         temp.real = this->real + x.real;
         temp.img = this->img + x.img;

         return temp;
      }

/* Note: 
   Either C1 OR C2 is adding itself with passed class object.
      Complex operator +(Complex x) { // Operator (+) Overloading
         Complex temp;

         temp.real = this->real + x.real;
         temp.img = this->img + x.img;

         return temp;
      }
*/
/* Note: 
   Nor C1 OR C2 is adding, A friend function is adding both Objects
*/
      friend Complex operator +(Complex x, Complex y); // Operator (+) Overloading
      friend ostream & operator <<(ostream &out, Complex &x);
      friend istream & operator >>(istream &in, Complex &x);

      void printData() {
         cout << real << " + i" << img << endl;
      }
};

/*
   NOTE:
      For friend functions, no Scope Resolution operators are used
*/

Complex operator +(Complex x, Complex y) { // Operator (+) Overloading
   Complex temp;

   temp.real = x.real + y.real;
   temp.img  = x.img + y.img;

   return temp;
}

ostream & operator <<(ostream &out, Complex &x) { // Stream Insertion Operator (<<)
   out << x.real << " + i" << x.img;
   return out;
}

istream & operator >>(istream &in, Complex &x) { // Stream Insertion Operator (<<)
   in >> x.real >> x.img;
   return in;
}
   
int main() {

   Complex C1(4, 5);
   Complex C2(6, 7);

   //Complex C3 = C1.add(C2);
   Complex C3 = C1 + C2;
   Complex C4;

   C3.printData();
   cout << C3 << endl; // After returning from function (cout << C3 --> cout then cout << endl will be called

   cin >> C4;
   cout << C4 << endl;

   return 0;
}
