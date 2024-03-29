#include <stdio.h>
#include <string.h>

int main()
{
    char str[10];
    int k;
    printf("Use Only 0's or 1's\n");
    printf("Enter a string: ");
    scanf("%s", str);
    
    k = strlen(str);
    if (str[0] == '0' && str[k - 1] == '1')
        printf("Accepted\n");
    else
        printf("Not Accepted\n");

    return 0;
}
