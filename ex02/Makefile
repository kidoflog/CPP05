# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkido <kkido@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/12 16:22:21 by kkido             #+#    #+#              #
#    Updated: 2026/09/13 21:16:10 by kkido            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = polymorphismForm

SRCS = main.cpp Bureaucrat.cpp AForm.cpp \
		ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp

OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

BLACK   = \033[0;30m
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
MAGENTA = \033[0;35m
CYAN    = \033[0;36m
WHITE   = \033[0;37m
RESET   = \033[0m

all: $(NAME)


$(NAME):$(OBJS)
	@echo "$(GREEN)[INFO]$(CYAN) Building $(WHITE)$(NAME)...$(RESET)"
	@$(CXX) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[OK]$(BLUE) Build completed!$(RESET)"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)[DONE] Object files removed.$(RESET)"

fclean:	clean
	@rm -f $(NAME)
	@echo "$(YELLOW)[DELETE]$(RED) All clean: $(NAME)$(RESET)"

re:
	@$(MAKE) fclean --no-print-directory
	@$(MAKE) all --no-print-directory

.PHONY: all clean fclean re
