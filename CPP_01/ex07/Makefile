# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salome <salome@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/21 23:27:43 by salome            #+#    #+#              #
#    Updated: 2021/03/21 23:38:03 by salome           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Colors
NORMAL= \033[0m
GREY = \033[90m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
CYAN = \033[36m
PURPLE = \033[35m
RED = \033[31m
HIDDEN = \033[2m
ITALIC = \033[3m

# Pre-compiling
NAME		= replace
CC		 	= clang++
CPPFLAGS 	= -Wall -Wextra -Werror -std=c++98
FILES		= main.cpp
OBJS		= $(FILES:.cpp=.o)

# Compiling
all:	draw $(NAME)

$(NAME):	$(OBJS)
	@echo "$(CYAN)\nMODULE CPP 01/ex07 $(GREEN)\tREADY FOR EXEC$(NORMAL)"
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@echo "$(BLUE)$(HIDDEN)COMPILATION $(NORMAL)$(GREY)\t"$<
	@$(CC) $(CPPFLAGS) -c $< -o $@

# Cleaning
clean:
	@echo "$(BLUE)MODULE CPP 01/ex07 $(GREY)\t.O DELETION $(NORMAL)"
	@rm -f $(OBJS)

fclean:		clean
	@echo "$(BLUE)MODULE CPP 01/ex07 $(GREY)\tEXEC DELETION $(NORMAL)"
	@rm -f $(NAME)
	@echo "$(CYAN)\nMODULE CPP 01/ex07 $(GREEN)\tALL HAS BEEN CLEANED $(NORMAL)"

re: fclean all

# Designing
draw:
	@printf "\n"
	@printf "$(BLUE)  e88\'Y88 888 88e  888 88e      e88 88e     d88 \n"
	@printf "$(BLUE) d888  \'Y 888 888D 888 888D    d888 888b   d888 \n"
	@printf "$(BLUE)C8888     888 88\"  888 88\"    C8888 8888D d\"888 \n"
	@printf "$(BLUE) Y888  ,d 888      888         Y888 888P    888 \n"
	@printf "$(BLUE)  \"88,d88 888      888          \"88 88\"     888 \n"
	@printf "$(ITALIC)\t\t\t\t\t\t\tex07/replace\n"
	@printf "$(HIDDEN)$(ITALIC)\t\t\t\t\t\t\t sad-aude\n"
	@printf "$(NORMAL)																\n"
