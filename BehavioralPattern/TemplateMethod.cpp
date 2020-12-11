#include <iostream>
#include <string>

class SandWich abstract {
protected:
	virtual std::string bread(void) = 0;
	virtual std::string jam(void) = 0;
public:
	std::string make(void) {
		std::string food = bread();

		food += " + ";
		food += jam();

		food += " + ";
		food += bread();

		return food;
	}
};

class Strawberry : public SandWich {
protected:
	std::string bread(void) {
		return "식빵";
	}
	std::string jam(void) {
		return "딸기잼";
	}
};

class StrawberryBagle : public SandWich {
protected:
	std::string bread(void) {
		return "베이글";
	}
	std::string jam(void) {
		return "딸기잼";
	}
};

int main(void) {
	SandWich *first = new Strawberry(), *second = new StrawberryBagle();

	std::cout << first->make() << "\n";
	std::cout << second->make() << "\n";
}