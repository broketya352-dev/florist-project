#include <stdio.h>
#include "report.h"
#include "seachFlower.h"

void salesReport(Order orders[], int orderCount,Flower flowers[], int flowerCount)
{
    int i;
    int j;

    if (orderCount == 0)
    {
        printf("\nNo orders available.\n");
        return;
    }

    for (i = 0; i < orderCount; i++)
    {
        printf("\n--- Receipt for Order #%d ---\n",
               orders[i].orderID);

        printf("Order Date : %02d/%02d/%04d\n",
               orders[i].date.day,
               orders[i].date.month,
               orders[i].date.year);

        printf("---------------------------------\n");

        for (j = 0; j < orders[i].itemCount; j++)
        {
            printf("Flower ID       : %d\n",
                   orders[i].item[j].flower.flowerID);

            printf("Flower Name     : %s\n",
                   orders[i].item[j].flower.name);

            printf("Unit Price      : %.2f\n",
                   orders[i].item[j].unitPrice);

            printf("Quantity Ordered: %d\n",
                   orders[i].item[j].quantity);

            printf("Subtotal        : %.2f\n",
                   orders[i].item[j].subtotal);

            printf("---------------------------------\n");
        }

        printf("Total Payment : %.2f\n",
               orders[i].totalPayment);

        printf("=================================\n");
    }
}
