#include <iostream>
#include <string>
#include <vector>

template <typename T>
class PloyIterator abstract{
public:
	virtual bool isNext(void) = 0;
	virtual T next(void) = 0;
};

template <typename T>
class Aggregate abstract {
public:
	virtual PloyIterator<T> *iterator(void) = 0;
	virtual int getLast(void) = 0;
	virtual T getObj(int id) = 0;
	virtual void append(T obj) = 0;
};

template <typename U>
class IteratorObject : public PloyIterator<U> {
private:
	Aggregate<U> *_aggregate;
	int _index;
public:
	IteratorObject(Aggregate<U> *aggregate) {
		_aggregate = aggregate;
		_index = 0;
	}

	bool isNext(void) {
		return _index < _aggregate->getLast();
	}

	U next(void) {
		return _aggregate->getObj(_index++);
	}
};

template <typename U>
class Collection : public Aggregate<U> {
private:
	std::vector<U> _objs;
public:
	U getObj(int id) {
		return _objs[id];
	}

	int getLast(void) {
		return _objs.size();
	}

	void append(U obj) {
		_objs.push_back(obj);
	}

	PloyIterator<U> *iterator(void) {
		return new IteratorObject<U>(this);
	}
};

class Fruit {
private:
	std::string _name;
public:
	Fruit(std::string name) {
		_name = name;
	}

	std::string getName(void) {
		return _name;
	}
};

int main(void) {
	Collection<Fruit *> *collection = new Collection<Fruit *>();

	collection->append(new Fruit("Apple"));
	collection->append(new Fruit("Banana"));
	collection->append(new Fruit("Berry"));
	collection->append(new Fruit("Grape"));

	PloyIterator<Fruit *> *it = collection->iterator();
	while (it->isNext()) {
		std::cout << it->next()->getName() << "\n";
	}
}