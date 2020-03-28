#include<iostream>

using namespace std;

class Test {

   private:
      int val;

   public:
      Test(int val) {
         this->val = val;
      }

      int get_val();

      int getVal() { // There is no seperate stack frame for this function
         cout << "This is Inline function" << endl; 
         return val;
      }
};

int Test::get_val() {
   cout << "This is Non-Inline function" << endl;
   return val;
}

int main() {

   Test Obj(4);

   Obj.getVal(); // Expand in the same line where that func is called is known as Inline function
   Obj.get_val();

   return 0;
}
