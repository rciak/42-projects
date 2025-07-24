/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:42:14 by reciak            #+#    #+#             */
/*   Updated: 2025/07/24 09:40:36 by reciak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file libft.h
 * @brief The header file for reciak's libft library project of the Common Core
 */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>   // write
# include <stdbool.h>  // true, false
# include <stdlib.h>   // malloc, free   (also NULL definition aside stddef.h)
# include <stdint.h>   // intptr_t, uintptr_t
# include <limits.h>   // UINT_MAX

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"

enum e_libft_errors
{
	E_ARG_VAL = -1,
	E_WRITE = -10,
};

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}						t_list;

// Part 1: Some libc functions (and bsd relatives like  ft_strlcpy, ft_strcat)
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);

//Part 2: Some additional functions
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// Part 3: Bonus
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//ft_x_math01.c
size_t	si_min(size_t a, size_t b);
size_t	si_max(size_t a, size_t b);
int		abs(int n);

//ft_x_memtools1.c
int		si_is_overflow(size_t a, char action, size_t b);

//ft_x_strtools1.c
bool	is_in(char c, const char *str);

// Variants of ft_* functions that are in the same file as their ft-relatives.
char	*si_substr(char const *s, size_t start, size_t len);
void	*calloc_uninit(size_t nmemb, size_t size);

//
// Extensions added after eval of libft
//

//ft_xx_out1.c
int		out_nbr_fd(int nbr, char *digits, int fd);
int		out_unbr_fd(unsigned int nbr, char *digits, int fd);
int		out_uintptr_fd(uintptr_t unbr, char *digits, int fd);
int		out_str_fd(char *str, int fd);
int		out_vptr_fd(void *ptr, int fd);

//ft_xx_out2.c: Convenience wrappers fd = STDOUT_FD in previous 4 functions.
int		out_nbr(int nbr, char *digits);
int		out_unbr(unsigned int nbr, char *digits);
int		out_uintptr(uintptr_t unbr, char *digits);
int		out_str(char *str);
int		out_vptr(void *ptr);

//ft_xx_color_codes.c
const char	*color(int code);

#endif
