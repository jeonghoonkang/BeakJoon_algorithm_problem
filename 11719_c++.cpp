#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer[10000];

    while (fgets(buffer, 10000, stdin) != NULL) {

        printf("%s", buffer);
    }


    return 0;
}


