#include <stdio.h>
#include "report.h"
#include "searchFlower.h"

void salesReport(Order orders[], int orderCount)
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

void customerPurchaseHistory(Order orders[], int orderCount)
{
    int customerID;
    int i;
    int j;
    int flag = 0;

    if (orderCount == 0)
    {
        printf("\nNo available for order.\n");
        return;
    }

    printf("\nEnter Customer ID: ");
    scanf("%d", &customerID);

    printf("\n=====================================================\n");
    printf("          CUSTOMER PURCHASE HISTORY\n");
    printf("=====================================================\n");

    for (i = 0; i < orderCount; i++)
    {
        if (orders[i].customer.customerID == customerID)
        {
            flag = 1;

            printf("\nOrder ID : %d\n",
                   orders[i].orderID);

            printf("Customer : %s\n",
                   orders[i].customer.name);

            printf("Phone    : %s\n",
                   orders[i].customer.phone);

            printf("Date     : %02d/%02d/%04d\n",
                   orders[i].date.day,
                   orders[i].date.month,
                   orders[i].date.year);

            printf("-----------------------------------------------------\n");
            printf("%-5s %-20s %-8s %-8s %-10s\n",
                   "No", "Flower", "Price", "Qty", "Subtotal");
            printf("-----------------------------------------------------\n");

            for (j = 0; j < orders[i].itemCount; j++)
            {
                printf("%-5d %-20s %-8.2f %-8d %-10.2f\n",
                       j + 1,
                       orders[i].item[j].flower.name,
                       orders[i].item[j].unitPrice,
                       orders[i].item[j].quantity,
                       orders[i].item[j].subtotal);
            }

            printf("-----------------------------------------------------\n");
            printf("Total Payment : %.2f\n", orders[i].totalPayment);

            printf("=====================================================\n");
        }
    }

    if (flag == 0)
    {
        printf("\nCustomer has not made any orders.\n");
    }
}
