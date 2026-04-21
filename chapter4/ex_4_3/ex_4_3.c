#include <stdio.h>
#include <stdlib.h> /* for  atof() */
#include <ctype.h>

/*
Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add
the modulus (%) operator and provisions for negative numbers.

Bài tập 4-3. Với khung cơ bản đã có, việc mở rộng máy tính này rất đơn giản.
Thêm toán tử modulo (%) và các chức năng cho số âm.
*/
#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* maximum depth of val stack */
#define BUFSIZE 100
char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */
int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */
int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
/* reverse Polish calculator */
main()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
        {
            int op2 = (int)pop();
            push((int)pop() % op2);
            break;
        }

        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

/* push:  push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}
/* pop:  pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}
/* getop:  get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    // bỏ qua khoảng trắng
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    // nếu không phải số, dấu chấm, hoặc dấu trừ thì trả về ngay
    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    i = 0;
    if (c == '-') {
        int next = getch();
        if (isdigit(next) || next == '.') {
            // đây là số âm
            s[i++] = c;   // lưu dấu '-'
            c = next;
        } else {
            // chỉ là toán tử trừ
            ungetch(next);
            return '-';
        }
    }

    if (isdigit(c))   // đọc phần nguyên
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')     // đọc phần thập phân
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}