#include <stdio.h>
#include "data.h"

void loadMockData(Flower flowers[], int *flowerCount,
                  Order orders[], int *orderCount);

int main(void)
{
    Flower flowers[100];
    Order orders[100];

    int flowerCount = 0;
    int orderCount = 0;

    loadMockData(flowers, &flowerCount, orders, &orderCount);

    printf("Flowers loaded: %d\n", flowerCount);
    printf("Orders loaded : %d\n", orderCount);

    return 0;
}

void loadMockData(Flower flowers[], int *flowerCount,
                  Order orders[], int *orderCount)
{
    /* ---------- Flowers ---------- */
    *flowerCount = 6;

    flowers[0] = (Flower){101, "Red Rose", 2.50f, 100};
    flowers[1] = (Flower){102, "White Lily", 3.20f, 50};
    flowers[2] = (Flower){103, "Sunflower", 1.80f, 75};
    flowers[3] = (Flower){104, "Tulip", 2.80f, 60};
    flowers[4] = (Flower){105, "Orchid", 5.00f, 30};
    flowers[5] = (Flower){106, "Carnation", 1.50f, 120};

    /* ---------- Orders ---------- */
    *orderCount = 2;

    orders[0].orderID = 1001;
    orders[0].customer = (Customer){1, "Alice Johnson", "012345678"};
    orders[0].date = (Date){17, 6, 2026};
    orders[0].itemCount = 2;

    orders[0].item[0].flower = flowers[0];
    orders[0].item[0].quantity = 5;
    orders[0].item[0].subtotal = 12.50f;

    orders[0].item[1].flower = flowers[3];
    orders[0].item[1].quantity = 3;
    orders[0].item[1].subtotal = 8.40f;

    orders[0].totalPayment = 20.90f;

    orders[1].orderID = 1002;
    orders[1].customer = (Customer){2, "Bob Smith", "098765432"};
    orders[1].date = (Date){18, 6, 2026};
    orders[1].itemCount = 3;

    orders[1].item[0].flower = flowers[1];
    orders[1].item[0].quantity = 2;
    orders[1].item[0].subtotal = 6.40f;

    orders[1].item[1].flower = flowers[2];
    orders[1].item[1].quantity = 10;
    orders[1].item[1].subtotal = 18.00f;

    orders[1].item[2].flower = flowers[4];
    orders[1].item[2].quantity = 1;
    orders[1].item[2].subtotal = 5.00f;

    orders[1].totalPayment = 29.40f;
}