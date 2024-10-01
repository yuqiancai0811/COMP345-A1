

//
// Created by Crimson on 2024-09-29.
//

#include "Orders.h"
#include <iostream>
#include <string>
#include <vector>

class Order {
protected:
    std::string* effect;  // Changed to pointer
    bool* executed;       // Changed to pointer
public:
    std::string* name;    // Changed to pointer

    // Constructor
    Order() : effect(new std::string), executed(new bool(false)), name(new std::string) {}

    // Destructor
    virtual ~Order() {
        delete effect;
        delete executed;
        delete name;
    }

    // Copy constructor
    Order(const Order& other) {
        effect = new std::string(*other.effect);
        executed = new bool(*other.executed);
        name = new std::string(*other.name);
    }

    // Assignment operator
    Order& operator=(const Order& other) {
        if (this == &other) return *this;

        delete effect;
        delete executed;
        delete name;

        effect = new std::string(*other.effect);
        executed = new bool(*other.executed);
        name = new std::string(*other.name);

        return *this;
    }

    // Validate and execute methods are virtual and overridden by subclasses
    virtual bool validate() const = 0;
    virtual void execute() = 0;

    virtual std::string toString() const {
        if (*executed && !name->empty()) {
            return "Order: " + *name + " is executed\n";
        } else if (!*executed && !name->empty()) {
            return "Order: " + *name + " is not executed\n";
        } else {
            return "Order: Null\n";
        }
    }

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Order& order) {
        os << "Order: " << *order.name << (*order.executed ? " (Executed)" : " (Not executed)") << "\n";
        os << "Effect: " << *order.effect << "\n";
        return os;
    }
};

// Subclasses now inherit the changes made to the base class

class deployOrder : public Order {
public:
    deployOrder() {
        *name = "deployOrder";
    }

    bool validate() const override {
        return true;
    }

    void execute() override {
        if (validate()) {
            *effect = "Deploy troops";
            *executed = true;
        }
    }
};

class advanceOrder : public Order {
public:
    advanceOrder() {
        *name = "Advance Order";
    }

    bool validate() const override {
        return true;
    }

    void execute() override {
        if (validate()) {
            *effect = "Advance troops";
            *executed = true;
        }
    }
};

class bombOrder : public Order {
public:
    bombOrder() {
        *name = "Bomb Order";
    }

    bool validate() const override {
        return true;
    }

    void execute() override {
        if (validate()) {
            *effect = "Bomb troops";
            *executed = true;
        }
    }
};

class blockadeOrder : public Order {
public:
    blockadeOrder() {
        *name = "Blockade Order";
    }

    bool validate() const override {
        return true;
    }

    void execute() override {
        if (validate()) {
            *effect = "Blockade troops";
            *executed = true;
        }
    }
};

class airliftOrder : public Order {
public:
    airliftOrder() {
        *name = "Airlift Order";
    }

    bool validate() const override {
        return true;
    }

    void execute() override {
        if (validate()) {
            *effect = "Airlift troops";
            *executed = true;
        }
    }
};

class negotiateOrder : public Order {
public:
    negotiateOrder() {
        *name = "Negotiate Order";
    }

    bool validate() const override {
        return true;
    }

    void execute() override {
        if (validate()) {
            *effect = "Negotiate troops";
            *executed = true;
        }
    }
};

class orderList {
private:
    std::vector<Order*> orders;

public:
    ~orderList() {
        for (Order* order : orders) {
            delete order;
        }
    }

    void addOrder(Order* order) {
        orders.push_back(order);
    }

    void removeOrder(int index) {
        if (index >= 0 && index < orders.size()) {
            delete orders[index];
            orders.erase(orders.begin() + index);
        }
    }

    void moveOrder(int oldIndex, int newIndex) {
        if (oldIndex >= 0 && oldIndex < orders.size() &&
            newIndex >= 0 && newIndex < orders.size()) {
            std::swap(orders[oldIndex], orders[newIndex]);
        }
    }

    void showAllOrders() const {
        for (const auto& order : orders) {
            std::cout << order->toString();
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const orderList& ordersList) {
        for (const auto& order : ordersList.orders) {
            os << *order;
        }
        return os;
    }
};
