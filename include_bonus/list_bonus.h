#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	char				*token;
	int					kind;
	struct s_list		*next;
}		t_list;

char	*lst_to_string(t_list *lst);
size_t	lst_size(t_list *list);
t_list	*lst_new(void);
t_list	*lst_add_front(char *token, int kind, t_list *list);
t_list	*lst_add_back(char *token, int kind, t_list *list);
t_list	*lst_dup(t_list *list);
t_list	*lst_rm_front(t_list *list);
t_list	*lst_rm_back(t_list *list);
t_list	*lst_rm_next(t_list *list);
t_list	*lst_free(t_list *list);
t_list	*lst_free_env(t_list *list);
void	lst_print(t_list *list);
void	lst_sort_token(t_list *list);

#endif
