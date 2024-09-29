//
// Created by Crimson on 2024-09-29.
//

#include "Orders.h"
#include <iostream>
#include <string>
#include <vector>
class Order {
    protected:
        std::string effect;
        bool executed;
    public:
        Order() : executed(false) {}
        virtual ~Order() {}

    // Validate and execute methods are virtual and overridden by subclasses
        virtual bool validate() const = 0;
        virtual void execute() = 0;

    // Stream insertion operator
        friend std::ostream& operator<<(std::ostream& os, const Order& order) {
            os << "Order: " << typeid(order).name() << (order.executed ? " (Executed)" : " (Not executed)") << "\n";
            os << "Effect: " << order.effect << "\n";
            return os;
    }
};

class deployOrder : public Order {
  public:
    bool validate() const override {
        // For now, let's assume this order is always valid
        return true;
    }

    void execute() override {
        if (validate()) {
            effect = "Deploy troops";
            executed = true;
        }
    }
};

class advanceOrder : public Order {
  public:
    bool validate() const override {
        // For now, let's assume this order is always valid
        return true;
    }

    void execute() override {
        if (validate()) {
            effect = "Advance troops";
            executed = true;
        }
    }
};

class bombOrder : public Order {
  public:
    bool validate() const override {
        return true;
    }

    void execute() override {
        if (validate()) {
            effect = "Bomb troops";
            executed = true;
        }
    }
};

class blockadeOrder : public Order {
  public:
    bool validate() const override {
        // For now, let's assume this order is always valid
        return true;
    }

    void execute() override {
        if (validate()) {
            effect = "Blockade troops";
            executed = true;
        }
    }
};

class airliftOrder : public Order {
    public:
    bool validate() const override {
        return true;
    }

    void execute() override {
        if (validate()) {
            effect = "Airlift troops";
            executed = true;
        }
    }
};

class negotiateOrder : public Order {
    public:
    bool validate() const override {
        return true;
    }

    void execute() override {
        if (validate()) {
            effect = "Negotiate troops";
            executed = true;
        }
    }
};

class orderList {
    private:
        std::vector<Order *> orders;

    public:

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

    friend std::ostream& operator<<(std::ostream& os, const orderList& ordersList) {
        for (const auto& order : ordersList.orders) {
            os << *order;
        }
        return os;
    }
};