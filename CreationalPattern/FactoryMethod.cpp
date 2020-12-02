#include <iostream>

class IProduct abstract {
public:
	virtual void name(void) = 0;
};

class Factory abstract {
public:
	IProduct* create(int type) {
		return createProduct(type);
	}
	virtual IProduct* createProduct(int type)=0;
};

class LgProduct : public IProduct{
public:
	void name(void) {
		std::cout << "LG gram labtop\n";
	}
};

class SamsungProduct : public IProduct{
public:
	void name(void) {
		std::cout << "Samsung Always labtop\n";
	}
};

class ProductFactory : public Factory {
public:
	IProduct* createProduct(int type) {
		if (type == 0)
			return new LgProduct();
		else if (type == 1)
			return new SamsungProduct();
		else
			return NULL;
	}
};

int main(void) {
	Factory *factory = new ProductFactory();
	IProduct* product = factory->create(0);

	product->name();
	delete product;

	product = factory->create(1);
	product->name();

	product = factory->create(2);
	if (product == NULL)
		std::cout << "product variable is NULL\n";
	else
		product->name();
}