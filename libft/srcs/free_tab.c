#include "./../includes/libft.h"

void	*free_tab(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str)
			free(str[i]);
		++i;
	}
	if (str)
		free(str);
	return (NULL);
}
