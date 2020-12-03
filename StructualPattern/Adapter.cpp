#include <iostream>

class Math {
public:
	float twoTime(float num) {
		return num * 2;
	}

	float halfTime(float num) {
		return num / 2;
	}
};

class Adapter abstract {
public:
	virtual int twiceOf(int num) = 0;
	virtual int halfOf(int num) = 0;
};

class Object : public Adapter {
private:
	Math *_adapter;
public:
	Object() {
		_adapter = new Math();
	}

	int twiceOf(int num) {
		return (int)_adapter->twoTime(num);
	}

	int halfOf(int num) {
		return (int)_adapter->halfTime(num);
	}
};

int main(void) {
	Adapter *adapter = new Object();

	std::cout << adapter->twiceOf(10) << "\n";
	std::cout << adapter->halfOf(10) << "\n";
}