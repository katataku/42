#ifndef LIBFT_H
# define LIBFT_H

//My Bool
# define TRUE 1
# define FALSE 0
# include "stdlib.h"
# include "limits.h"
# include <unistd.h>



//part1-1 left
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_strlen(char *str);
void			*ft_memset(void *buf, int ch, size_t n);
void			*ft_bzero(void *buf, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
//strlcat

//part1-1 right
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
//strncmp
//memchr
//memcmp
char			*ft_strnstr(const char *h, const char *n, size_t l);
//atoi

//part1-2 using malloc
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);

//part2
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
//strtrim
//split
//itoa
//strmapi
//striteri
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
//putendl
//putnbr

//for split
typedef struct s_split_list
{
	int	start_index;
	int	len;
}	t_split_list;

//bonus

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list *ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void*));
void ft_lstclear(t_list **lst, void (*del)(void*));
void ft_lstiter(t_list *lst, void (*f)(void *));
int ft_lstsize(t_list *lst);
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//other
void			ft_putchar(char c);
void			ft_swap(int *a, int *b);
void			ft_putstr(char *str);
int				ft_strcmp(char *s1, char *s2);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
char			*ft_strcat(char *dest, char *src);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

#endif
