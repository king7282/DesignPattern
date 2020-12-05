#include <iostream>
#include <string>
#include <map>

class Flyweight abstract {
public:
	virtual void code(void) = 0;
};

class MorseG : public Flyweight {
public:
	void code(void) {
		std::cout << "**-* ";
	}
};

class MorseO : public Flyweight {
public:
	void code(void) {
		std::cout << "--- ";
	}
};

class MorseL : public Flyweight {
public:
	void code(void) {
		std::cout << "*-** ";
	}
};

class MorseE : public Flyweight {
public:
	void code(void) {
		std::cout << "* ";
	}
};

class Factory {
private:
	std::map<char, Flyweight *> pool;
public:
	Flyweight *getCode(char input) {
		if (pool.find(input) == pool.end()) {
			switch (input) {
			case 'g':
				pool[input] = new MorseG();
				break;
			case 'o':
				pool[input] = new MorseO();
				break;
			case 'l':
				pool[input] = new MorseL();
				break;
			case 'e':
				pool[input] = new MorseE();
				break;
			}
		}

		return pool[input];
	}
};

int main(void) {
	Factory *share = new Factory();
	std::string name = "goooogllleee";

	for (int i = 0; i < name.size(); i++) {
		share->getCode(name[i])->code();
		std::cout << "\n";
	}
}