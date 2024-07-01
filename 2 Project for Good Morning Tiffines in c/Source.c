#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 5

typedef struct {
    char name[30];
    float price;
}FoodItem;

void displayMenu(FoodItem menu[], int size) {
    printf("Welcome to Good Morning Tiffines , and todays menu is :\n");

    for (int i = 0; i < size; i++) {
        printf("%d.%s- $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

float takeOrder(FoodItem menu[], int size) {

    int choice;
    int quantity;
    float total = 0.0;

    printf("Enter the FoodItem number you want to oder (1-%d):", size);
    scanf_s("%d", &choice);

    while (1) {
        if (choice < 1 || choice >5) {
            printf("invalid choice, please try again \n");
            continue;
        }

        printf("Enter the quantity :");
        scanf_s("%d", &quantity);

        total += menu[choice - 1].price * quantity;

        printf("Do you want to order anything else ? (1 for yes, 0 for No) :");
        int more;
        scanf_s("%d", &more);
        if (more == 0) {
            break;
        }
    }

    return total;
}


int main() {

    FoodItem menu[MAX_ITEMS] =
    { {"Idly",25.0},
    {"Vada",30.0},
    {"Dosa",40.0},
    {"Bajji",50.0},
    {"Poori",60.0}

    };

    while (1) {
        displayMenu(menu, MAX_ITEMS);
        float total = takeOrder(menu, MAX_ITEMS);

        printf("your total is : $%.2f\n", total);

        printf("Do you want to oder any thing else?(1 for yes, 0 for no):");
        int more;
        scanf_s("%d", &more);

        if (more == 0) {
            printf("Thank you for your order. Goodbye!\n");
            break;
        }
    }

    return 0;
}