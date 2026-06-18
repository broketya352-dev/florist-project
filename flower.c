#include <stdio.h>
#include <string.h>
#include "flower.h"
#include "data.h"

void addFlower(Flower flowers[], int *count)
{
    /* Generate Flower ID */
    if (*count == 0)
    {
        flowers[*count].flowerID = 1001;
    }
    else
    {
        flowers[*count].flowerID = flowers[*count - 1].flowerID + 1;
    }

    /* Clear input buffer */
    getchar();

    /* Input flower name */
    printf("Enter Flower Name : ");
    fgets(flowers[*count].name, sizeof(flowers[*count].name), stdin);
    flowers[*count].name[strcspn(flowers[*count].name, "\n")] = '\0';

    /* Input price */
    do
    {
        printf("Enter Price : ");
        scanf("%f", &flowers[*count].price);

        if (flowers[*count].price < 0)
        {
            printf("Price cannot be negative.\n");
        }

    } while (flowers[*count].price < 0);

    /* Input stock */
    do
    {
        printf("Enter Stock : ");
        scanf("%d", &flowers[*count].stock);

        if (flowers[*count].stock < 0)
        {
            printf("Stock cannot be negative.\n");
        }

    } while (flowers[*count].stock < 0);

    (*count)++;

    printf("\nFlower added successfully!\n");
}

void displayFlowers(Flower flowers[], int count)
{
    if (count == 0)
    {
        printf("\nNo flowers available.\n");
        return;
    }

    printf("\n=====================================================\n");
    printf("%-8s %-20s %-10s %-10s\n",
           "ID", "Name", "Price", "Stock");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-8d %-20s %-10.2f %-10d\n",
               flowers[i].flowerID,
               flowers[i].name,
               flowers[i].price,
               flowers[i].stock);
    }

    printf("=====================================================\n");
}

void updateFlowerStock(Flower flowers[], int count)
{
    int id;
    int index = -1;

    if (count == 0)
    {
        printf("\nNo flowers available.\n");
        return;
    }

    displayFlowers(flowers, count);

    printf("\nEnter Flower ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (flowers[i].flowerID == id)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Flower not found.\n");
        return;
    }

    printf("\nUpdating Flower: %s\n", flowers[index].name);

    do
    {
        printf("Enter New Price : ");
        scanf("%f", &flowers[index].price);

        if (flowers[index].price < 0)
        {
            printf("Price cannot be negative.\n");
        }

    } while (flowers[index].price < 0);

    do
    {
        printf("Enter New Stock : ");
        scanf("%d", &flowers[index].stock);

        if (flowers[index].stock < 0)
        {
            printf("Stock cannot be negative.\n");
        }

    } while (flowers[index].stock < 0);

    printf("\nFlower updated successfully!\n");
}