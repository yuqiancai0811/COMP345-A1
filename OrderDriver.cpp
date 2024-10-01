
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
    ordersList.moveOrder(2, 0); // Move Blockade order  to the first position

    std::cout << "\n\nOrders after modifications (move and remove):\n";
    ordersList.showAllOrders();

    // Clean up the orders list to avoid memory leaks
    // Since orderList destructor now handles deletion, no need for manual cleanup
}

int main() {
    test();
    return 0;
}
