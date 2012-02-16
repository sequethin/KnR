#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);
void revString(char str[]);

/* print longest input line */
int main(void) {
    int len; /* current line length */
    int max; /* maximum length seen so far */

    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    char rev[MAXLINE];

    max = 0;
    while ((len = mygetline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(line, longest);
        }
    }

    if (max > 0) { /* there was a line */
        // should really print both here
        printf("Line is: %s", longest);
        revString(longest);
    }

    return 0;
}

/* getline: read a line into s, return length */
int mygetline(char s[], int lim) {
    int c, i;

    for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char from[], char to[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}

void revString(char str[]) {
    int i;
    int r;
    char rev[MAXLINE];
    // count size of array (is there a better way?)
    for (i = 0; i < MAXLINE-1 && str[i] != '\0'; ++i)
        ;

    for (r = 0; r < MAXLINE-1 && i >= 0; ++r, --i) {
        rev[r] = str[i];
        printf("%c", rev[r]);
    }
    printf("reverse is: %s", rev);
}
