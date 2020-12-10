#include <iostream>
#include <map>
#include <string>

class State abstract {
public:
	virtual void process(void) = 0;
};

class StateOrder : public State {
public:
	void process(void) {
		std::cout << "Order starts!!\n";
	}
};

class StatePay : public State {
public:
	void process(void) {
		std::cout << "Pay starts!!\n";
	}
};

class StateOrdered : public State {
public:
	void process(void) {
		std::cout << "Order is finished!!\n";
	}
};

class StateFinish : public State {
public:
	void process(void) {
		std::cout << "All process are finished!!\n";
	}
};

class Shop {
private:
	std::map<std::string, State *> _state;
public:
	Shop(void) {
		_state["ORDER"] = new StateOrder();
		_state["PAY"] = new StatePay();
		_state["ORDERED"] = new StateOrdered();
		_state["FINISH"] = new StateFinish();
	}

	void process(std::string status) {
		if (_state.find(status) == _state.end())
			std::cout << status << "'s process is not found\n";
		else
			_state[status]->process();
	}
};

int main(void) {
	Shop *shop = new Shop();
	shop->process("ORDER");
	shop->process("PAY");
	shop->process("ORDERED");
	shop->process("FINISH");
	shop->process("LOGOUT");
}