#include <iostream>
#include <string>

class Component abstract {
public:
	virtual std::string product(void) = 0;
	virtual int price(void) = 0;
};

class Product1 : public Component {
public:
	std::string product(void) {
		return "원피스";
	}

	int price(void) {
		return 20000;
	}
};

class Product2 : public Component {
public:
	std::string product(void) {
		return "블라우스";
	}
	int price(void) {
		return 25000;
	}
};

class Decorate abstract : public Component {
public:
	virtual std::string product(void) = 0;
	virtual int price(void) = 0;
};

class i7 : public Decorate {
private:
	Component *_base;
public:
	i7(Component *base) {
		_base = base;
	}

	std::string product(void) {
		return _base->product() + ",i7";
	}

	int price(void) {
		return _base->price() + 475000;
	}
};

class ssd256 : public Decorate {
private:
	Component *_base;
public:
	ssd256(Component *base) {
		_base = base;
	}

	std::string product(void) {
		return _base->product() + ",ssd256";
	}

	int price(void) {
		return _base->price() + 110000;
	}
};

int main(void) {
	Component *p = new Product1();
	Decorate *p_i7 = new i7(p);
	Decorate *p_ssd256 = new ssd256(p_i7);

	std::cout << "스펙 = " << p->product() << "\n";
	std::cout << "가격 = " << p->price() << "\n";
	
	std::cout << "스펙 = " << p_i7->product() << "\n";
	std::cout << "가격 = " << p_i7->price() << "\n";

	std::cout << "스펙 = " << p_ssd256->product() << "\n";
	std::cout << "가격 = " << p_ssd256->price() << "\n";
}