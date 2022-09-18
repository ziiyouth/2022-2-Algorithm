#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// A function that flips pancakes based on a specific number
void flip_pan(int* pancake, int num)
{
    int temp;
    for (int i = 0; i < --num; i++)
    {
        temp = pancake[i];
        pancake[i] = pancake[num];
        pancake[num] = temp;
    }
}

// Find and flip the largest pancake value
int pancake_sort(int* pancake, int length)
{
    if (length < 2) {
        return 0;
    }

    int max_idx, flip;
    flip = 0;

    for (int i = length; i > 1; i--)
    {
        max_idx = 0;
        for (int j = 0; j < i; j++)
        {
            if (pancake[j] > pancake[max_idx])
                max_idx = j;
        }

        // Pancakes that fit that layer
        if (max_idx == i - 1)
            continue;

        if (max_idx != 0)
        {
            flip++;
            flip_pan(pancake, max_idx + 1);
        }
        flip++;
        flip_pan(pancake, i);
    }

    return flip;
}


int main()
{
    int pan = 0, n = 0;
    int pancake[30] = { 0 };

    while ((pan = getchar()) != EOF) {
        getchar();
        pancake[n] = pan - 48;
        //printf("%d ", pancake[n]);
        n++;

    }

    printf("Before : ");

    for (int i = 0; i < n; i++) {
        printf("%d ", pancake[i]);
    }

    int flip = pancake_sort(pancake, n);

    printf("\n");
    printf("After : ");

    for (int i = 0; i < n; i++) {
        printf("%d ", pancake[i]);
    }

    printf("\nFilp Number : %d\n", flip);

}