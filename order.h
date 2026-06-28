#ifndef ORDER_H
#define ORDER_H

#include "data.h"

void createOrder(Order orders[], int *orderCount,
                 Flower flowers[], int flowerCount);

void displayOrders(Order orders[], int orderCount);
void lowStockReport(Flower flowers[], int flowerCount);

#endif
