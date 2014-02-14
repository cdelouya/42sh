/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 08:44:19 by hestela           #+#    #+#             */
/*   Updated: 2014/02/14 02:11:28 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <time.h>
# include <stdarg.h>

/*
** Define color constants for text decoration
*/
# define C_RESET "\033[1;0m"
# define C_BRIGTH "\033[1;1m"
# define C_DIM "\033[1;2m"
# define C_ULINE "\033[1;4m"
# define C_BLINK "\033[1;5m"
# define C_REV "\033[1;7m"
# define C_HIDE "\033[1;8m"

# define F_BLACK "\033[1;30m"
# define F_RED "\033[1;31m"
# define F_GREEN "\033[1;32m"
# define F_YELLOW "\033[1;33m"
# define F_BLUE "\033[1;34m"
# define F_MAGENTA "\033[1;35m"
# define F_CYAN "\033[1;36m"
# define F_WHITE "\033[1;37m"

# define B_BLACK "\033[1;40m"
# define B_RED "\033[1;41m"
# define B_GREEN "\033[1;42m"
# define B_YELLOW "\033[1;43m"
# define B_BLUE "\033[1;44m"
# define B_MAGENTA "\033[1;45m"
# define B_CYAN "\033[1;46m"
# define B_WHITE "\033[1;47m"

/*
** Write functions
*/
int			ft_putchar(char c);
int			ft_putchar_fd(char c, int fd);
int			ft_putstr(char const *s);
int			ft_putstr_fd(char const *s, int fd);
int			ft_putnstr(char const *s, size_t n);
int			ft_putnstr_fd(char const *s, size_t n, int fd);
int			ft_putnbr(long n);
int			ft_putnbr_fd(long n, int fd);
int			ft_putendl(char const *s);
int			ft_putendl_fd(char const *s, int fd);
int			ft_putfnbr(double n, size_t precision);
int			ft_putfnbr_fd(double n, size_t precision, int fd);
int			ft_putadr(void const *p);
int			ft_putadr_fd(void const *p, int fd);
int			ft_put_time(const time_t clock);
int			ft_put_time_fd(const time_t clock, int fd);
int			ft_put_current_time(void);
int			ft_put_current_time_fd(int fd);

int			ft_printf(const char *format, ...);
void		ft_flags1(const char *form, va_list *ap, int *i, int *count);
void		ft_flags2(const char *form, va_list *ap, int *i, int *count);
void		ft_flags3(const char *form, va_list *ap, int *i, int *count);
void		ft_flags4(const char *form, va_list *ap, int *i, int *count);
void		ft_flags5(const char *form, va_list *ap, int *i, int *count);

int			g_fd;
int			ft_printf_fd(int fd, const char *format, ...);
void		ft_flags1fd(const char *form, va_list *ap, int *i, int *count);
void		ft_flags2fd(const char *form, va_list *ap, int *i, int *count);
void		ft_flags3fd(const char *form, va_list *ap, int *i, int *count);
void		ft_flags4fd(const char *form, va_list *ap, int *i, int *count);
void		ft_flags5fd(const char *form, va_list *ap, int *i, int *count);

/*
** Convertion functions
*/
long		ft_atoi(const char *str);
char		*ft_itoa(long n);
long		ft_itob(long n);
long		ft_itoo(long n);
char		*ft_itoh(long n);
double		ft_atof(const char *str);
char		*ft_ftoa(double n, size_t precision);
long		ft_otoi(long n);
long		ft_otob(long n);
char		*ft_otoh(long n);
long		ft_htoi(char *hex);
long		ft_htob(char *hex);
long		ft_htoo(char *hex);
long		ft_btoi(long n);
long		ft_btoo(long n);
char		*ft_btoh(long n);
char		*ft_dtos(double n, int precision);
char		*ft_time_to_str(const time_t clock);
char		*ft_current_time_to_str(void);

/*
** Maths functions
*/
# define PI 3.14159265358979323846264338327950288
# define RAD(x) x / 57.2957795
# define DEG(x) x * 0.0174532925

void		ft_int_swap(int *a, int *b);
double		ft_pow(double x, double y);
double		ft_sqrt(double x);
int			ft_factorial(int nb);

/*
** Strings compare functions
*/
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp_case(const char *s1, const char *s2);
int			ft_strncmp_case(const char *s1, const char *s2, size_t n);
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
int			ft_strequ_case(char const *s1, char const *s2);
int			ft_strnequ_case(char const *s1, char const *s2, size_t n);
int			ft_match(char *s1, char *s2);

/*
** Memory functions
*/
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
void		*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memmove(void *s1, const void *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_memdel(void **ap);
void		*ft_memalloc(size_t size);

/*
** String Case functions
*/
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
char		*ft_str_upcase(char *str);
char		*ft_str_lowcase(char *str);
char		*ft_str_caps(char *str);
char		*ft_strrev(char *str);

/*
** General strings functions
*/
char		*ft_strcpy(char *s1, const char *s2);
char		*ft_strncpy(char *s1, const char *s2, size_t n);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_strndup(char const *s1, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
size_t		ft_strlen(const char *s);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_str_multi_join(int ac, ...);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);

/*
** Array int functions
*/
double		ft_array_int_sum(int *array, size_t size);
int			ft_array_int_max(int *array, size_t size);
int			ft_array_int_min(int *array, size_t size);
float		ft_array_int_avg(int *array, size_t size);
void		ft_array_int_sort(int *array, size_t size);
void		ft_array_int_rsort(int *array, size_t size);
void		ft_array_int_print(int *array, size_t size);

/*
** Array strings functions
*/
void		ft_array_str_sort(char **array);
void		ft_array_str_sort_case(char **array);
void		ft_array_str_rsort(char **array);
void		ft_array_str_rsort_case(char **array);
size_t		ft_array_str_len(char **array);
void		ft_array_str_print(char **array);
void		ft_array_str_free(char **array);
char		**ft_array_str_dup(char **array);
char		**ft_array_str_map(char **array, char *(*f)(char *));
void		ft_array_str_iter(char **array, char *(*f)(char *));

/*
** List functions
*/
typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

t_list		*ft_lstnew(void const *content, size_t content_size);
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list		*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem));
t_list		*ft_lstdup(t_list *lst);
t_list		*ft_lstndup(t_list *lst, size_t n);
size_t		ft_lstlen(t_list *lst);
void		ft_lstprint(t_list *lst);
void		ft_lstsort(t_list **alst);
void		ft_lstsort_case(t_list **alst);
void		ft_lstrsort(t_list **alst);
void		ft_lstrsort_case(t_list **alst);
void		ft_lstrev(t_list **alst);
t_list		*ft_lstdel_contain(t_list *list, char *str);

/*
** Get Next line
*/
# define BUFF_SIZE 1024

typedef struct			s_gnl
{
	int					fd_prev;
	char				*rest[100];
}						t_gnl;

int			ft_gnl(int const fd, char **line);

/*
** Environnement modification
*/

char		*ft_getenv(char **env, char *var);

#endif /* !LIBFT_H */
