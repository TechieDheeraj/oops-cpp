#include<iostream>

using namespace std;

#define PI 3.1425

#ifndef PI
   #define PI 3.1425
#endif

#define OUT cout

#define SQR(x) (x * x)

#define MAX(x, y) (x > y ? x : y)

#define TOSTR(x) #x    // Will Put x in double quotes ( "x" )

int main() {

   cout << PI << endl;

   OUT << SQR(5) << endl; 

   OUT << TOSTR(Hello) << endl;

   OUT << MAX(10, 20) << endl;

   return 0;
}
