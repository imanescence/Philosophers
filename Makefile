# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iait-ouf <aitouflih.iman@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 17:33:28 by iait-ouf          #+#    #+#              #
#    Updated: 2025/05/29 17:16:11 by iait-ouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INCLUDE = library/philo.h

CFLAGS = -pthread -Wall -Werror -Wextra -finline-functions -fvectorize -fslp-vectorize -ffast-math -falign-functions -funroll-loops -fstrict-aliasing -fomit-frame-pointer -flto -Ofast -O1 -O2 -Os -O3 #-fsanitize=address -g
# If needed fsanitize and debug flag just here to see if there are data races

SRCS = 	   srcs/main.c\
	   srcs/parsing_utils.c\
	   srcs/routine.c\
	   srcs/routine_utils.c\
	   srcs/init.c\
	   srcs/free_handler.c\
	   srcs/display_utils.c

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
