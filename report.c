#include <stdio.h>
#include "report.h"
#include "searchFlower.h"

void salesReport(Order orders[], int orderCount, Flower flowers[], int flowerCount) {
    for (int i = 0; i < orderCount; i++) {
        printf("\n--- Receipt for Order #%d ---\n", orders[i].orderID);
        
        for (int j = 0; j < orders[i].itemCount; j++) {
            int currentFlowerID = orders[i].item[j].flower.flowerID;
            
            printf("Quantity Ordered: %d\n", orders[i].item[j].quantity);
        }
    }
}
