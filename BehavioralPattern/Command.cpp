#include <iostream>
#include <map>

class Command abstract {
public:
	virtual void execute(void) = 0;
	virtual void undo(void) = 0;
};

class Invoker {
private:
	std::map<int, Command *> _cmd;
public:
	void setCommand(int key, Command *command) {
		_cmd[key] = command;
	}

	void removeCommand(int key) {
		_cmd.erase(key);
	}

	void execute(int key) {
		if (_cmd.find(key) != _cmd.end())
			_cmd[key]->execute();
	}

	void undo(int key) {
		if (_cmd.find(key) != _cmd.end())
			_cmd[key]->undo();
	}
};

class Exec1 : public Command {
public:
	void execute(void) {
		std::cout << "Exec1 command execute!!\n";
	}

	void undo(void) {
		std::cout << "Exec1 command undo!!\n";
	}
};

class Exec2 : public Command {
public:
	void execute(void) {
		std::cout << "Exec2 command execute!!\n";
	}

	void undo(void) {
		std::cout << "Exec2 command undo!!\n";
	}
};

int main(void) {
	Invoker *invoker = new Invoker();
	int index = 0;

	invoker->setCommand(index++, new Exec1());
	invoker->setCommand(index++, new Exec2());
	invoker->setCommand(index++, new Exec2());
	invoker->setCommand(index++, new Exec1());

	invoker->removeCommand(2);

	for (int i = 0; i < index; i++) {
		invoker->execute(i);
	}

	for (int i = 0; i < index; i++) {
		invoker->undo(i);
	}
}