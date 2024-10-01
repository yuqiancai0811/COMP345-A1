//
// Created by Crimson on 2024-09-29.
//

#ifndef ORDERS_H
#define ORDERS_H
#include <iostream>
#include <string>
#include <vector>

class Orders {
protected:
    std::string* effect;
    bool* executed;

public:
    std::string* name;

    // Constructor
    Orders();

    // Destructor
    virtual ~Orders();

    // Copy constructor
    Orders(const Orders& other);

    // Assignment operator
    Orders& operator=(const Orders& other);

    // Virtual methods for validation and execution
    virtual bool validate() const = 0;
    virtual void execute() = 0;

    // ToString method
    virtual std::string toString() const;

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Orders& order);
};



#endif //ORDERS_H
