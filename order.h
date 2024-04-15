#ifndef ORDER_H
#define ORDER_H


typedef struct {
    int orderCode;
    char productName[100];  // Name of the ordered product
    int quantity;
    double totalAmount;
    char userName[50];             // User's first name
    char userSurname[50];          // User's last name
} Order;
extern Order orders[100];
extern int numOrders;

void placeOrder(int code, const char *productName, int quantity, double paidAmount, const char *userName, const char *userSurname);
void viewOrders(const char *userName, const char *userSurname);

#endif
