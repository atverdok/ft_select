
#include "../includes/ft_select.h"

int tputs_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}

//int main()
//{
//    struct termios	term;
//    int	height;
//    int	width;
//
//    save_attributes();
//    set_input_mode();
//    height = tgetnum ("li");
//    width = tgetnum ("co");
//    tputs(tgetstr("cl", NULL), 0, tputs_putchar);
//    printf("Hello, World!\n");
//    reset_input_mode();
//    return 0;
//}

int     main()
{
//    const char *name;
    char  *bp;
    char  *term;
    int   height;
    int   width;

    bp = malloc(sizeof(*bp));
//    name = "TERM";
    if ((term = getenv("TERM")) == NULL)
        return (1);
    printf("My terminal is %s.\n", term);
    tgetent(bp, term);
    height = tgetnum ("li");
    width = tgetnum ("co");
    printf("H : %d\nL : %d\n", height, width);
    free(bp);
    return (0);
}