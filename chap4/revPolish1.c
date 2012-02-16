/* Reverse Polish Calcluator from K & R pp 76-79 */
#include <stdio.h>
#include <stdlib.h> // for atof()

#define MAXOP 100 // max size of operand or operator
#define NUMBER '0' // signal that a number was found



int getop(char []);
void push(double);
double pop(void);

// reverse polish calculator

int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("ERROR: Division by zero attempted");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("ERROR: unknown command %s\n", s);
                return 1;
                break;
        }
    }
    return 0;
}

// stack stuff
#define MAXVAL 100 // maximum depth of the value stack
int sp = 0; // next free stack position
double val[MAXVAL];

// push: push f onto value stack
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("ERROR: stack is full cannot push %g\n", f);
    }
}

// pop: pop and return top value from stack
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("ERROR: stack empty\n");
        return 0.0;
    }
}

// getop: get the next operator or numeric operand
#include <ctype.h> // for isdigit
int getch(void);
void ungetch(int);

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        // skip blanks
    }

    s[1] = '\0';

    if (!isdigit(c) && c != '.') {
        return c; // not a number
    }

    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) {
            // fill S
        }
    }

    if (c == '.') { // collect fractional part
        while (isdigit(s[++i] = c = getch())) {
            // fill S
        }
    }

    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
}

// io stuff
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) { // get a (possibly pushed back) character
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { // push characater back on input
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
