#include<iostream>

using namespace std;

/*
   NOTE:
      1. Creating Nested Class
*/

class LinkList { // Outer Class

   public: //

      void printData() {
         cout << "Data from Outer class " << head->data << endl; // Outer Class Can access the members of inner class using Object

         head->printData();
      }

      class Node { // Inner class
         
         public:

            int data;
            Node *next;

            void printData() {
               cout << "Data from Inner class " << data << endl;
            }
      };
   
      Node *head = new Node; // Create Object of Inner Class

//    head->data = 20;  <---- This is Invalid, Can't do initialisation directly in Class

      LinkList() {
         head->data = 20;
      }
};

int main() {

   LinkList obj;

   obj.printData();

   LinkList::Node *node = new LinkList::Node; // Can Create Object of Inner Class if it is exposed means written inside public in Outer Class

   node->data = 30;

   node->printData();
   
   return 0;
}
