#include<string>
#include<vector>
#include<fstream>

struct Journel {

	std::string title;
	std::vector<std::string> entries;
	
	explicit Journel(const std::string& title) : title{title} { } // Uniform Intialization using Initialization list

	void add(const std::string& entry) {
		entries.push_back(entry);	
	}

/*
	This is the Voilation of SRP ( Single Responsibility Principle):
		As Journel Entity has one Job To add the Entries but We also adding Save to File
		functionality which is wrong because if in future we decide to save in some other format
		so we have to change the Journel Entity and recompile and we can have seperate entity
		to do the saving Job like PersistanceManger so that each Entity have single responsibilty.

	void save(const std::string& filename) {
	
		std::ofstream ofs(filename);
		for(auto &s: entries)
			ofs << s << std::endl;
	}
*/
};

struct PersitanceManger {
	
	static void save(struct Journel& j, const std::string& filename) {
	
		std::ofstream ofs(filename);
		for(auto &s: j.entries)
			ofs << s << std::endl;
	}
};
