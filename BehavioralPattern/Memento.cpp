#include <iostream>
#include <string>
#include <stack>

class Hello {
private:
	std::string _msg;
public:
	Hello(std::string msg) {
		_msg = msg;
	}

	void setMessage(std::string msg) {
		_msg = msg;
	}

	std::string getMessage(void) {
		return _msg;
	}

	Hello *clone(void) {
		return new Hello(_msg);
	}
};

class Memento {
protected:
	Hello *_obj;
public:
	Memento(Hello *obj) {
		_obj = obj->clone();
	}

	Hello *getObj(void) {
		return _obj;
	}
};

class Originator {
protected:
	Hello *_state;
public:
	void setState(Hello *state) {
		_state = state;
	}

	Hello *getState(void) {
		return _state;
	}

	Memento *create(void) {
		return new Memento(_state);
	}

	void restore(Memento *memento) {
		_state = memento->getObj()->clone();
	}
};

class CareTaker {
protected:
	std::stack<Memento *> _stack;
public:
	void push(Originator *origin) {
		_stack.push(origin->create());
	}

	Hello *undo(Originator *origin) {
		if (_stack.size() == 0)
			return NULL;

		origin->restore(_stack.top());
		_stack.pop();

		return origin->getState();
	}
};

int main(void) {
	Hello *hello = new Hello("안녕하세요");
	Originator *origin = new Originator();
	CareTaker *care = new CareTaker();
	
	std::cout << hello->getMessage() << "\n";

	origin->setState(hello);
	care->push(origin);
	hello->setMessage("Hi, Nice to meet you");
	std::cout << hello->getMessage() << "\n";
	
	origin->setState(hello);
	care->push(origin);
	hello->setMessage("Guten Tag!");
	std::cout << hello->getMessage() << "\n";

	hello = care->undo(origin);
	std::cout << hello->getMessage() << "\n";

	hello = care->undo(origin);
	std::cout << hello->getMessage() << "\n";
}