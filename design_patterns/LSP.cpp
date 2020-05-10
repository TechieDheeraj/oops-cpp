#include<iostream>

// Liskov Substitution Principle

class Rectangle {
   
protected:
   int width, height;
public:
   Rectangle(const int width, const int height) : width{width}, height{height} {
   }

   virtual int getWidth() const { // Inspectors -> Can't modify (this)
      return width;
   }
   virtual int getHeight() const {
      return height;
   }
   virtual void setWidth(const int width) { // Mutators
      this->width = width;
   }
   virtual void setHeight(const int height) {
      this->height = height;
   }

   int Area() const { return width * height; } 
};

class Square : public Rectangle {

protected:
   int size;
public:  
   Square(int size) : Rectangle(size, size) { } // Constructor

   void setWidth(const int width) override {
      this->width = height = width;
   }

   void setHeight(const int height) override {
      this->height = width = height;
   }
};

void process(Rectangle& r) {
   int w = r.getWidth();
   r.setHeight(10); // Violation of LSP because in case of Derived class object this code is misbehaving

   std::cout << " Area should be " << (w * 10)
      << " , got " << r.Area() << std::endl;
}

int main() {
   Rectangle obj(5, 5);
   process(obj);

   Square s(5);
   process(s);

   return 0;
}
