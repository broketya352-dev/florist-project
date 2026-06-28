#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "data.h"

void addCustomer(Customer customers[], int *count);
void displayCustomers(Customer customers[], int count);
int searchCustomer(Customer customers[], int count, char *phone);
void findCustomer(Customer customers[], int count);
void deleteCustomer(Customer customers[], int *count, char *phone);


#endif
