#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    
    do
    {
        printf("Height: ");
        height = GetInt();
    }
    while ((height > 23)||(height < 0));
    
    for (int i = 0; i < height; i++)
    {
        for (int j = height - 1; j > i; j--)
        {
            printf(" ");
        };
        
        for (int j = 0; j < i + 2; j++)
        {
            printf("#");
        };
        
        printf("\n");
    };
}