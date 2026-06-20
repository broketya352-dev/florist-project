#ifndef DATA_H
#define DATA_H

#define MAX_NAME 50
#define MAX_PHONE 20
#define MAX_ITEM 20
#define MAX_CUSTOMERS 100

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    int customerID;
    char name[MAX_NAME];
    char phone[MAX_PHONE];
} Customer;

typedef struct
{
    int flowerID;
    char name[MAX_NAME];
    float price;
    int stock;
} Flower;

typedef struct
{
    Flower flower;      // nested struct
    int quantity;
    float subtotal;
   float unitPrice;
} OrderItem;

typedef struct
{
    int orderID;
    Customer customer;  // nested struct
    Date date;          // nested struct
    OrderItem item[MAX_ITEM];     // nested struct
    int itemCount;
    float totalPayment;
} Order;

#endif
