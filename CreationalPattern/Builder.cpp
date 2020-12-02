#include <iostream>
#include <string>
#include <vector>

class Memory {
private:
	int _size;
public:
	Memory(int size = 0) : _size(size) {}

	int getSize(void) {
		return _size;
	}

	void setSize(int size) {
		_size = size;
	}
};

class Storage {
private:
	int _size;
public:
	Storage(int size = 0) : _size(size) {}

	int getSize(void) {
		return _size;
	}

	void setSize(int size) {
		_size = size;
	}
};

class Computer {
public:
	std::string _CPU;
	std::vector<Memory *> _RAM;
	std::vector<Storage *> _storage;

	int memory(void) {
		int size = 0;
		for (int i = 0; i < _RAM.size(); i++) {
			size += _RAM[i]->getSize();
		}
		return size;
	}

	int storage(void) {
		int size = 0;
		for (int i = 0; i < _storage.size(); i++) {
			size += _storage[i]->getSize();
		}
		return size;
	}
};

class Algorism abstract {
protected:
	Computer *_composite;
public:
	virtual Algorism *setCPU(std::string CPU) = 0;
	virtual Algorism *setRAM(int size) = 0;
	virtual Algorism *setStorage(int size) = 0;

	Computer *getInstance(void) {
		return _composite;
	}
};

class ProductModel : public Algorism {
public:
	ProductModel(void) {
		std::cout << "Computer Create!!\n";
		_composite = new Computer();
	}

	Algorism *setCPU(std::string CPU) {
		std::cout << "Computer CPU : " << CPU << "\n";
		_composite->_CPU = CPU;
		return this;
	}

	Algorism *setRAM(int size) {
		std::cout << size << " SIZE RAM is attached\n";
		_composite->_RAM.push_back(new Memory(size));
		return this;
	}

	Algorism *setStorage(int size) {
		std::cout << size << " SIZE Storage is attached\n";
		_composite->_storage.push_back(new Storage(size));
		return this;
	}
};

class Builder abstract {
protected:
	Algorism *_algorism;

public:
	void setAlgoritsm(Algorism *algoritsm) {
		_algorism = algoritsm;
	}

	Algorism *getAlgoritsm(void) {
		return _algorism;
	}

	Computer *getInstance(void) {
		return _algorism->getInstance();
	}

	virtual Builder *build(void) = 0;
};

class Factory : public Builder {
public:
	Factory(Algorism *algorism = NULL) {
		if (algorism != NULL)
			_algorism = algorism;
	}

	Builder *build(void) {

		std::cout << "Computer Building Now!!\n";

		_algorism->setCPU("i7");
		
		_algorism->setRAM(8)->setRAM(8);
		
		_algorism->setStorage(256)->setStorage(512);

		std::cout << "Computer Building Finish!!\n";
		return this;
	}
};

int main(void) {
	Builder *builder = new Factory(new ProductModel());
	Computer *computer = builder->build()->getInstance();

	std::cout << "CPU : " << computer->_CPU << "\n";
	std::cout << "RAM Size : " << computer->memory() << "\n";
	std::cout << "Storage Size : " << computer->storage() << "\n";
}