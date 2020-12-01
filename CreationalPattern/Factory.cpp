#include <iostream>
#include <string>

class Language {
public:
	virtual std::string text(void) {
		return "안녕하세요";
	}
};

class Korean : public Language {
public:
	std::string text(void) override {
		return "안녕하세요";
	}
};

class English : public Language {
public:
	std::string text(void) override {
		return "Hello";
	}
};

class Factory {
public:
	enum Language_type{
		KOREAN,
		ENGLISH
	};

	static Language* getInstance(Language_type type) {
		switch (type) {
		case KOREAN:
			return new Korean();
		case ENGLISH:
			return new English();
		}
	}
};

class Hello {
public:
	std::string greeting(Factory::Language_type type) {
		return Factory::getInstance(type)->text();
	}
};

int main(void) {
	Hello hello;
	std::cout << hello.greeting(Factory::Language_type::KOREAN) << "\n";
	std::cout << hello.greeting(Factory::Language_type::ENGLISH) << "\n";
}

