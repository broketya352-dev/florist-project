#include <stdio.h>
#include <string.h>
#include "customer.h"

void addCustomer(Customer customers[], int *count) {
    printf("\n=== Add New Customer ===\n");
    
    if (*count >= MAX_CUSTOMERS) {
        printf("Error: Customer database is full (%d/%d).\n", *count, MAX_CUSTOMERS);
        return;
    }

    customers[*count].customerID =  *count + 1;
    int newID = customers[*count].customerID;
    printf("Assigned Customer ID: %d\n", newID);

    printf("Enter Customer Name: ");

    int ch;
    while ((ch = getchar()) != '\n' && (ch != EOF)); 

    fgets(customers[*count].name, MAX_NAME, stdin);
    customers[*count].name[strcspn(customers[*count].name, "\n")] = '\0';

    printf("Enter Phone Number: ");
    fgets(customers[*count].phone, MAX_PHONE, stdin);
    customers[*count].phone[strcspn(customers[*count].phone, "\n")] = '\0';

    (*count)++;
    
    printf("\nCustomer '%s' added successfully!\n", customers[*count - 1].name);
}

void displayCustomers(Customer customers[], int count) {
    printf("\n=== Customer List ===\n");
    
    if (count == 0) {
        printf("No customers registered yet.\n");
        return;
    }
    
    printf("============================================================\n");
    printf("%-12s | %-25s | %-15s\n", "Customer ID", "Name", "Phone Number");
    printf("============================================================\n");

    for (int i = 0; i < count; i++) {
        printf("%-12d | %-25s | %-15s\n", 
               customers[i].customerID, 
               customers[i].name, 
               customers[i].phone);
    }
    printf("============================================================\n");
}

int searchCustomer(Customer customers[], int count, char *phone) {
    for (int i = 0; i < count; i++) {
        if (strcmp(customers[i].phone, phone) == 0) {
            return i;  // return i if customer happen to be found.
        }
    }
    return -1;  // return -1 if customer is not found.
}

void findCustomer(Customer customers[], int count) {
    char phone[MAX_PHONE];
    
    printf("Enter phone number to search: ");
    int ch; while ((ch = getchar()) != '\n' && ch != EOF);
    fgets(phone, MAX_PHONE, stdin);
    phone[strcspn(phone, "\n")] = '\0';
    
    int index = searchCustomer(customers, count, phone);
    
    if (index == -1) {
        printf("No customer found with phone: %s\n", phone);
    } else {
        printf("\nCustomer Found:\n");
        printf("ID: %d | Name: %s | Phone: %s\n",
               customers[index].customerID,
               customers[index].name,
               customers[index].phone);
    }
}

 void deleteCustomer(Customer customers[], int *count, char *phone){
    int index = searchCustomer(customers, *count, phone);
    
    if (index == -1) {
        printf("Customer not found.\n");
        return;
    }
    
    // shift stored array to the left to fill up the gap that is empty after deleting the customer.
    for (int i = index; i < *count - 1; i++) {
        customers[i] = customers[i + 1];
    }
    
    (*count)--;
    printf("Customer deleted successfully!\n");
}
