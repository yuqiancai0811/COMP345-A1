//
// Created by Crimson on 2024-09-29.
//

#include "OrderDriver.h"
#include "Orders.cpp"


void test() {

        orderList ordersList;

        // Creating orders
        ordersList.addOrder(new deployOrder());
        ordersList.addOrder(new advanceOrder());
        ordersList.addOrder(new bombOrder());
        ordersList.addOrder(new blockadeOrder());
        ordersList.addOrder(new airliftOrder());
        ordersList.addOrder(new negotiateOrder());

        std::cout << "Orders before execution:\n";
        ordersList.showAllOrders();

        // Execute some orders
        ordersList.removeOrder(0); // Remove first order (DeployOrder)
        ordersList.moveOrder(2, 0); // Move BombOrder to the first position

        std::cout << "\n\nOrders after modifications (move and remove):\n";
        ordersList.showAllOrders();

    }

int main() {
    test();
    return 0;
}


