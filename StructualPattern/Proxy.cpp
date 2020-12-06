#include <iostream>
#include <string>

class Subject abstract {
public:
	virtual std::string action1(void) = 0;
	virtual std::string action2(void) = 0;
};

class RealSubject : public Subject {
public:
	std::string action1(void) {
		return "action1 function call!!";
	}

	std::string action2(void) {
		return "action2 function call!!";
	}
};

class Proxy : public Subject {
private:
	Subject *_object;
public:
	Proxy(Subject *object) {
		_object = object;
	}

	std::string action1(void) {
		return "proxy action1 function call!!";
	}

	std::string action2(void) {
		return _object->action2();
	}
};

int main(void) {
	Subject *subject = new Proxy(new RealSubject());
	std::cout << subject->action1() << "\n";
	std::cout << subject->action2() << "\n";
}