#include "product.h"
#include<string.h>
#include <stdio.h>
Product products[100];
int numProducts = 0;
void addProduct(const char *name, int quantity, double price) {


    if (numProducts < 100) { // Check array bounds
        strcpy(products[numProducts].name, name);
        products[numProducts].quantity = quantity;
        products[numProducts].price = price;
        numProducts++;
        printf("Product added: %s, Quantity: %d, Price: %.2f\n", name, quantity, price);
    } else {
        printf("No space to add new products.\n");
    }
    // Ideally, you'd also check for duplicates before adding
}


void searchProductByName(const char *name) {
    int found = 0;

    for (int i = 0; i < numProducts; i++) {
        if (strstr(products[i].name, name) != NULL) {
            printf("Product: %s, Quantity: %d, Price: %.2f\n", products[i].name, products[i].quantity, products[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("No products found containing: %s\n", name);
    }
}


void searchProductByPrice(double min_price, double max_price) {
    extern Product products[100];
    extern int numProducts;
    int found = 0;

    for (int i = 0; i < numProducts; i++) {
        if (products[i].price >= min_price && products[i].price <= max_price) {
            printf("Product: %s, Quantity: %d, Price: %.2f\n", products[i].name, products[i].quantity, products[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("No products found in price range $%.2f to $%.2f\n", min_price, max_price);
    }
}
