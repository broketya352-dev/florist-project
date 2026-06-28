#ifndef FLOWER_H
#define FLOWER_H

#include "data.h"

void addFlower(Flower flowers[], int *count);
void displayFlowers(Flower flowers[], int count);
void updateFlowerStock(Flower flowers[], int count);
void deleteFlower(Flower flowers[], int *count);

#endif
