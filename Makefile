# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/05 16:20:26 by nmougino          #+#    #+#              #
#    Updated: 2017/02/08 22:07:45 by nmougino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Compilator - clang est plus sur que gcc
CC =		clang
CFLAGS =	-Weverything

#	Binary
NAME =		libft.a
DST =		.

#	Default rule
DEFRULE =	all

#	Dossiers utiles
SRCDIR =	srcs
INCDIR =	includes
LIBDIR =	libs
OBJDIR =	objs
DETDIR =	array display list math memory misc printf string

#	Liste des sources
SRC =		array/ft_arrglu.c \
			array/ft_arrlen.c \
			display/ft_putchar.c \
			display/ft_putchar_fd.c \
			display/ft_putendl.c \
			display/ft_putendl_fd.c \
			display/ft_putnbr.c \
			display/ft_putnbr_fd.c \
			display/ft_putnbrendl.c \
			display/ft_putnbrendl_fd.c \
			display/ft_putstr.c \
			display/ft_putstr_fd.c \
			get_next_line.c \
			list/ft_lstadd_end.c \
			list/ft_lstadd_sort.c \
			list/ft_lstadd_top.c \
			list/ft_lstdel.c \
			list/ft_lstiter.c \
			list/ft_lstmap.c \
			list/ft_lstnew.c \
			math/ft_abs.c \
			math/ft_absmax.c \
			math/ft_bitlen.c \
			math/ft_max.c \
			math/ft_maxst.c \
			math/ft_min.c \
			math/ft_minst.c \
			math/ft_nbrlen.c \
			math/ft_nbrlenbase.c \
			math/ft_nbrlenbasemax.c \
			math/ft_nbrlenmax.c \
			math/ft_pow.c \
			math/ft_sqrt.c \
			math/ft_tolower.c \
			memory/ft_bzero.c \
			memory/ft_memalloc.c \
			memory/ft_memchr.c \
			memory/ft_memcmp.c \
			memory/ft_memcpy.c \
			memory/ft_memdel.c \
			memory/ft_memmove.c \
			memory/ft_memset.c \
			misc/ft_atoi.c \
			misc/ft_free.c \
			misc/ft_isalnum.c \
			misc/ft_isalpha.c \
			misc/ft_isascii.c \
			misc/ft_isdigit.c \
			misc/ft_islow.c \
			misc/ft_isprint.c \
			misc/ft_isup.c \
			misc/ft_itoa.c \
			misc/ft_swapchar.c \
			misc/ft_swapint.c \
			misc/ft_toupper.c \
			printf/addto.c \
			printf/applyparams.c \
			printf/conv.c \
			printf/conv_b.c \
			printf/conv_c.c \
			printf/conv_di.c \
			printf/conv_hexa.c \
			printf/conv_mod.c \
			printf/conv_o.c \
			printf/conv_p.c \
			printf/conv_s.c \
			printf/conv_u.c \
			printf/conv_uni.c \
			printf/ft_printf.c \
			printf/ft_strnloc.c \
			printf/recupparam.c \
			printf/setconvparts.c \
			printf/sitoa.c \
			printf/uitoabase.c \
			string/ft_stradd.c \
			string/ft_strcat.c \
			string/ft_strchr.c \
			string/ft_strcloc.c \
			string/ft_strcmp.c \
			string/ft_strcpy.c \
			string/ft_strdel.c \
			string/ft_strdup.c \
			string/ft_strinschar.c \
			string/ft_strequ.c \
			string/ft_striter.c \
			string/ft_striteri.c \
			string/ft_strjoin.c \
			string/ft_strlcat.c \
			string/ft_strlen.c \
			string/ft_strmap.c \
			string/ft_strmapi.c \
			string/ft_strncat.c \
			string/ft_strncmp.c \
			string/ft_strncpy.c \
			string/ft_strnequ.c \
			string/ft_strnew.c \
			string/ft_strnstr.c \
			string/ft_strrchr.c \
			string/ft_strremchar.c \
			string/ft_strrev.c \
			string/ft_strsplit.c \
			string/ft_strstr.c \
			string/ft_strsub.c \
			string/ft_strtrim.c

LIB =
OBJ =		$(SRC:.c=.o)

#	Prefixes
LLIBP =		$(addprefix -l, $(LIB))
LIBP =		$(addprefix lib, $(LIB))
OBJP =		$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

#	Couleurs
DEF =		\033[0m
GRA =		\033[1m
SOU =		\033[4m
BLI =		\033[5m
BLA =		\033[30m
RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
PUR =		\033[35m
CYA =		\033[36m
WHI =		\033[37m

define \n


endef

# #
#	RULES
#

.PHONY = default glu all re $(OBJDIR) $(NAME) deplib clean fclean

#	Main rules
default:
	@echo "$(GRA)  DEFAULT RULE EXECUTION  :::  rule $(DEFRULE)$(DEF)"
	@$(addprefix make ,$(DEFRULE))
	@echo "$(GRE)$(GRA)Programme termine :)$(DEF)"

glu: re
	make clean

all: $(NAME)

re: fclean all

#	Compilation rules
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c  -o $@ $^ -I$(INCDIR)

$(OBJDIR):
	@echo "$(GRA)$(CYA)@ ++ Objects compilation$(DEF)"
	@mkdir -p $(OBJDIR)
	@mkdir -p $(addprefix "$(OBJDIR)/", $(DETDIR))

$(NAME): $(OBJDIR) $(OBJP)
	@echo "$(PUR)@ Library indexation$(DEF)"
	@ar rc $(NAME) $(OBJP)
	@ranlib $(NAME)

#	MrProper's legacy
clean:
	@echo "$(RED)@ Objects deletion$(DEF)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)@ Binary deletion$(DEF)"
	@rm -f $(NAME)
