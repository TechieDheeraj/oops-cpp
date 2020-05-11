#include <iostream>
#include <vector>

// Interface Segregation Principle
// No Client should be forced to depend on 

struct Document;

struct IMachine { // Machine Interface
	virtual void print(std::vector<Document*> docs) = 0;
	virtual void scan(std::vector<Document*> docs) = 0;
	virtual void fax(std::vector<Document*> docs) = 0;
};

/*
	NOTE:

	In Below Code Machine has all the functionalities which end Client might not even Use it.
	It is violating the ISP Principle.
	The Idea is Divide the Interfaces into Smaller Interfaces So that Client can have the only
	Code which is required.
*/

struct MFP : IMachine {
	void print(std::vector<Document*> docs) override;
	void scan(std::vector<Document*> docs) override;
	void fax(std::vector<Document*> docs) override;
};

struct IPrinter {
	virtual void print(std::vector<Document*> docs) = 0;
};

struct IScan {
	virtual void scan(std::vector<Document*> docs) = 0;
};
	
struct IFax {
	virtual void fax(std::vector<Document*> docs) = 0;
};

struct Printer : IPrinter {
	void print(std::vector<Document*> docs) override;
};

struct Scanner : IScanner {
	void scan(std::vector<Document*> docs) override;
};

struct Faxing : IFax {
	void fax(std::vector<Document*> docs) override;
};

// If the Client Machine with Specific fucntionalities, we can provide custom machine

struct IMachine : IPrinter, IScanner {};

struct Machine : IMachine { // Decorator
	IPrinter& printer;
	IScanner& scanner;

	Machine(IPrinter& printer, IScanner& scanner) : printer{printer}, scanner{scanner} { 
	}

	void print(std::vector<Document*> docs) override {
		printer.print(docs);
	}
	void scan(std::vector<Document*> docs) override {
		scanner.scan();
	}
};
