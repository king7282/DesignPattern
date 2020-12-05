#include <iostream>

class Package1 {
public:
	void process(void) {
		std::cout << "Package1 Process Start!\n";
	}
};

class Package2 {
public:
	void process(void) {
		std::cout << "Package2 Process Start!\n";
	}
};

class Package3 {
public:
	void process(void) {
		std::cout << "Package3 Process Start!\n";
	}
};

class Facade {
private:
	Package1 *_package1;
	Package2 *_package2;
	Package3 *_package3;
public:
	Facade(void) {
		_package1 = new Package1();
		_package2 = new Package2();
		_package3 = new Package3();
	}

	void processAll(void) {
		_package1->process();
		_package2->process();
		_package3->process();
	}
};

int main(void) {
	Facade *facade = new Facade();
	facade->processAll();
}