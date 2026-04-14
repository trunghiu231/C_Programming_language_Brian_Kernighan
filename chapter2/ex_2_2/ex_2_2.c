/*
Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.

Viết một vòng lặp tương đương với vòng lặp for ở trên mà không sử dụng && hoặc ||.
Vòng lặp for ở trên là:

for (i = 0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;

Giải: Điều kiện là phải có (c=getchar()) != '\n' && c != EOF thì mới thực hiện nội dung trong vòng lặp
    => có điều kiện ngược lại là (c=getchar()) == '\n' || c == EOF thì sẽ không thực hiện nội dung trong vòng lặp
    for (i = 0; i < lim - 1; ++i)
    {
        c = getchar();
        if (c == '\n')
        {
            break;
        }
        if (c == EOF)
        {
            break;
        }
        s[i] = c;
    }
*/
