#include <iostream>

class Config {
protected:
	static Config* instance;
	Config(void) {
		std::cout << "생성되었습니다." << "\n";
	}

	~Config(void) {
		std::cout << "삭제되었습니다." << "\n";
	}
public:
	static Config* getInstance(void) {
		if (instance == NULL)
			instance = new Config();
		
		std::cout << "반환되었습니다." << "\n";
		return instance;
	}
};

class Env : public Config {
public:
	void setting(void) {
		std::cout << "시스템 환경을 설정합니다." << "\n";
	}
	static Env* getInstance(void) {
		return (Env *)Config::getInstance();
	}
};

Config* Config::instance = NULL;

int main(void) {
	Config *first = Config::getInstance();
	Config *second = Config::getInstance();
	Env *third = Env::getInstance();
	third->setting();
}