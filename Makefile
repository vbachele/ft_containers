# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbachele <vbachele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 15:41:32 by vbachele          #+#    #+#              #
#    Updated: 2022/06/01 14:19:47 by vbachele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

SRC =				\
	main.cpp	\

OS = $(shell uname -s)
ifeq ($(OS),Darwin)
	CXX = c++
else
	CXX = c++
endif
CXXFLAGS = -fsanitize=address -g -Wall -Wextra -Werror -std=c++98
# to silence alloc: nano zone abandoned due to inability to preallocate reserved vm space.
# put MallocNanoZone=0 before launching the ./a.out

S = src
I = inc
B = .build
O = $(SRC:%.cpp=$(B)/%.o)
D = $(SRC:%.cpp=$(B)/%.d)

all: $(NAME)

$(NAME): $(O)
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "$(DONE) $@"

$(B):
	@mkdir $@

-include $(D)

$(B)/%.o: $(S)/%.cpp | $(B)
	@echo "$(COMPILE)$(NOC) $*.cpp"
	@$(CXX) $(CXXFLAGS) -MMD -MP $(I:%=-I %) -c $< -o $@

clean:
	@echo "$(INFO) deleting $(B)"
	@rm -rf $(B)

fclean: clean
	@echo "$(INFO) deleting $(NAME) $(OUTFILE)"
	@rm -f $(NAME) $(OUTFILE)

re: fclean all

push:
	@git add .
	@git status
	@git commit -m "cpp (make push)"
	@git push

.PHONY: all clean fclean re push

YELLOW	= \033[38;5;184m
GREEN	= \033[38;5;46m
CYAN	= \033[0;49;96m
COMPILE	= [$(CYAN)COMP$(NOC)]
INFO	= [$(YELLOW)INFO$(NOC)]
DONE	= [$(GREEN)DONE$(NOC)]
NOC		= \033[0m