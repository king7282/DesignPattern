#include <iostream>
#include <vector>
#include <string>

class Mediator;

class Colleague abstract {
protected:
	std::string _name;
	Mediator *_mediator;
public:
	void setMediator(Mediator *mediator) {
		_mediator = mediator;
	}

	std::string getName(void) {
		return _name;
	}

	virtual void message(std::string data) = 0;
};

class Mediator abstract {
protected:
	std::vector<Colleague *> _colleague;
public:
	void addColleague(Colleague *obj) {
		_colleague.push_back(obj);
	}

	virtual void createColleague(void) = 0;
	virtual void mediate(std::string data, Colleague *user) = 0;
};

class Server : public Mediator {
public:
	void createColleague(void) {
	}

	void mediate(std::string data, Colleague *user) {
		std::cout << user->getName() << "로부터 서버 메세지를 받았습니다.\n";

		for (int i = 0; i < _colleague.size(); i++) {
			_colleague[i]->message(data);
		}
	}
};

class User : public Colleague {
public:
	User(std::string name) {
		_name = name;
	}

	void send(std::string data) {
		std::cout << _name << "이 " << data << "라는 데이터를 전송합니다.\n";
		_mediator->mediate(data, this);
	}

	void message(std::string data) {
		std::cout << _name << " : " << data << "\n";
	}
};

int main(void) {
	Mediator *mediator = new Server();
	User *jyj = new User("jyj");
	User *khs = new User("khs");
	User *kjg = new User("kjg");

	jyj->setMediator(mediator);
	khs->setMediator(mediator);
	kjg->setMediator(mediator);

	mediator->addColleague(jyj);
	mediator->addColleague(khs);
	mediator->addColleague(kjg);

	jyj->send("Hi, My name is jyj");
	
}