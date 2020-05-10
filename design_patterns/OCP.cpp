#include<string>
#include<vector>
#include<iostream>

enum class Color {Red, Green, Blue};
enum class Size {Small, Medium, Large};

struct Product {
	std::string name;
	Color color;
	Size size;
}; 

struct Productfilter {
	
	typedef std::vector<Product *> Items;

// One requirement comes to filter Products by color
	
	static Items by_color(Items items, Color color) {
		
		Items result;
		for (auto &i : items) {
			if ( i->color == color)
				result.push_back(i);
		}
		return result;
	}

// One more requirement comes to filter Products by Size

	static Items by_size(Items items, Size size) {
	
		Items result;
		
		for (auto &i : items) {
			if (i->size == size)
				result.push_back(i);
		}
		return result;
	}
	
/*
One more requirement comes to filter Products by Color and Size
	Note:
		Every Time new requirement comes we are modifying the existing class and we have to again retest
		previously implemented functions and also it is violating the OCP principle of SOLID.
		
		Class should be open for extenstion not for modification, So Below we are going to implement
			"Specification Design Pattern" to fix this problem
*/

	static Items by_color_and_by_size(Items items, Color color, Size size) {
	
		Items result;
		
		for (auto &i : items) {
			if (i->size == size && i->color == color)
				result.push_back(i);
		}
		return result;
	}
};
 // ******** Specification Pattern ********
 // This Pattern is used in Data Access

template <typename T> struct ISpecification { // Specification Interface
	
	virtual bool is_satisfied(T* item) = 0;
};

template <typename T> struct AndSpecification : ISpecification<T> {
   
   ISpecification<T>& first;
   ISpecification<T>& second;

   AndSpecification(ISpecification<T>& first, ISpecification<T>& second) : first{first}, second{second} { }
   
   bool is_satisfied(T* item) override {
      return first.is_satisfied(item) && second.is_satisfied(item);
   }
};

template<typename T> struct OrSpecification : ISpecification<T> {
	ISpecification<T>& first;
	ISpecification<T>& second;

	OrSpecification(ISpecification<T>& first, ISpecification<T>& second) : first{first}, second{second} {
	}

	bool is_satisfied(T *item) override {
		return first.is_satisfied(item) || second.is_satisfied(item);
	}
};

template <typename T> struct IFilter {
	
	virtual std::vector<T*> filter(std::vector<T*> items, ISpecification<T>& spec) = 0; 
};

struct BetterFilter : IFilter<Product> {

	typedef std::vector<Product*> Items;
	std::vector<Product*> filter(std::vector<Product*> items, ISpecification<Product>& spec) override {
		Items result;
		for (auto &i : items) {
			if (spec.is_satisfied(i))
				result.push_back(i);
		}
		return result;
	}
};

struct ColorSpecification : ISpecification<Product> {

	Color color;

	explicit ColorSpecification(const Color color) : color{color} { 
	}

	bool is_satisfied(Product *item) override {
		return item->color == color;
	}
};

struct SizeSpecification : ISpecification<Product> {

	Size size;

	explicit SizeSpecification(const Size size) : size{size} { }

	bool is_satisfied(Product *item) override {
		return item->size == size;
	}
};

int main() {

	Product apple{ "Apple", Color::Red, Size::Small };
	Product tree{ "Tree", Color::Green, Size::Large };
	Product house{ "House", Color::Blue, Size::Large };

	std::vector<Product*> all{ &apple, &tree, &house};

	BetterFilter bf;

	ColorSpecification green(Color::Green);

	auto green_things = bf.filter(all, green);

	for (auto &x: green_things) 
		std::cout << x->name << " is green " << std::endl;

   SizeSpecification big(Size::Large);

   AndSpecification<Product> gAlarge(green, big);

   auto greenALarge = bf.filter(all, gAlarge);

	for (auto &x: greenALarge) 
		std::cout << x->name << " is green and Large " << std::endl;

	OrSpecification<Product> gOlarge(green, big);

	auto greenOLarge = bf.filter(all, gOlarge);

	for(auto &x : greenOLarge)
		std::cout << x->name << " is green or large" << std::endl;

	getchar();
	return 0;
}