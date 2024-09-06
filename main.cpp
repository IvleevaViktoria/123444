#include <stdio.h>

int main() {
    int trade_id;
    printf("Enter Trade ID: ");
    scanf("%d", &trade_id);

    printf("Trade ID: %d", trade_id);

    int manager_count;
    printf("Введите количество менеджеров: ");
    scanf("%d", &manager_count);

    for (int i = 0; i < manager_count; ++i) {
        int manager_id;
        char name[50];
        char city[50];
        float comm;

        printf("Enter manager id, name, city, commission: ");
        scanf("%d %s %s %f", &manager_id, name, city, &comm);

        printf("Manager %d: ID = %d, Name = %s, City = %s, Commission = %.2f",
                i + 1, manager_id, name, city, comm);
    }

    return 0;
}

