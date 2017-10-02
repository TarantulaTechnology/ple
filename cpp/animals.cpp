#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
using namespace std;

class Animal {
protected:
  string name;
  virtual string sound() = 0;
public:
  Animal(string name): name(name) {}
  string speak() {
    return (std::stringstream() << name << " says " << sound()).str();
  }
};

class Cow: public Animal {
protected:
  string sound() {
    return "moooo";
  }
public:
  Cow(string name): Animal(name) {}
};

class Horse: public Animal {
protected:
  string sound() {
    return "neigh";
  }
public:
  Horse(string name): Animal(name) {}
};

class Sheep: public Animal {
protected:
  string sound() {
    return "baaaa";
  }
public:
  Sheep(string name): Animal(name) {}
};

#include <cassert>
int main(int, char**) {
  Animal* h = new Horse("CJ");
  assert(h->speak() == "CJ says neigh");
  Animal* c = new Cow("Bessie");
  assert(c->speak() == "Bessie says moooo");
  assert((new Sheep("Little Lamb"))->speak() == "Little Lamb says baaaa");
}
