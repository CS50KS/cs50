#include <stdio.h>

int main(void) {

    struct greedy { // пользовательский тип данных - структура Жадина

        int denomination; // элемент структуры - номинал монеты
        int quantity;     // элемент структуры - количество монет данного номинала

    };

    struct greedy atm[] = { // массив элементов типа структура Жадина

        {50, 10},
        {25, 15},
        {10, 30},
        {5, 0},
        {1, 7}

    };

    int size = sizeof(atm) / sizeof(struct greedy);
    int amount = 0;
    int total = 0;
    int transaction[size];

    // запрос на ввод суммы наличными
    do {

        printf("Какая сумма наличными Вам нужна? \n");
        scanf("%d", &amount);

    } while (!(amount > 0));

    // есть ли вообще такая сумма денег?
    for (int i = 0; i < size; i++) {

        total += atm[i].denomination * atm[i].quantity;

    };
    if (amount > total) {

        printf("К сожалению, в банкомате нет достаточной суммы наличных денег! :=( \n");
        return 1;

    };

    // можно ли ее выдать?
    for (int i = 0; i < size; i++) {

        int number = 0;
        transaction[i] = 0;
        while (amount >= atm[i].denomination && atm[i].quantity > 0) {

            amount -= atm[i].denomination;
            atm[i].quantity--;
            number++;

        };
        transaction[i] = number;

    };
    if (amount) {

        printf("К сожалению, банкомат не может выдать именно эту сумму наличными! :=( \n");
        return 2;

    };

    // выдаем деньги
    printf("К выдаче: \n");
    for (int i = 0; i < size; i++) {

        if (transaction[i]) {

            printf("%d - %d \n", atm[i].denomination, transaction[i]);

        };

    };

    // успешно завершаем программу
    printf("Транзакция завершена успешно! :=) \n");
    return 0;

}