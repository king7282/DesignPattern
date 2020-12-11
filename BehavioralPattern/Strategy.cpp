#include <iostream>

class Weapon abstract {
public:
	virtual void attack(void) = 0;
};

class Knife : public Weapon {
public:
	void attack(void) {
		std::cout << "칼 공격합니다.\n";
	}
};

class Gun : public Weapon {
public:
	void attack(void) {
		std::cout << "총 발포합니다.\n";
	}
};

class Strategy abstract {
protected:
	Weapon *_delegate;
public:
	Strategy(void) {
		_delegate = NULL;
	}

	void setWeapon(Weapon *weapon) {
		_delegate = weapon;
	}

	virtual void attack(void) = 0;
};

class Charactor : public Strategy {
public:
	void attack(void) {
		if (_delegate == NULL)
			std::cout << "맨손 공격합니다.\n";
		else
			_delegate->attack();
	}
};

int main(void) {
	Charactor *charactor = new Charactor();
	charactor->attack();

	charactor->setWeapon(new Gun());
	charactor->attack();
}