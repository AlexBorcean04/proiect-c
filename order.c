#include "order.h"
#include <stdio.h>
#include<string.h>
#include "product.h"

Order orders[100];
int numOrders = 0;
void placeOrder(int code, const char *productName, int quantity, double paidAmount, const char *userName, const char *userSurname) {
    int productIndex = -1;
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, productName) == 0 && products[i].quantity >= quantity) {
            productIndex = i;
            break;
        }
    }

    if (productIndex != -1) {
        orders[numOrders].orderCode = code;
        strcpy(orders[numOrders].productName, productName);  // Copy product name
        orders[numOrders].quantity = quantity;
        orders[numOrders].totalAmount = paidAmount;
        strcpy(orders[numOrders].userName, userName);
        strcpy(orders[numOrders].userSurname, userSurname);
        numOrders++;

        products[productIndex].quantity -= quantity; // Update inventory

        printf("Order placed: Code %d, Product %s, Quantity %d, Paid %.2f, User: %s %s\n",
               code, productName, quantity, paidAmount, userName, userSurname);
    } else {
        printf("Order failed: Product not available or insufficient quantity.\n");
    }
}
void viewOrders(const char *userName, const char *userSurname) {
    extern Order orders[100]; // Assuming an order array is global
    extern int numOrders;
    int found = 0;

    printf("Viewing orders for %s %s:\n", userName, userSurname);
    for (int i = 0; i < numOrders; i++) {
        if (strcmp(orders[i].userName, userName) == 0 && strcmp(orders[i].userSurname, userSurname) == 0) {
            printf("Order Code %d: Product %s, Quantity %d, Total Paid %.2f\n",
                   orders[i].orderCode, orders[i].productName, orders[i].quantity, orders[i].totalAmount);
            found = 1;
        }
    }

    if (!found) {
        printf("No orders found for %s %s.\n", userName, userSurname);
    }
}

