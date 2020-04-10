#include<iostream>

using namespace std;

class Test {
   private:
      int a;
      int b;

   public:

      static int count; // Belong to Class not objects 

      Test() {
         a = 10;
         b = 10;

         count++;
      }

      static int getCount() {
//         cout << "Can access only Static Members" << a << endl;
         return count;
      }
};

/* 
NOTE:
   USAGE OF STATIC MEMBERS:
     1. Can be used as Shared memory between Class Objects.
     2. Can provide Class information and do not need to create object for that.
     3. Can be used as a Counter.
*/

int Test::count = 0; // Initialize and Declaration is must because it is linked to Class not Objects and memory is global and scoped to Class

int main() {


   Test obj1;
   Test obj2;

   cout << "From Obj1 " << obj1.count << endl;
   cout << "From Obj2 " << obj2.count << endl;
   cout << "Using Class " << Test::count << endl; // Without creating Object can access.
   obj1.count = 20;
   cout << "From Obj2 " << obj2.count << endl;

   cout << "Static Func from Obj1 " << obj1.getCount() << endl;
   cout << "Static Func from Obj2 " << obj2.getCount() << endl;
   cout << "Static Func from Class " << Test::getCount() << endl;

   
   return 0;
}
