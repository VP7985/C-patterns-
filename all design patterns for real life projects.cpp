Singleton Pattern:

1)Intent: Ensure a class has only one instance and provide a global point of access to it.
Example:

class Singleton {
private:
    static Singleton* instance;
    Singleton() {} // private constructor
public:
    static Singleton* getInstance() {
        if (!instance) {
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;

// Usage
Singleton* obj = Singleton::getInstance();
Factory Method Pattern:

2)Intent: Define an interface for creating an object, but let subclasses alter the type of objects that will be created.
Example:

class Product {
public:
    virtual void create() = 0;
};

class ConcreteProductA : public Product {
public:
    void create() override {
        // create Product A
    }
};

class ConcreteProductB : public Product {
public:
    void create() override {
        // create Product B
    }
};

class Creator {
public:
    virtual Product* factoryMethod() = 0;
};

class ConcreteCreatorA : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProductA();
    }
};

class ConcreteCreatorB : public Creator {
public:
    Product* factoryMethod() override {
        return new ConcreteProductB();
    }
};

// Usage
Creator* creator = new ConcreteCreatorA();
Product* product = creator->factoryMethod();
product->create();
Observer Pattern:




3)Intent: Define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.
Example:

#include <iostream>
#include <vector>

class Observer {
public:
    virtual void update() = 0;
};

class ConcreteObserver : public Observer {
public:
    void update() override {
        std::cout << "Observer is notified and updated.\n";
    }
};

class Subject {
private:
    std::vector<Observer*> observers;
public:
    void addObserver(Observer* obs) {
        observers.push_back(obs);
    }

    void notifyObservers() {
        for (Observer* obs : observers) {
            obs->update();
        }
    }
};

// Usage
ConcreteObserver observer1, observer2;
Subject subject;
subject.addObserver(&observer1);
subject.addObserver(&observer2);

// When the subject changes state
subject.notifyObservers();
These are just a few examples of design patterns in C++