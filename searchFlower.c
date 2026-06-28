#include <stdio.h>
#include "searchFlower.h"

int searchFlowerByID(Flower flowers[], int count)
{
    int i;
    int flowerID;
    int c;

    if (count == 0)
    {
        printf("\nNo flowers available.\n");
        return -1; 
    }

    printf("Enter Flower ID: ");
    scanf("%d", &flowerID);

    for (i = 0; i < count; i++)
    {
        if (flowers[i].flowerID == flowerID)
        {
            // 
            printf("\n========== Flower Information ==========\n");
            printf("Flower ID : %d\n", flowers[i].flowerID);
            printf("Name      : %s\n", flowers[i].name);
            printf("Price     : %.2f\n", flowers[i].price);
            printf("Stock     : %d\n", flowers[i].stock);
            printf("========================================\n");
            
            while ((c = getchar()) != '\n' && c != -1); 
            
            return i; 
    }
}

    printf("\nFlower ID not found.\n");
    while ((c = getchar()) != '\n' && c != -1); // Clean up buffer safely
    return -1; // Return -1 indicating not found
}
