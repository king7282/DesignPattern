#include <iostream>
#include <string>

class Hello abstract {
public:
	virtual std::string greeting(void) = 0;
};

class Korean : public Hello {
public:
	std::string greeting(void) {
		return "안녕하세요";
	}
};

class English : public Hello {
public:
	std::string greeting(void) {
		return "hello";
	}
};

class Language abstract {
protected:
	Hello* _language;
public:
	virtual std::string greeting(void) = 0;
};

class Message : public Language {
public:
	Message(Hello *language) {
		_language = language;
	}

	std::string greeting(void) {
		return _language->greeting();
	}
};

int main(void) {
	std::string input;
	std::cin >> input;
	Language* language;

	if (input == "Korean")
		language = new Message(new Korean());
	else
		language = new Message(new English());

	std::cout << language->greeting();
}