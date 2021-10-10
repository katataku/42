#ifndef LIBFT_H
# define LIBFT_H
# define TRUE 1
# define FALSE 0
# include "stdlib.h"
# include "limits.h"
# include <unistd.h>
void			*ft_memset(void *buf, int ch, size_t n);
void			*ft_bzero(void *buf, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strcat(char *dest, char *src);
char			*ft_strnstr(const char *h, const char *n, size_t l);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
void			*ft_memmove(void *dst, const void *src, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
char			*ft_strrchr(const char *s, int c);
void			ft_putstr_fd(char *str, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_swap(int *a, int *b);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
#endif
