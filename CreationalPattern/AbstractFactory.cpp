#include <iostream>

class TireProduct abstract {
public:
	virtual void makeAssemble(void) = 0;
};

class DoorProduct abstract {
public:
	virtual void makeAssemble(void) = 0;
};

class KoreanTireProduct : public TireProduct {
public:
	void makeAssemble(void) {
		std::cout << "한국 타이어 조립!!\n";
	}
};

class KoreanDoorProduct : public DoorProduct {
public:
	void makeAssemble(void) {
		std::cout << "한국 문 조립!!\n";
	}
};

class StateTireProduct : public TireProduct {
public:
	void makeAssemble(void) {
		std::cout << "미국 타이어 조립!!\n";
	}
};

class StateDoorProduct : public DoorProduct {
public:
	void makeAssemble(void) {
		std::cout << "미국 문 조립!!\n";
	}
};

class Factory abstract {
public:
	virtual TireProduct* createTire(void) = 0;
	virtual DoorProduct* createDoor(void) = 0;
};

class KoreanFactory : public Factory {
public:
	TireProduct* createTire(void) {
		return new KoreanTireProduct();
	}
	DoorProduct* createDoor(void) {
		return new KoreanDoorProduct();
	}
};

class StateFactory : public Factory {
public:
	TireProduct* createTire(void) {
		return new StateTireProduct();
	}

	DoorProduct* createDoor(void) {
		return new StateDoorProduct();
	}
};

int main(void) {
	Factory* koreanFactory = new KoreanFactory();
	Factory* stateFactory = new StateFactory();

	TireProduct *koreanTire = koreanFactory->createTire(), *stateTire = stateFactory->createTire();
	DoorProduct *koreanDoor = koreanFactory->createDoor(), *stateDoor = stateFactory->createDoor();

	koreanTire->makeAssemble();
	koreanDoor->makeAssemble();

	stateTire->makeAssemble();
	stateDoor->makeAssemble();
}