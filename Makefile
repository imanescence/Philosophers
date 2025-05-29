# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 17:33:28 by iait-ouf          #+#    #+#              #
#    Updated: 2024/09/11 15:12:51 by iait-ouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INCLUDE = philo.h

CFLAGS = -pthread -Wall -Werror -Wextra -finline-functions -fvectorize -fslp-vectorize -ffast-math -falign-functions -funroll-loops -fstrict-aliasing -fomit-frame-pointer -flto -Ofast -O1 -O2 -Os -O3 #-fsanitize=address -g
# If needed fsanitize and debug flag just here to see if there are data races

SRCS = main.c\
	   parsing_utils.c\
	   routine.c\
	   routine_utils.c\
	   init.c\
	   free_handler.c\
	   display_utils.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)
	@echo "\x1b[38;5;229m   _      _      _      _      _      _      _      _      _      _      _   ";
	@echo " _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_ ";
	@echo "(_ 💭_)(_ 💭_)(_ 💭_)(_ 💭_)(_ 💭_)(_ 💭_)(_ 💭_)(_ 💭_)(_ 💭_)(_ 💭_)(_ 💭_)";
	@echo " (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_) ";
	@echo "   _   \x1b[38;5;105m     ___           ___                       ___       ___     \x1b[38;5;229m   _   ";
	@echo " _( )_ \x1b[38;5;105m    /\  \         /\__\          ___        /\__\     /\  \   \x1b[38;5;229m  _( )_ ";
	@echo "(_💭 _)\x1b[38;5;105m   /::\  \       /:/  /         /\  \      /:/  /    /::\  \   \x1b[38;5;229m(_ 💭_)";
	@echo " (_,_) \x1b[38;5;105m  /:/\:\  \     /:/__/          \:\  \    /:/  /    /:/\:\  \   \x1b[38;5;229m(_,_) ";
	@echo "   _   \x1b[38;5;105m /::\~\:\  \   /::\  \ ___      /::\__\  /:/  /    /:/  \:\  \  \x1b[38;5;229m  _   ";
	@echo " _( )_ \x1b[38;5;105m/:/\:\ \:\__\ /:/\:\  /\__\  __/:/\/__/ /:/__/    /:/__/ \:\__\ \x1b[38;5;229m_( )_ ";
	@echo "(_💭 _)\x1b[38;5;105m\/__\:\/:/  / \/__\:\/:/  / /\/:/  /    \:\  \    \:\  \ /:/  /\x1b[38;5;229m(_ 💭_)";
	@echo " (_,_) \x1b[38;5;105m     \::/  /       \::/  /  \::/__/      \:\  \    \:\  /:/  / \x1b[38;5;229m (_,_) ";
	@echo "   _    \x1b[38;5;105m     \/__/        /:/  /    \:\__\       \:\  \    \:\/:/  /  \x1b[38;5;229m   _   ";
	@echo " _( )_  \x1b[38;5;105m                 /:/  /      \/__/        \:\__\    \::/  /  \x1b[38;5;229m  _( )_ ";
	@echo "(_💭 _)  \x1b[38;5;105m                \/__/                     \/__/     \/__/   \x1b[38;5;229m (_ 💭_)";
	@echo " (_,_)                                                                 (_,_) ";
	@echo "   _      _      _      _      _      _      _      _      _      _      _   ";
	@echo " _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_  _( )_ ";
	@echo "(_💭 _)(_💭 _)(_💭 _)(_💭 _)(_💭 _)(_💭 _)(_💭 _)(_💭 _)(_💭 _)(_💭 _)(_💭 _)";
	@echo " (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_)  (_,_) ";




$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm  -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
