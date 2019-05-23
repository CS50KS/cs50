#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // Раздел описания переменных
    float money;
    int coin, cash;
    
    // Ввод исходных данных
    printf("O hai! ");
    do
    {
        printf("How much change is owed? \n");
        money = GetFloat();
    }
    while (money <= 0);
    
    // Базовая логика программы
    money = money * 100;
    cash = roundf(money);
    coin = 0;
    
    while (cash >= 25)
    {
        cash = cash - 25;
        coin++;
    };
    
    while (cash >= 10)
    {
        cash = cash - 10;
        coin++;
    };
    
    while (cash >= 5)
    {
        cash = cash - 5;
        coin++;
    };
    
    while (cash >= 1)
    {
        cash = cash - 1;
        coin++;
    };
    
    // Вывод результата
    printf("%i\n", coin);
}