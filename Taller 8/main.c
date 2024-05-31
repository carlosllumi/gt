#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventario lleno, no se pueden agregar más productos.\n");
        return;
    }
    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", inventory[productCount].name);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &inventory[productCount].quantity);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &inventory[productCount].price);
    productCount++;
    printf("Producto agregado con éxito.\n");
}

void editProduct() {
    char name[50];
    printf("Ingrese el nombre del producto a editar: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < productCount; ++i) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Producto encontrado. Ingrese los nuevos datos.\n");
            printf("Ingrese el nuevo nombre del producto: ");
            scanf(" %[^\n]", inventory[i].name);
            printf("Ingrese la nueva cantidad del producto: ");
            scanf("%d", &inventory[i].quantity);
            printf("Ingrese el nuevo precio del producto: ");
            scanf("%f", &inventory[i].price);
            printf("Producto editado con éxito.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void deleteProduct() {
    char name[50];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < productCount; ++i) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < productCount - 1; ++j) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Producto eliminado con éxito.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void listProducts() {
    if (productCount == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }
    printf("Listado de productos:\n");
    for (int i = 0; i < productCount; ++i) {
        printf("Producto %d:\n", i + 1);
        printf("Nombre: %s\n", inventory[i].name);
        printf("Cantidad: %d\n", inventory[i].quantity);
        printf("Precio: %.2f\n", inventory[i].price);
    }
}

void searchProduct() {
    char name[50];
    printf("Ingrese el nombre del producto a buscar: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < productCount; ++i) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Producto encontrado:\n");
            printf("Nombre: %s\n", inventory[i].name);
            printf("Cantidad: %d\n", inventory[i].quantity);
            printf("Precio: %.2f\n", inventory[i].price);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

int main() {
    int option;
    do {
        printf("\nSistema de Inventarios\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Listar productos\n");
        printf("5. Buscar producto\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addProduct();
                break;
            case 2:
                editProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                listProducts();
                break;
            case 5:
                searchProduct();
                break;
            case 6:
                printf("Saliendo del sistema de inventarios.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (option != 6);

    return 0;
}
