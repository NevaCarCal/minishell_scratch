/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:14:22 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/15 04:10:43 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stddef.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
typedef struct s_array_data
{
	char	**new_arr;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
}					t_array_data;
int		ft_abs(int num);
char	**ft_arrjoin(char **arr1, char **arr2);
int		ft_arrlen(char **arr);
int		ft_atoi(const char *nptr);
int		ft_hextoi(char *hex_str, int n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_close(int fd);
int		ft_duplicate_check(t_list *lst, int num);
void	ft_error_exit(char *err_msg, int err_code);
void	ft_exit(char *msg, int ex_code);
int		ft_cr_open(char *filenamem);
int		count_strings(char const *s, char c);
void	ft_free_str_array(char **array);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isnumstr(char *str);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_is_eol_eof(char c);
char	*ft_itoa(int n);
void	ft_list_del(void *content);
void	ft_list_push(t_list **s_list, t_list **d_list, char *str);
void	ft_list_rev_rot(t_list **s_list, char *str);
void	ft_list_rot(t_list **s_list, char *str);
void	ft_list_swap(t_list **s_list, char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_open(char *filename, int flag);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_safe_atoi(const char *nptr, int *status);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin_tri(const char *s1, const char *s2, const char *s3);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_printf(char const *kw, ...);
int		ft_write(char *str, int out);
int		ft_print_unsigned_num(unsigned int n);
int		ft_print_str(const char *s);
int		ft_print_char(char c);
int		ft_print_num(int n);
int		print_hex_helper(uintptr_t address);
int		print_hex_helper_uc(unsigned int address);
char	*get_next_line(int fd);
size_t	ft_gstrlen(char *s);
char	*ft_gstrchr(char *s, int c);
char	*ft_gstrjoin(char *s1, char *s2);
char	*ft_gsubstr(char *s, unsigned int start, size_t len);
char	*ft_gstrdup(char *s);
int		compose_rgb(int r, int g, int b);
int		gradient(int start, int end, double percent);
int		c_red(int colour);
int		c_green(int colour);
int		c_blue(int colour);

#endif
