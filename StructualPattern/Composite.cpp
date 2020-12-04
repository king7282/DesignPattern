#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <typeinfo>

class Component abstract{
public:
	enum Type {
		LEAF = 0,
		COMPOSITE
	};
private:
	std::string _name;
	Type _type;
protected:
	void setType(Type type) {
		_type = type;
	}
public:
	void setName(std::string name) {
		_name = name;
	}

	std::string getName(void) {
		return _name;
	}

	Type getType(void) {
		return _type;
	}
};

class Leaf : public Component {
private:
	std::string _data;
public:
	Leaf(std::string name) {
		setName(name);
		setType(Type::LEAF);
	}

	std::string getData(void) {
		return _data;
	}

	void setData(std::string data) {
		_data = data;
	}
};

class Composite : public Component {
private:
	std::map<std::string, Component *> _children;
public:
	Composite(std::string name) {
		setName(name);
		setType(Type::COMPOSITE);
	}

	void addNode(Component *folder) {
		_children[folder->getName()] = folder;
	}

	void removeNode(Component *folder) {
		_children.erase(folder->getName());
	}

	Component *getNode(std::string name) {
		return _children[name];
	}

	std::vector<std::string> getNodeList(void) {
		std::vector<std::string> result;
		for (auto it = _children.begin(); it != _children.end(); it++)
			result.push_back(it->first);

		return result;
	}
};

void tree_traversal(Component *node) {
	std::cout << "Component Name : " << node->getName() << ", ";
	if (node->getType() == Component::Type::LEAF) {
		std::cout << "Type : Leaf, Data : " << ((Leaf *)node)->getData() << "\n";
	}
	else {
		std::cout << "Type : Composite, Children : ";
		std::vector<std::string> children = ((Composite *)node)->getNodeList();

		for (int i = 0; i < children.size(); i++) {
			std::cout << children[i] << " ";
		}
		if (children.size() == 0)
			std::cout << "None\n";
		else
			std::cout << "\n";

		for (int i = 0; i < children.size(); i++) {
			tree_traversal(((Composite *)node)->getNode(children[i]));
		}
	}
}

int main(void) {
	Composite *root = new Composite("root");
	Composite *home = new Composite("home");
	Composite *jyj = new Composite("jyj");
	Composite *khs = new Composite("khs");
	Composite *users = new Composite("users");
	Composite *temp = new Composite("temp");
	
	Leaf *img1 = new Leaf("img1");
	Leaf *img2 = new Leaf("img2");
	Leaf *img3 = new Leaf("img3");
	Leaf *img4 = new Leaf("img4");
	Leaf *img5 = new Leaf("img5");

	img1->setData("Hi");
	img2->setData("My name is");
	img3->setData("Yeongjun");
	img4->setData("Joo");
	img5->setData("Nice to meet you");

	root->addNode(home);
	root->addNode(users);
	users->addNode(jyj);
	users->addNode(khs);
	jyj->addNode(img1);
	jyj->addNode(img2);
	jyj->addNode(img3);
	jyj->addNode(img4);
	home->addNode(temp);
	temp->addNode(img5);

	tree_traversal(root);
}