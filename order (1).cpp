#include <stdio.h>   // Для работы с функциями ввода-вывода
#include <stdlib.h>  // Для функций преобразования
#include <string.h>  // Для работы со строками

typedef struct {
    int order_id;
    int manager_id;
    int client_id;
    char order_date[11]; // Дата формата "YYYY-MM-DD"
    float amount;
} Order;

int compareOrders(const void *a, const void *b) {
    Order *orderA = (Order *)a;
    Order *orderB = (Order *)b;
    if (orderA->amount < orderB->amount) return 1;
    if (orderA->amount > orderB->amount) return -1;
    return 0;
}

int maain() {
    Order orders[100];  // Предполагая, что максимум 100 заказов
    int order_count = 0;

    FILE *orders_f = fopen("order.txt", "r");
    if (orders_f == NULL) {
        perror("Failed to open order.txt");
        return EXIT_FAILURE;
    }

    // Считываем данные из файла
    while (fscanf(orders_f, "%d;%d;%d;%10[^;];%f",
                  &orders[order_count].order_id,
                  &orders[order_count].manager_id,
                  &orders[order_count].client_id,
                  orders[order_count].order_date,
                  &orders[order_count].amount) == 5) {
        order_count++;
    }

    fclose(orders_f);

    // Сортируем заказы
    qsort(orders, order_count, sizeof(Order), compareOrders);

    FILE *orders_sorted_f = fopen("orders_sorted.txt", "w");
    if (orders_sorted_f == NULL) {
        perror("Failed to open orders_sorted.txt");
        return EXIT_FAILURE;
    }

    fprintf(orders_sorted_f, "order_id, manager_id, client_id, order_date, amount");
    for (int i = 0; i < order_count; i++) {
        fprintf(orders_sorted_f, "%d. %d %d %s %.2f",
                orders[i].order_id,
                orders[i].manager_id,
                orders[i].client_id,
                orders[i].order_date,
                orders[i].amount);
    }

    fclose(orders_sorted_f);
    printf("orders done");

    return EXIT_SUCCESS;
}
