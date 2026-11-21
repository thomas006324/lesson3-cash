#include <cs50.h>
#include <math.h>
#include <stdio.h>

// Removes as many of one coin as fit and returns how many were taken
int take(int *cents, int coin);

int main(void)
{
    // Ask for the change in dollars until it is not negative
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    // Convert to whole cents with rounding, because floats are not exact
    int cents = round(dollars * 100);

    // Greedy: take the biggest coin first, then move down
    int coins = 0;
    coins += take(&cents, 25);
    coins += take(&cents, 10);
    coins += take(&cents, 5);
    coins += take(&cents, 1);

    // Print only the number of coins
    printf("%i\n", coins);
}

int take(int *cents, int coin)
{
    // How many of this coin fit into the cents left
    int count = *cents / coin;

    // Subtract those coins from the cents left
    *cents = *cents - count * coin;

    return count;
}
