#include <iostream>
#include <string>
#include <vector>

class Observer abstract {
protected:
	std::string _name;
public:
	virtual void update(void) = 0;
	std::string getName(void) {
		return _name;
	}
};

class Subject abstract {
public:
	virtual void addObserver(Observer *o) = 0;
	virtual void deleteObserver(std::string name) = 0;
	virtual void notifyObserver(void) = 0;
};

class Member : public Subject {
private:
	std::vector<Observer *> _objs;
public:
	void addObserver(Observer *o) {
		_objs.push_back(o);
	}

	void deleteObserver(std::string name) {
		for (int i = 0; i < _objs.size(); i++) {
			if (_objs[i]->getName() == name) {
				_objs.erase(_objs.begin() + i);
				break;
			}
		}
	}

	void notifyObserver(void) {
		for (int i = 0; i < _objs.size(); i++) {
			_objs[i]->update();
		}
	}
};

class UserA : public Observer {
public:
	UserA(std::string name) {
		_name = name;
	}

	void update(void) {
		std::cout << _name << " is now updated!!\n";
	}
};

class UserB : public Observer {
public:
	UserB(std::string name) {
		_name = name;
	}

	void update(void) {
		std::cout << _name << " is now updated!!\n";
	}
};

class UserC : public Observer {
public:
	UserC(std::string name) {
		_name = name;
	}

	void update(void) {
		std::cout << _name << " is now updated!!\n";
	}
};

int main(void) {
	Subject *subject = new Member();

	subject->addObserver(new UserA("jyj"));
	subject->addObserver(new UserB("khs"));
	subject->addObserver(new UserC("kjg"));

	subject->deleteObserver("khs");

	subject->notifyObserver();
}