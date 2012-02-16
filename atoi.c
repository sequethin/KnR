#include <stdio.h>

int atoi(char s[]);
char *mychar;

int main(void) {
    mychar = "9";
    printf("Char %s is Int: %d", mychar, atoi(mychar));
}

int atoi(char s[]) {
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');

    return n;
}
