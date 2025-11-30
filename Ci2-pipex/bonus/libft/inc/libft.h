/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reciak <reciak@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:42:14 by reciak            #+#    #+#             */
/*   Updated: 2025/09/29 11:11:59 by reciak           ###   ########.fr       */
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
# include <values.h>   // Indirectly includes
//                          limits.h --> UINT_MAX
//                          float.h  --> DBL_MIN, DBL_MAX
// Note: The following caused norminette to print an "error" in red,
//       likely its parser does not deal properly with  float.h  ,
//       messing it up with the keyword  float ?!
//# include <float.h>    // DBL_MIN, DBL_MAX
//# include <limits.h>   // UINT_MAX

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"

/**
 * @warning The error code `E_ATOI_...`, `E_ATOLL_...`, `E_ATOF_...` are
 *          related to each other. Their relative differences should not 
 *          changed, since this will break the logic in 
 *          `atoll__err_to atof_err`, c.f. atof_stric().
 */
typedef enum e_libft_err
{
	E_ARG_VAL = -1,
	E_WRITE = -10,
	E_ATOI_NO_ERR = -20,
	E_ATOI_BAD_STRING = -21,
	E_ATOI_RANGE = -22,
	E_ATOLL_NO_ERR = -30,
	E_ATOLL_BAD_STRING = -31,
	E_ATOLL_RANGE = -32,
	E_ATOF_NO_ERR = -40,
	E_ATOF_BAD_STRING = -41,
	E_ATOF_RANGE_PANIC = -42,
	E_ATOF_MALLOC = -44,
}				t_libft_err;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}						t_list;

/**
 * @brief generic node for doubly linked list
 * @note \p obj must point to an object that was allocated on the heap
 */
typedef struct s_dl_node
{
	void				*obj;
	struct s_dl_node	*prev;
	struct s_dl_node	*next;
}							t_dl_node;

/**
 * @brief These are the return types of dl_lst_type()
 */
typedef enum e_dl_type
{
	DL_EMPTY = 0,
	DL_NON_EMPTY_LINEAR = 1,
	DL_NON_EMPTY_CIRCULAR = 2
}	t_dl_type;

// Section 0: Taken from Piscine / adopted:
int			ft_strcmp(const char *s1, const char *s2);

// Section 1: Most of very first common core project's
// Part 1: Some libc functions (and bsd relatives like  ft_strlcpy, ft_strcat)
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);

// Section 2: Most of very first common core project's
// Part 2: Some additional functions
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

// Section 3: Most of very first common core project's
// Part 3: Bonus: Singly linked list functions
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// Section 4: ft_printf     - see ft_printf.h

// Section 5: get_next_line - see get_next_line.h

// Section 6: Doubly linked list tools (developed during Ci2-Push_swap)
t_dl_node	*dl_lst_new_nd(void *obj);
void		dl_lst_add_after(t_dl_node **addr_pdl_node, t_dl_node *const pnew);
void		dl_lst_add_before(t_dl_node **addr_pdl_node, t_dl_node *const pnew);
void		dl_lst_circularize(t_dl_node *pdl_node);
void		dl_lst_linearize(t_dl_node *pdl_node);
size_t		dl_lst_size(const t_dl_node *const pdl_node);
t_dl_type	dl_lst_type(const t_dl_node *const pdl_node);
void		dl_lst_clear(t_dl_node **addr_pdl_node, void (*del)(void*));

// Section 7: Conversions with error info
//           (with additional strictness in case of atoi_strict)
int			atoi_proper(const char *nptr, t_libft_err *err_code);
int			atoi_strict(const char *nptr, t_libft_err *err_code);
long long	atoll_strict(const char *nptr, t_libft_err *err_code);
double		atof_strict(const char *nptr, t_libft_err *err_code);

// Section 8a: Output / ft_xx   (project ft_printf ...)
int			out_nbr_fd(int nbr, char *digits, int fd);
int			out_unbr_fd(unsigned int nbr, char *digits, int fd);
int			out_uintptr_fd(uintptr_t unbr, char *digits, int fd);
int			out_str_fd(char *str, int fd);
int			out_vptr_fd(void *ptr, int fd);
// Convenience wrappers fd = STDOUT_FD in previous 4 functions.
int			out_nbr(int nbr, char *digits);
int			out_unbr(unsigned int nbr, char *digits);
int			out_uintptr(uintptr_t unbr, char *digits);
int			out_str(char *str);
int			out_vptr(void *ptr);
// Section 8b: output functions - added after ft_printf project
void		ft_putllnbr_fd(long long n, int fd);

//Section 9: memtools
void		*calloc_uninit(size_t nmemb, size_t size);
int			si_is_overflow(size_t a, char action, size_t b);

//Section 10a: String tools / ft_x
char		*si_substr(char const *s, size_t start, size_t len);
bool		is_in(char c, const char *str);
// Section 10b: String tools - added after libft project
size_t		skip(char **pstr, const char *chars_to_skip);
size_t		strlen_deli(const char *s, const char *deli);
size_t		count_words(const char *s, const char *deli);
char		**split_deli(char const *s, const char *deli);
bool		is_listed(const char *str, const char **list);
void		free_array(char **string_array);

// Section 11a: math / ft_x  
//                    used by Part 1 - Part 3
size_t		si_min(size_t a, size_t b);
size_t		si_max(size_t a, size_t b);
int			abs(int n);
// Section 11b: math - later add-ons

#endif
