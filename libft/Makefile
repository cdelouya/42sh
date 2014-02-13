#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hestela <hestela@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 08:42:55 by hestela           #+#    #+#              #
#    Updated: 2014/02/07 12:14:07 by hestela          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SOURCES = ft_atoi.c \
		ft_strcat.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strstr.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnstr.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlcat.c \
		ft_bzero.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_memmove.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstdup.c \
		ft_lstndup.c \
		ft_strequ_case.c \
		ft_strnequ_case.c \
		ft_int_swap.c \
		ft_array_int_sort.c \
		ft_array_int_rsort.c \
		ft_array_int_print.c \
		ft_array_str_print.c \
		ft_array_str_free.c \
		ft_array_str_len.c \
		ft_array_str_sort.c \
		ft_array_str_rsort.c \
		ft_array_int_sum.c \
		ft_array_int_avg.c \
		ft_ftoa.c \
		ft_putfnbr.c \
		ft_str_upcase.c \
		ft_str_lowcase.c \
		ft_str_caps.c \
		ft_array_str_iter.c \
		ft_array_str_dup.c \
		ft_array_str_map.c \
		ft_lstprint.c \
		ft_lstlen.c \
		ft_lstsort.c \
		ft_lstrsort.c \
		ft_strndup.c \
		ft_strcmp_case.c \
		ft_strncmp_case.c \
		ft_array_str_sort_case.c \
		ft_array_str_rsort_case.c \
		ft_lstsort_case.c \
		ft_lstrsort_case.c \
		ft_array_int_max.c \
		ft_array_int_min.c \
		ft_gnl.c \
		ft_lstrev.c \
		ft_putfnbr_fd.c \
		ft_atof.c \
		ft_itoo.c \
		ft_pow.c \
		ft_otoi.c \
		ft_strrev.c \
		ft_itoh.c \
		ft_htoi.c \
		ft_putadr.c \
		ft_putadr_fd.c \
		ft_itob.c \
		ft_btoi.c \
		ft_htob.c \
		ft_htoo.c \
		ft_otob.c \
		ft_otoh.c \
		ft_btoo.c \
		ft_btoh.c \
		ft_sqrt.c \
		ft_lstdel_contain.c \
		ft_put_time.c \
		ft_put_time_fd.c \
		ft_put_current_time.c \
		ft_put_current_time_fd.c \
		ft_time_to_str.c \
		ft_current_time_to_str.c \
		ft_dtos.c \
		ft_putnstr.c \
		ft_putnstr_fd.c \
		ft_printf.c \
		ft_output1.c \
		ft_output2.c \
		ft_output3.c \
		ft_output4.c \
		ft_output5.c \
		ft_printf_fd.c \
		ft_output1_fd.c \
		ft_output2_fd.c \
		ft_output3_fd.c \
		ft_output4_fd.c \
		ft_output5_fd.c \
		ft_factorial.c \
		ft_getenv.c

HEADERS = libft.h

OBJECTS = $(subst .c,.o,$(SOURCES))

WFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: %.c
	gcc $(WFLAGS) -c -o $@ $^

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
