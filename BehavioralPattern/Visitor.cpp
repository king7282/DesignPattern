#include <iostream>
#include <string>
#include <vector>

class Visitable;

class Visitor abstract {
public:
	virtual std::string order(Visitable *visitable) = 0;
};

class Visitable abstract {
public:
	enum Type {
		CART = 0
	};
protected:
	Type _type;
public:
	Visitable(Type type) {
		_type = type;
	}

	Type getType(void) {
		return _type;
	}
	virtual std::string accept(Visitor *visitor) = 0;
};

class Product {
protected:
	std::string _name;
	int _price, _num;
public:
	void setName(std::string name) {
		_name = name;
	}

	std::string getName(void) {
		return _name;
	}

	void setPrice(int price) {
		_price = price;
	}

	int getPrice(void) {
		return _price;
	}

	void setNum(int num) {
		_num = num;
	}

	int getNum(void) {
		return _num;
	}

	int getTax(int tax = 10) {
		return (_price * _num) * tax / 100;
	}
};

class Cart : public Product, public Visitable {
public:
	Cart(std::string name, int price, int num) : Visitable(Type::CART) {
		setName(name);
		setPrice(price);
		setNum(num);
	}

	std::string accept(Visitor *visitor) {
		return visitor->order(this);
	}

	std::string list(void) {
		std::string order = _name;
		order += ", 수량 = " + std::to_string(_num);
		order += ", 가격 = " + std::to_string(_price * _num) + " 입니다.\n";
		
		return order;
	}
};

class Visitant : public Visitor {
private:
	int _total, _num;
public:
	Visitant(int total = 0, int num = 0) {
		_total = total;
		_num = num;
	}

	std::string order(Visitable *visitable) {
		std::string msg = "";

		if (visitable->getType() == Visitable::Type::CART) {
			Cart *input = (Cart *)visitable;
			msg += "상품명 : " + input->getName();
			msg += ", 수량 : " + std::to_string(input->getNum());
			msg += ", 가격 : " + std::to_string(input->getPrice() * input->getNum()) + " 입니다.\n";

			_total += input->getPrice() * input->getNum();
			msg += "합계 : " + std::to_string(_total) + "\n";

			_num++;
		}

		return msg;
	}

	int getTotal(void) {
		return _total;
	}

	int getNum(void) {
		return _num;
	}
};

int main(void) {
	Visitant *visitant = new Visitant();
	std::vector<Cart *> list;

	list.push_back(new Cart("컵라면", 900, 3));
	list.push_back(new Cart("아이스크림", 1500, 1));
	list.push_back(new Cart("음료수", 2800, 1));

	for (int i = 0; i < list.size(); i++) {
		std::cout << list[i]->accept(visitant);
	}

	std::cout << "감사합니다. 주문건수 : " << visitant->getNum() << ", 주문 합계 : " << visitant->getTotal() << " 입니다.\n";

}