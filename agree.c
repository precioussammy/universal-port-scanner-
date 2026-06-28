#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree \n");

    if( c=='Y' || c=='y')
    {
        printf("AGREED \n");
    }
    else
    {
        printf("NOTAGREED \n");
    }
}