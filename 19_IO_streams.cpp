#include<iostream>
#include<fstream>

using namespace std;

class Student {
   public:
      string name;
      int rollno;
      string branch;

      friend ofstream &operator<<(ofstream &ofstrm, Student &stu); 
      friend ifstream &operator>>(ifstream &ifstrm, Student &stu);
      friend ostream &operator<<(ostream &ostrm, Student &stu);
};

ofstream &operator<<(ofstream &ofstrm, Student &stu) {

   ofstrm << stu.name << endl;
   ofstrm << stu.rollno << endl;
   ofstrm << stu.branch << endl;

   return ofstrm;
}

ifstream &operator>>(ifstream &ifstrm, Student &stu) {

   ifstrm >> stu.name;
   ifstrm >> stu.rollno;
   ifstrm >> stu.branch;

   return ifstrm;
}

ostream &operator<<(ostream &ostrm, Student &stu) {

   ostrm << "Name: " << stu.name << endl;
   ostrm << "Roll No: " << stu.rollno << endl;
   ostrm << "Branch : " << stu.branch << endl;

   return ostrm;
}

int main() {

/*
   NOTE:
      ofstream -> To Write into File
      ifstream -> To Read from File
*/
   string str;
   int x;

   ofstream outfile("demo.txt"); // By default create new file, if already existed will truncate the content with default mode ios::truc 

   outfile << "Hello" << endl;
   outfile << 30 << endl;
   outfile.close();

   ofstream outsfile("demo.txt", ios::app); // Append into same file as mode ios::app is used

   outsfile << "Appending into file" << endl;
   outsfile.close();

   ifstream infile;

   infile.open("demo.txt");

   if (!infile.is_open())
      cout << "File does not exist " << endl;

   infile >> str;
   infile >> x;
   infile >> str;

   if (infile.eof())
      cout << "End of File reached" << endl;

   infile.close();

   cout << "First line is " << str << endl;
   cout << "Second line is " << x << endl;

/**************************************************************/

   Student s1;
   Student s2;
   Student s3;

   s1.name="Dheeraj";
   s1.rollno=21;
   s1.branch="ECE";

   ofstream stu1file("student.txt", ios::trunc);

   stu1file << s1.name << endl;
   stu1file << s1.rollno << endl;
   stu1file << s1.branch << endl;

   stu1file.close();

   s2.name = "Neeraj";
   s2.rollno=22;
   s2.branch="ECE";

   ofstream stu2file("student.txt", ios::app);
   stu2file << s2 << endl;
   stu2file.close();

   ifstream stu3file("student.txt");
   stu3file >> s3;
   cout << s3;

   stu3file >> s3;
   cout << s3;

   int value = 16;
   float val = 38.52;

   cout << value << endl; // endl is called as Manipulators
   cout << hex << value << endl; // hex, oct, dec are called as Manipulators
   cout << oct << value << endl;
   cout << dec << value << endl;

   cout << fixed << val << endl;  // For float numbers: fixed, scientific are called as Manipulators
   cout << scientific << val << endl;

//   cout << set(10) << "Hello" << endl; // set manipulator to provide space b/w string
//   cout << 30 << ws << 40 << endl; // ws manipulator to provide whitespace b/w 30 and 40

   return 0;
}
