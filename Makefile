# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 19:09:21 by rihoy             #+#    #+#              #
#    Updated: 2024/01/17 12:16:35 by rihoy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom des programmes
NAME = push_swap
BONUS = checker

# Compilateur et options
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -fr

# Dossiers des sources
SRC_DIR = srcs
DIR_SWAP = push_swap_dir
DIR_BONUS = checker_dir

# Couleurs
NOIR = \033[0;30m
ROUGE = \033[1;31m
VERT = \033[1;32m
JAUNE = \033[0;33m
BLEU = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
BLANC = \033[0;37m
RESET = \033[0m

# Dossiers des fichiers objets
OBJS_SWAP_DIR = objs_push_swap
OBJS_BONUS_DIR = objs_bonus

# Fichiers sources
SRCS_SWAP =	$(SRC_DIR)/$(DIR_SWAP)/push.c \
			$(SRC_DIR)/$(DIR_SWAP)/rev_rota.c \
			$(SRC_DIR)/$(DIR_SWAP)/rota.c \
			$(SRC_DIR)/$(DIR_SWAP)/swap.c \
			$(SRC_DIR)/$(DIR_SWAP)/algo.c \
			$(SRC_DIR)/$(DIR_SWAP)/error_usage.c \
			$(SRC_DIR)/$(DIR_SWAP)/ft_split.c \
			$(SRC_DIR)/$(DIR_SWAP)/stack.c \
			$(SRC_DIR)/$(DIR_SWAP)/utils_algo.c \
			$(SRC_DIR)/$(DIR_SWAP)/utils_swap.c \
			$(SRC_DIR)/$(DIR_SWAP)/sec_utils.c \
			$(SRC_DIR)/$(DIR_SWAP)/utils_ref.c \
			$(SRC_DIR)/$(DIR_SWAP)/move_algo.c

SRCS_BONUS =	$(SRC_DIR)/$(DIR_BONUS)/get_next_line.c \
				$(SRC_DIR)/$(DIR_BONUS)/get_next_line_utils.c \
				$(SRC_DIR)/$(DIR_BONUS)/ope_check.c \
				$(SRC_DIR)/$(DIR_BONUS)/check.c

# Fichiers objets
OBJS_SWAP = $(SRCS_SWAP:$(SRC_DIR)/$(DIR_SWAP)/%.c=$(OBJS_SWAP_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:$(SRC_DIR)/$(DIR_BONUS)/%.c=$(OBJS_BONUS_DIR)/%.o)

# Calculer le nombre total de fichiers à compiler
TOTAL_FILES = $(words $(SRCS_SWAP) $(SRCS_BONUS))
FILES_COMPILED = 0

# Fonction pour calculer et afficher le pourcentage et le nom du fichier
define update_progress
	$(eval FILES_COMPILED=$(shell echo $$(($(FILES_COMPILED)+1))))
	@echo "$(JAUNE)[$(shell echo $$(($(FILES_COMPILED)*100/$(TOTAL_FILES))))%] Compilation de $<$(RESET)"
endef

# Règles
all: $(NAME)
	@echo "$(VERT)COMPILATION TERMINE$(RESET)"

bonus: all $(BONUS)
	@echo "$(VERT)BONUS COMPILÉ$(RESET)"

# Compilation du programme principal
$(NAME): $(OBJS_SWAP)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_SWAP) $(SRC_DIR)/$(DIR_SWAP)/main.c

# Compilation du bonus
$(BONUS): $(OBJS_BONUS)
	@$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BONUS) $(OBJS_SWAP)

# Création des fichiers objets pour le programme principal
$(OBJS_SWAP_DIR)/%.o: $(SRC_DIR)/$(DIR_SWAP)/%.c
	@mkdir -p $(OBJS_SWAP_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(call update_progress,$<)

# Création des fichiers objets pour le bonus
$(OBJS_BONUS_DIR)/%.o: $(SRC_DIR)/$(DIR_BONUS)/%.c
	@mkdir -p $(OBJS_BONUS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(call update_progress,$<)

# Nettoyage
clean:
	@$(RM) $(OBJS_SWAP_DIR) $(OBJS_BONUS_DIR)
	@echo "$(ROUGE)FICHIERS SUPPRIMÉS$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@echo "$(ROUGE)EXECUTABLES SUPPRIMÉS$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re
