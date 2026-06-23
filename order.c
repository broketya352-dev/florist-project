#include <stdio.h>
#include "order.h"
#include "data.h"
#include "time.h"

void createOrder(Order orders[], int *orderCount,
                 Flower flowers[], int flowerCount)
{
    int i;
    int j;
    int flowerID;
    int flag;

    if (flowerCount == 0)
    {
        printf("No flowers available.\n");
        return;
    }

    if (*orderCount == 0)
    {
        orders[*orderCount].orderID = 1001;
    }
    else
    {
        orders[*orderCount].orderID =
            orders[*orderCount - 1].orderID + 1;
    }
  
  t = time(NULL);
    currentTime = localtime(&t);

    orders[*orderCount].date.day =
        currentTime->tm_mday;

    orders[*orderCount].date.month =
        currentTime->tm_mon + 1;

    orders[*orderCount].date.year =
        currentTime->tm_year + 1900;

    orders[*orderCount].totalPayment = 0;

    printf("Order Date : %02d/%02d/%04d\n",
           orders[i].date.day,
           orders[i].date.month,
           orders[i].date.year);

    orders[*orderCount].totalPayment = 0;

    printf("How many flower types do you want? ");
    scanf("%d", &orders[*orderCount].itemCount);

    /* Validate item count */
    if (orders[*orderCount].itemCount < 1 ||
        orders[*orderCount].itemCount > 12)
    {
        printf("Invalid number of items.\n");
        return;
    }

    for (i = 0; i < orders[*orderCount].itemCount; i++)
    {
        flag = -1;

        printf("\n========== Item %d ==========\n", i + 1);

        displayFlowers(flowers, flowerCount);

        printf("Enter Flower ID: ");
        scanf("%d", &flowerID);

        for (j = 0; j < flowerCount; j++)
        {
            if (flowers[j].flowerID == flowerID)
            {
                flag = j;
                break;
            }
        }

        /* Flower not found */
        if (flag == -1)
        {
            printf("Flower ID not found!\n");
            i--;
            continue;
        }

        orders[*orderCount].item[i].flower = flowers[flag];

        orders[*orderCount].item[i].unitPrice =
            flowers[flag].price;

        printf("Enter Quantity: ");
        scanf("%d", &orders[*orderCount].item[i].quantity);

        if (orders[*orderCount].item[i].quantity >
            flowers[flag].stock)
        {
            printf("Not enough stock available!\n");
            i--;
            continue;
        }

        orders[*orderCount].item[i].subtotal =
            orders[*orderCount].item[i].unitPrice *
            orders[*orderCount].item[i].quantity;

        orders[*orderCount].totalPayment +=
            orders[*orderCount].item[i].subtotal;

        flowers[flag].stock -=
            orders[*orderCount].item[i].quantity;
    }
    (*orderCount)++;

    printf("\nOrder created successfully!\n");
}

void displayOrders(Order orders[], int orderCount)
{
    int i;
    int j;

    if (orderCount == 0)
    {
        printf("\nNo orders found.\n");
        return;
    }

    for (i = 0; i < orderCount; i++)
    {
        printf("\n------------------------------------------------\n");
        printf("Order ID : %d\n", orders[i].orderID);

        printf("Customer ID : %d\n",
               orders[i].customer.customerID);
        printf("Customer Name : %s\n",
               orders[i].customer.name);
        printf("Phone Number : %s\n",
               orders[i].customer.phone);

        printf("Order Date : %02d/%02d/%04d\n",
               orders[i].date.day,
               orders[i].date.month,
               orders[i].date.year);

        printf("---------------------------------------------------\n");
        printf("%-5s %-20s %-10s %-10s %-10s\n",
               "No", "Flower", "Price", "Qty", "Subtotal");
        printf("---------------------------------------------------\n");

        for (j = 0; j < orders[i].itemCount; j++)
        {
            printf("%-5d %-20s %-10.2f %-10d %-10.2f\n",
                   j + 1,
                   orders[i].item[j].flower.name,
                   orders[i].item[j].unitPrice,
                   orders[i].item[j].quantity,
                   orders[i].item[j].subtotal);
        }

        printf("-----------------------------------------\n");
        printf("Total Payment : %.2f\n",
               orders[i].totalPayment);
        printf("=========================================\n");
    }
}
