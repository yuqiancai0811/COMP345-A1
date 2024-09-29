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
        bool executed=false;
    public:
        std::string name;

        Order() : executed(false) {}
        virtual ~Order() {}

    // Validate and execute methods are virtual and overridden by subclasses
        virtual bool validate() const = 0;
        virtual void execute() = 0;

        virtual std::string toString() const {
           // return "Order: " + name + (executed ? " (Executed)" : " (Not executed)") + "\nEffect: " + effect + "\n";
            if (executed&&!name.empty()) {
                return "Order:"+ name + " is executed\n";
            }
            else if(!executed&&!name.empty()) {
                return "Order:" + name + " is not executed\n";
            }
            else {
                return"Order:Null\n";
            }
        }
    // Stream insertion operator
        friend std::ostream& operator<<(std::ostream& os, const Order& order) {
            os << "Order: " << order.name << (order.executed ? " (Executed)" : " (Not executed)") << "\n";
            os << "Effect: " << order.effect << "\n";
            return os;


    }
};

class deployOrder : public Order {
  public:
    deployOrder() {
        name = "deployOrder";
    }
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
    std::string toString() const override {
        return Order::toString(); // Use the base class implementation
    }
};

class advanceOrder : public Order {
  public:

    advanceOrder() {
        name = "Advance Order";
    }
    std::string name="advanceOreder";
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
    std::string toString() const override {
        return Order::toString(); // Use the base class implementation
    }
};

class bombOrder : public Order {
  public:
    bombOrder() {
        name="Bomb Order";
    }
    bool validate() const override {
        return true;
    }

    void execute() override {
        if (validate()) {
            effect = "Bomb troops";
            executed = true;
        }
    }

    std::string toString() const override {
        return Order::toString(); // Use the base class implementation
    }
};

class blockadeOrder : public Order {
  public:

    blockadeOrder() {
        name = "Blockade Order";
    }
    bool validate() const override {
        return true;
    }

    void execute() override {
        if (validate()) {
            effect = "Blockade troops";
            executed = true;
        }
    }

    std::string toString() const override {
        return Order::toString(); // Use the base class implementation
    }
};

class airliftOrder : public Order {
    public:

    airliftOrder() {
        name="Airlift Order";
    }

    bool validate() const override {
        return true;
    }

    void execute() override {
        if (validate()) {
            effect = "Airlift troops";
            executed = true;
        }
    }

    std::string toString() const override {
        return Order::toString(); // Use the base class implementation
    }
};

class negotiateOrder : public Order {
    public:

    negotiateOrder() {
        name = "Negotiate Order";
    }

    bool validate() const override {
        return true;
    }

    void execute() override {
        if (validate()) {
            effect = "Negotiate troops";
            executed = true;
        }
    }

    std::string toString() const override {
        return Order::toString(); // Use the base class implementation
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

    void showAllOrders() const {
        for (const auto& order : orders) {
            std::cout << order->toString(); // or you can just do std::cout << *order;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const orderList& ordersList) {
        for (const auto& order : ordersList.orders) {
            os << *order;
        }
        return os;
    }
};
