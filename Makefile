##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC_MAI = 	src/main.c														\

SRC_SCN =	src/scenes/scene_main_menu.c									\
			src/scenes/scene_main_menu_hover.c								\
			src/scenes/scn_utils.c											\
			src/scenes/scn_main_menu_buttons.c								\
			src/scenes/game/scene_game_event.c								\
			src/scenes/game/scene_game_bottom.c								\
			src/scenes/game/scene_game_middle.c								\
			src/scenes/game/scene_game_top.c								\
			src/scenes/game/scene_game_hud.c								\
			src/scenes/game/scene_escape_menu.c								\
			src/scenes/game/game_scn_utils.c								\
			src/scenes/game/scn_esc_menu_buttons.c							\

SRC_CPT =	src/components/cpt_action.c										\
			src/components/cpt_text.c										\
			src/components/cpt_scale.c										\
			src/components/cpt_box_collider.c								\
			src/components/cpt_spritesheet.c								\
			src/components/cpt_sound.c										\
			src/components/cpt_tag.c										\
			src/components/cpt_subentity.c									\
			src/components/cpt_script.c										\
			src/components/cpt_color.c										\
			src/components/cpt_tilemap.c									\
			src/components/cpt_shape_rectangle.c							\
			src/components/cpt_shape_circle.c								\

SRC_ENT =	src/entities/ent_music.c										\
			src/entities/ent_sprite.c										\
			src/entities/ent_text.c											\
			src/entities/ent_map.c											\
			src/entities/ent_button.c										\
			src/entities/ent_player.c										\
			src/entities/ent_hud_box.c										\
			src/entities/ent_hud_menu_selector.c							\
			src/entities/ent_hud_inventory.c								\
			src/entities/ent_hud_clues.c									\
			src/entities/ent_hud_save.c										\
			src/entities/ent_hud_status.c									\
			src/entities/ent_hud_options.c									\
			src/entities/ent_hud_htp.c										\
			src/entities/ent_hud_load.c										\

SRC_SYS =	src/systems/sys_render.c										\
			src/systems/sys_tm_render.c										\
			src/systems/sys_display_text.c									\
			src/systems/sys_button.c										\
			src/systems/sys_escape.c										\
			src/systems/sys_camera.c										\
			src/systems/sys_script.c										\
			src/systems/sys_interact_dialogue.c								\
			src/systems/sys_shape_circle.c									\
			src/systems/sys_shape_rectangle.c								\

SRC_INI =	src/init/init_img.c												\
			src/init/init_audio.c											\
			src/init/init_dialogs.c 										\
			src/init/parsing/pars_dialogs.c 								\

SRC_SPT =	src/scripts/script_build_menu.c									\
			src/scripts/script_player_controller.c							\
			src/scripts/hud/button_action.c									\
			src/scripts/hud/menu_selector/script_hud_menu_selector.c		\
			src/scripts/hud/menu_selector/menu_selector_utils.c				\
			src/scripts/hud/menu_selector/menu_selector_set_data.c			\
			src/scripts/hud/inventory/scp_hud_inventory.c					\
			src/scripts/hud/inventory/inventory_utils.c						\
			src/scripts/hud/inventory/inventory_set_data.c					\
			src/scripts/hud/clues/scp_hud_clues.c							\
			src/scripts/hud/clues/clues_utils.c								\
			src/scripts/hud/clues/clues_set_data.c							\
			src/scripts/hud/save/scp_hud_save.c								\
			src/scripts/hud/save/save_utils.c								\
			src/scripts/hud/save/save_set_data.c							\
			src/scripts/hud/status/scp_hud_status.c							\
			src/scripts/hud/status/status_utils.c							\
			src/scripts/hud/status/status_set_data.c						\
			src/scripts/hud/options/scp_hud_options.c						\
			src/scripts/hud/options/options_utils.c							\
			src/scripts/hud/options/options_set_data.c						\
			src/scripts/hud/how_to_play/scp_hud_htp.c						\
			src/scripts/hud/how_to_play/htp_utils.c							\
			src/scripts/hud/how_to_play/htp_set_data.c						\
			src/scripts/hud/load/scp_hud_load.c								\
			src/scripts/hud/load/load_utils.c								\
			src/scripts/hud/load/load_set_data.c							\

SRC_OTH =	src/other/tilemap.c												\
			src/other/transform.c											\

SRC_LIB =	lib/get_next_line.c			\
			lib/my_putarray.c			\
			lib/my_strcpy.c				\
			lib/str_to_array.c			\
			lib/tools_function.c		\
			lib/transform_character.c	\
			lib/my_strdup.c				\
			lib/itoa.c					\
			lib/my_revstr.c				\
			lib/nblen.c					\
			lib/my_strcat.c				\

SRC	=	$(SRC_MAI)	\
		$(SRC_SCN)	\
		$(SRC_CPT)	\
		$(SRC_ENT)	\
		$(SRC_SYS)	\
		$(SRC_MNT)	\
		$(SRC_INI)	\
		$(SRC_TOW)	\
		$(SRC_SPT)	\
		$(SRC_OTH)	\

LIB	=	$(SRC_LIB)	\

NAME	=	my_rpg

DEBUG	=	rpg.d

all:	$(NAME)	## Build the project

$(NAME):
	@make -C dragon/
	@$(CC) -g3 -o $(NAME) $(SRC) $(LIB) -Iinclude -L./ -ldragon -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window
	@printf "[\e[1;34m-Link Obj-\e[0m] % 43s\n" $(NAME) | tr ' ' '.'
	@printf "[\e[1;34m-Link Main-\e[0m] % 43s\n" $(SRC) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished compiling sources ▄▀▄▀▄▀\e[0m\n"
	@printf "[\e[1;35m-Link Lib-\e[0m] % 43s\n" $(LIB) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished compiling lib ▄▀▄▀▄▀\e[0m\n"

debug: ## Lunch the debug
	@make -C dragon/
	@$(CC) -g3 -o $(DEBUG) $(SRC) $(LIB) -Iinclude -L./ -ldragon -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window
	@printf "[\e[1;34m-Link Obj-\e[0m] % 43s\n" $(DEBUG) | tr ' ' '.'
	@printf "[\e[1;34m-Link Main-\e[0m] % 43s\n" $(SRC) | tr ' ' '.'
	@printf "[\e[1;34m-Link Main-\e[0m] % 43s\n" $(LIB) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished compiling sources debug ▄▀▄▀▄▀\e[0m\n"

clean: ## Clean the useless file
	@make clean -C dragon/

fclean:	clean ## Clean the project
	@make fclean -C dragon/
	@rm -f $(NAME)
	@rm -f $(DEBUG)
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(NAME) | tr ' ' '.'
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(DEBUG) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished RM ▄▀▄▀▄▀\e[0m\n"


re:	fclean all ## Clean then compile

valgrind: fclean debug ## Launch valgrind
	@valgrind --show-leak-kinds=all --track-origins=yes ./$(DEBUG)

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[32m%-30s\033[0m %s\n"

.PHONY:	all build clean fclean re tests_run re_tests valgrind help