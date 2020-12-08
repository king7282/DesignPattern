#include <iostream>
#include <string>
#include <vector>

class Chain abstract {
protected:
	Chain *_next;

public:
	Chain *setNext(Chain *next) {
		_next = next;
		return _next;
	}

	virtual std::string execute(std::string e) = 0;
};

class Order : public Chain {
public:
	std::string execute(std::string e) {
		if (e == "Order") {
			return "주문을 처리합니다.";
		}

		if (_next != NULL)
			return _next->execute(e);
		else
			return "동작이 없습니다.";
	}
};

class Cancel : public Chain {
public:
	std::string execute(std::string e) {
		if (e == "Cancel") {
			return "주문을 취소합니다.";
		}

		if (_next != NULL)
			return _next->execute(e);
		else
			return "동작이 없습니다.";
	}
};

class Insert : public Chain {
public:
	std::string execute(std::string e) {
		if (e == "Insert") {
			return "주문을 추가합니다.";
		}

		if (_next != NULL)
			return _next->execute(e);
		else
			return "동작이 없습니다.";
	}
};

class Handler {
private:
	Chain *_first;
public:
	Handler(void) {
		Chain *cur;

		_first = new Order();
		cur = _first;

		cur = cur->setNext(new Cancel());
		cur = cur->setNext(new Insert());
	}

	std::string execute(std::string e) {
		return _first->execute(e);
	}
};

int main(void) {
	Handler *handler = new Handler();

	std::cout << handler->execute("Order") << "\n";
	std::cout << handler->execute("Cancel") << "\n";
	std::cout << handler->execute("Insert") << "\n";
	std::cout << handler->execute("Remove") << "\n";

}