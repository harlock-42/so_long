#include "./../includes/libft.h"

void    **free_tab(char **tab)
{
    int     i;

    i = 0;
    while (tab && tab[i])
    {
            free(tab[i]);
            ++i;
    }
    free(tab);
    tab = NULL;
    return (NULL);
}