#ifndef ORDER_H
#define ORDER_H

#include "data.h"

void makeOrder(Order orders[], int *orderCount,
                 Flower flowers[], int flowerCount);

void displayOrders(Order orders[], int orderCount);

#endif
