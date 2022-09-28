#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void Calculation(int money)
{
    // Generating variables in units of Korean currency
    int won50000, won10000, won7000, won5000, won1000, won500, won100, won50, won10; 

    won50000 = 0;
    won10000 = 0;
    won7000 = 0;
    won5000 = 0;
    won1000 = 0;
    won500 = 0;
    won100 = 0;
    won50 = 0;
    won10 = 0;

    // Process of making a locally optimal choices best at the moment
    if (money >= 50000)
    {
        won50000 = money / 50000;
        money = money % 50000;
    }

    if (money >= 10000)
    {
        won10000 = money / 10000;
        money = money % 10000;
    }

    if (money >= 5000)
    {
        won5000 = money / 5000;
        money = money % 5000;
    }

    if (money >= 1000)
    {
        won1000 = money / 1000;
        money = money % 1000;
    }

    if (money >= 500)
    {
        won500 = money / 500;
        money = money % 500;
    }

    if (money >= 100)
    {
        won100 = money / 100;
        money = money % 100;
    }

    if (money >= 50)
    {
        won50 = money / 50;
        money = money % 50;
    }

    if (money >= 10)
    {
        won10 = money / 10;
        money = money % 10;
    }

    printf("50000 won = %d\n", won50000);
    printf("10000 won = %d\n", won10000);
    printf("5000 won = %d\n", won5000);
    printf("1000 won = %d\n", won1000);
    printf("500 won= %d\n", won500);
    printf("100 won = %d\n", won100);
    printf("50 won = %d\n", won50);
    printf("10 won = %d\n", won10);

    int sum = won50000 + won10000 + won5000 + won1000 + won500 + won100 + won50 + won10;

    printf("Total number of used money = %d", sum);

}

void main()
{

    int money = 0;
    int numOfTypes = 0;

    // Get amount of money from users
    printf("Type the amount of money :"); 

    scanf("%d", &money);

    Calculation(money);

}

// It has optimal results, but may vary depending on the unit of money or the result.
// For example, let's say you have a currency of 1,3,7,10
// When you fill in 14 units of money, you get 1 unit of 10 and 4 units of 1,
// but the best result is to use 2 units of 7