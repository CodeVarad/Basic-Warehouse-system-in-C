//Very Basic Warehouse System in C language
//Author: CodeVarad  
//link : https://github.com/CodeVarad

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void additem();
void removeitem();
void checkstock();

struct Warehouse {
    char itemname[50];
    int quantity;
    int price;
    int found=0;
} item;

int main() {
    int var;
     
        printf("Welcome to CodeVarad Warehouse Services\n");
        printf("Please select an option from below.\n");
        printf("1. Add an Item\n");
        printf("2. Remove a Quantity of an Item\n");
        printf("3. Check for an Item Quantity\n");
        printf("4. Exit\n");
        scanf("%d", &var);

        switch (var) {
            case 1:
                additem();
                break;

            case 2:
                removeitem();
                break;

            case 3:
                checkstock();
                break;

            case 4:
                printf("Thanks for using CodeVarad Warehouse Services!\n");
                return 0;

            default:
                printf("Invalid option.Try again.\n");
        }
    

    return 0;
}

void additem() {
    FILE *fileptr;
    fileptr = fopen("warehouse.txt", "a");
    if (!fileptr) {
        fprintf(stderr, "There was an error opening the file.\n");
        return;
    }

    printf("Enter the Item name: \n");
    getchar();  
    scanf(" %[^\n]", item.itemname);
    printf("Enter the quantity of the Item: \n");
    scanf("%d", &item.quantity);
    printf("Enter the price of the Item: \n");
    scanf("%d", &item.price);

    fprintf(fileptr, "%s|%d|%d\n", item.itemname, item.quantity, item.price);
    fclose(fileptr);

    printf("Item added successfully.\n");
}

void removeitem() {
    FILE *fileptr, *tempfile;
    char line[1000], temp[50];
    int removeqty;

    printf("Enter the name of the item to remove quantity from: \n");
    getchar();  
    scanf(" %[^\n]", temp);
    printf("Enter the quantity to remove: \n");
    scanf("%d", &removeqty);

    fileptr = fopen("warehouse.txt", "r");
    tempfile = fopen("temp_wardrobe.txt", "w");

    if (!fileptr || !tempfile) {
        fprintf(stderr, "There was an error opening the file.\n");
        return;
    }

    while (fgets(line, sizeof(line), fileptr)) {
        sscanf(line, "%[^|]|%d|%d", item.itemname, &item.quantity, &item.price);
        if (strcmp(item.itemname, temp) == 0) {
            item.found = 1;
            if (item.quantity > removeqty) {
                item.quantity -= removeqty;
                fprintf(tempfile, "%s|%d|%d\n", item.itemname, item.quantity, item.price);
            } else {
                printf("The stock of the item avaliable is smaller than your desired value, removed the entire stock.\n");
            }
        } else {
            fprintf(tempfile, "%s|%d|%d\n", item.itemname, item.quantity, item.price);
        }
    }

    fclose(fileptr);
    fclose(tempfile);

    remove("warehouse.txt");
    rename("temp_wardrobe.txt", "warehouse.txt");

    if (item.found) {
        printf("Quantity removed successfully.\n");
    } else {
        printf("Item not found.\n");
    }
}

void checkstock() {
    FILE *fileptr;
    char line[1000], temp[50];


    printf("Enter the name of item to check stock: \n");
    getchar();  
    scanf(" %[^\n]", temp);

    fileptr = fopen("warehouse.txt", "r");
    if (!fileptr) {
        fprintf(stderr, "There was an error opening the file.\n");
        return;
    }

    while (fgets(line, sizeof(line), fileptr)) {
        sscanf(line, "%[^|]|%d|%d", item.itemname, &item.quantity, &item.price);
        if (strcmp(item.itemname, temp) == 0) {
            printf("Item: %s \n", item.itemname);
            printf("quantity: %d \n", item.quantity);
            printf("price: %d $ \n", item.price);
            item.found = 1;
            break;
        }
    }

    fclose(fileptr);

    if (!item.found) {
        printf("Item not found.\n");
    }
}
