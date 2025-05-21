/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:42:14 by reciak            #+#    #+#             */
/*   Updated: 2025/05/21 08:42:25 by reciak           ###   ########.fr       */
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
# include <limits.h>   // UINT_MAX

enum e_libft_errors
{
	ERRUNEXPECTEDVAL = -1,
	ERRNONE = 0
};

typedef unsigned char	t_uchar;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}						t_list;

// Part 1: Some libc functions
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
char	*strnstr(const char *big, const char *little, size_t len);
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

//ft_x_math01.c
size_t	si_min(size_t a, size_t b);
size_t	si_max(size_t a, size_t b);
int		abs(int n);

//ft_x_strtools1.c
bool	is_in(char c, const char *str);
size_t	strlen_deli(const char *s, const char *deli);
size_t	count_words(const char *s, const char *deli);

//ft_x_memtools1.c
int		si_is_overflow(size_t a, char action, size_t b);

// Variants of ft_* functions that are in the same file as their ft-relatives.
char	*si_substr(char const *s, size_t start, size_t len);
char	**split_deli(char const *s, const char *deli);
void	*calloc_uninit(size_t nmemb, size_t size);

#endif
