[6/30/2026 4:36 PM] ⚡ Pann Ketya ( ប៉ាន់​ កិត្យា ): #include <stdio.h>
#include <string.h>
#include "data.h"
#include "flower.h"
#include "customer.h"
#include "order.h"
#include "report.h"
#include "seachFlower.h"

void loadMockData(Flower flowers[], int *flowerCount,
                  Customer customers[], int *customerCount)
{

    strcpy(flowers[0].name, "Rose");
    flowers[0].flowerID = 1001;
    flowers[0].price = 50.0;
    flowers[0].stock = 25;

    strcpy(flowers[1].name, "Tulip");
    flowers[1].flowerID = 1002;
    flowers[1].price = 35.0;
    flowers[1].stock = 30;

    strcpy(flowers[2].name, "Sunflower");
    flowers[2].flowerID = 1003;
    flowers[2].price = 45.0;
    flowers[2].stock = 20;

    strcpy(flowers[3].name, "Lily");
    flowers[3].flowerID = 1004;
    flowers[3].price = 60.0;
    flowers[3].stock = 15;

    strcpy(flowers[4].name, "Daisy");
    flowers[4].flowerID = 1005;
    flowers[4].price = 25.0;
    flowers[4].stock = 40;

    strcpy(flowers[5].name, "Orchid");
    flowers[5].flowerID = 1006;
    flowers[5].price = 80.0;
    flowers[5].stock = 12;

    strcpy(flowers[6].name, "Carnation");
    flowers[6].flowerID = 1007;
    flowers[6].price = 30.0;
    flowers[6].stock = 35;

    strcpy(flowers[7].name, "Jasmine");
    flowers[7].flowerID = 1008;
    flowers[7].price = 40.0;
    flowers[7].stock = 22;

    strcpy(flowers[8].name, "Lavender");
    flowers[8].flowerID = 1009;
    flowers[8].price = 55.0;
    flowers[8].stock = 18;

    strcpy(flowers[9].name, "Peony");
    flowers[9].flowerID = 1010;
    flowers[9].price = 75.0;
    flowers[9].stock = 14;

    strcpy(flowers[10].name, "Marigold");
    flowers[10].flowerID = 1011;
    flowers[10].price = 20.0;
    flowers[10].stock = 50;

    strcpy(flowers[11].name, "Hibiscus");
    flowers[11].flowerID = 1012;
    flowers[11].price = 45.0;
    flowers[11].stock = 28;

    strcpy(flowers[12].name, "Lotus");
    flowers[12].flowerID = 1013;
    flowers[12].price = 90.0;
    flowers[12].stock = 10;

    strcpy(flowers[13].name, "Cherry Blossom");
    flowers[13].flowerID = 1014;
    flowers[13].price = 100.0;
    flowers[13].stock = 8;

    strcpy(flowers[14].name, "Daffodil");
    flowers[14].flowerID = 1015;
    flowers[14].price = 35.0;
    flowers[14].stock = 25;

    strcpy(flowers[15].name, "Iris");
    flowers[15].flowerID = 1016;
    flowers[15].price = 65.0;
    flowers[15].stock = 16;

    strcpy(flowers[16].name, "Magnolia");
    flowers[16].flowerID = 1017;
    flowers[16].price = 85.0;
    flowers[16].stock = 11;

    strcpy(flowers[17].name, "Gardenia");
    flowers[17].flowerID = 1018;
    flowers[17].price = 70.0;
    flowers[17].stock = 19;

    strcpy(flowers[18].name, "Camellia");
    flowers[18].flowerID = 1019;
    flowers[18].price = 55.0;
    flowers[18].stock = 24;

    strcpy(flowers[19].name, "Hydrangea");
    flowers[19].flowerID = 1020;
    flowers[19].price = 95.0;
    flowers[19].stock = 13;

    *flowerCount = 20;

    strcpy(customers[0].name, "Ahmed Hassan");
    customers[0].customerID = 1;
    strcpy(customers[0].phone, "01012345678");

    strcpy(customers[1].name, "Fatima Ali");
    customers[1].customerID = 2;
    strcpy(customers[1].phone, "01098765432");

    strcpy(customers[2].name, "Mohamed Ibrahim");
    customers[2].customerID = 3;
    strcpy(customers[2].phone, "01156789012");

    *customerCount = 3;
}
void customerMenu(Flower flowers[], int flowerCount,
                  Customer customers[], int *customerCount,
                  Order orders[], int *orderCount)
{
    int choice;
    int registered = 0;

    do
    {
        printf("\n=====================================================\n");
        printf("                 CUSTOMER MENU\n");
        printf("=====================================================\n");

        printf("1. Register\n");
        printf("2. View Available Flowers\n");
        printf("3. Create Order\n");
        printf("4. View Purchase History\n");
        printf("0. Back\n");

        printf("=====================================================\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            addCustomer(customers, customerCount);
            registered = 1;
            printf("\nRegistration Successful!\n");
            break;

        case 2:

            if (registered == 0)
            {
                printf("\nPlease register first!\n");
                break;
            }

            displayFlowers(flowers, flowerCount);
            break;

        case 3:
            if (registered == 0)
            {
                printf("\nPlease register first!\n");
                break;
            }

            createOrder(orders,
                        orderCount,
                        flowers,
                        flowerCount);

            break;
        case 4:
            if (registered == 0)
            {
                printf("\nPlease register first!\n");
                break;
            }

            customerPurchaseHistory(orders,
                                    *orderCount);

            break;

        case 0:
            printf("\nReturning to Main Menu...\n");
            break;

        default:
            printf("\nInvalid Choice!\n");
        }
    } while (choice != 0);
}

void managerMenu(Flower flowers[], int *flowerCount,
                 Customer customers[], int *customerCount,
                 Order orders[], int *orderCount)
{
    int choice;

    do
    {
        printf("\n");
        printf("=====================================================\n");
        printf("                 MANAGER MENU\n");
        printf("=====================================================\n");

        printf("\nFLOWER MANAGEMENT\n");
        printf("-----------------------------------------------------\n");
        printf("1. Add Flower\n");
        printf("2. Display Flowers\n");
        printf("3. Update Flower Stock\n");
        printf("4. Search Flower By ID\n");
        printf("5. Delete Flower\n");

        printf("\nCUSTOMER MANAGEMENT\n");
        printf("-----------------------------------------------------\n");
        printf("6. Add Customer\n");
        printf("7. Display Customers\n");

        printf("\nORDER MANAGEMENT\n");
        printf("-----------------------------------------------------\n");
        printf("8. Display Orders\n");

        printf("\nREPORTS\n");
        printf("-----------------------------------------------------\n");
        printf("9. Sales Report\n");
        printf("10. Low Stock Report\n");
        printf("11. Customer Purchase History\n");

        printf("\n0. Back\n");
        printf("=====================================================\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addFlower(flowers, flowerCount);
            break;

        case 2:
            displayFlowers(flowers, *flowerCount);
            break;

        case 3:
            updateFlowerStock(flowers, *flowerCount);
            break;

        case 4:
            searchFlowerByID(flowers, *flowerCount);
            break;

        case 5:
            deleteFlower(flowers, flowerCount);
            break;

        case 6:
            addCustomer(customers, customerCount);
            break;

        case 7:
            displayCustomers(customers, *customerCount);
            break;

        case 8:
            displayOrders(orders, *orderCount);
            break;

        case 9:
            salesReport(orders,
                        *orderCount,
                        flowers,
                        *flowerCount);
            break;

        case 10:
            lowStockReport(flowers, *flowerCount);
            break;

        case 11:
            customerPurchaseHistory(orders, *orderCount);
            break;

        case 0:
            printf("\nReturning to Main Menu...\n");
            break;

        default:
            printf("\nInvalid Choice!\n");
        }

    } while (choice != 0);
}

int main(void)
{
    Flower flowers[100];
    Customer customers[MAX_CUSTOMERS];
    Order orders[100];
[6/30/2026 4:36 PM] ⚡ Pann Ketya ( ប៉ាន់​ កិត្យា ): int flowerCount = 0;
    int customerCount = 0;
    int orderCount = 0;

    int choice;

    loadMockData(flowers, &flowerCount,
                 customers, &customerCount);

   

  do
    {
        printf("\n");
        printf("=====================================================\n");
        printf("           FLORIST MANAGEMENT SYSTEM\n");
        printf("=====================================================\n");
        printf("|                                                   |\n");
        printf("|  1. Manager                                       |\n");
        printf("|  2. Customer                                      |\n");
        printf("|                                                   |\n");
        printf("|  0. Exit                                          |\n");
        printf("|                                                   |\n");
        printf("=====================================================\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            managerMenu(flowers,
                        &flowerCount,
                        customers,
                        &customerCount,
                        orders,
                        &orderCount);
            break;

        case 2:
            customerMenu(flowers,
                         flowerCount,
                         customers,
                         &customerCount,
                         orders,
                         &orderCount);
            break;

        case 0:
            printf("\nThank You!\n");
            break;

        default:
            printf("\nInvalid Choice!\n");
        }

    } while (choice != 0);

    return 0;

  
}
