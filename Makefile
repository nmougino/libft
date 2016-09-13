# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/05 16:20:26 by nmougino          #+#    #+#              #
#    Updated: 2016/09/13 03:26:51 by nmougino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Compilator - clang est plus sur que gcc
CC =		clang
CFLAGS =	-Wall -Wextra -Werror

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

#	Liste des sources
SRC =		ft_abs.c \
			ft_atoi.c \
			ft_bitlen.c \
			ft_bzero.c \
			ft_getlinesize.c \
			ft_getlline.c \
			ft_getnbrline.c \
			ft_gotoline.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_islow.c \
			ft_isprint.c \
			ft_isup.c \
			ft_itoa.c \
			ft_linesplit.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_max.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_min.c \
			ft_nbrlen.c \
			ft_nbrlenbase.c \
			ft_pow.c \
			ft_printf.c \
			ft_printf_addto.c \
			ft_printf_applyparams.c \
			ft_printf_conv.c \
			ft_printf_conv_b.c \
			ft_printf_conv_c.c \
			ft_printf_conv_di.c \
			ft_printf_conv_hexa.c \
			ft_printf_conv_mod.c \
			ft_printf_conv_o.c \
			ft_printf_conv_p.c \
			ft_printf_conv_s.c \
			ft_printf_conv_u.c \
			ft_printf_conv_uni.c \
			ft_printf_recupparam.c \
			ft_printf_setconvparts.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putnbrendl.c \
			ft_putnbrendl_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_sitoa.c \
			ft_sqrt.c \
			ft_stradd.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_strglu.c \
			ft_strinc.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnloc.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_swapchar.c \
			ft_swapint.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_uitoabase.c \
			get_next_line.c

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
	$(CC) $(CFLAGS)	-c -o $@ $^ -I$(INCDIR)

$(OBJDIR):
	@echo "$(GRA)$(CYA)@ ++ Objects compilation$(DEF)"
	@mkdir -p $(OBJDIR)

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
