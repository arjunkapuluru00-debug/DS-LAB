#include <stdio.h>

int main() {
    char str[100];
    char *p;
    int length = 0;

    fgets(str, sizeof(str), stdin);
    p = str;

    while (*p != '\0') {
        if (*p != '\n')
            length++;
        p++;
    }

    printf("Length = %d", length);
    return 0;
}
