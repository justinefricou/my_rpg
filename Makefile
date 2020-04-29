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
			src/scenes/scene_tmp_hover.c									\
			src/scenes/scene_tmp_hover_ws.c									\
			src/scenes/scn_utils.c											\
			src/scenes/scn_main_menu_buttons.c								\
			src/scenes/game/scene_game_event.c								\
			src/scenes/game/scene_game_bottom.c								\
			src/scenes/game/scene_game_bh.c									\
			src/scenes/game/scene_game_middle.c								\
			src/scenes/game/scene_game_top.c								\
			src/scenes/game/scene_game_hud.c								\
			src/scenes/game/scene_escape_menu.c								\
			src/scenes/game/game_scn_utils.c								\
			src/scenes/game/scn_esc_menu_buttons.c							\
			src/scenes/fight_scenes/scene_fight_event.c						\
			src/scenes/fight_scenes/scene_fight_bottom.c					\
			src/scenes/fight_scenes/scene_fight_middle.c					\
			src/scenes/fight_scenes/scene_fight_top.c						\
			src/scenes/fight_scenes/scene_fight_hud.c						\
			src/scenes/fight_scenes/game_scn_utils_fight.c					\

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
			src/components/cpt_tilecollide.c								\
			src/components/cpt_shape_rectangle.c							\
			src/components/cpt_shape_circle.c								\
			src/components/cpt_sprite.c										\

SRC_ENT =	src/entities/ent_music.c										\
			src/entities/ent_sprite.c										\
			src/entities/ent_text.c											\
			src/entities/ent_map.c											\
			src/entities/ent_map_collider.c									\
			src/entities/ent_button.c										\
			src/entities/ent_player.c										\
			src/entities/ent_event.c										\
			src/entities/hud/ent_hud_progress_bar.c							\
			src/entities/hud/ent_hud_box.c									\
			src/entities/hud/ent_hud_menu_selector.c						\
			src/entities/hud/ent_hud_inventory.c							\
			src/entities/hud/ent_hud_clues.c								\
			src/entities/hud/ent_hud_save.c									\
			src/entities/hud/ent_hud_status.c								\
			src/entities/hud/ent_hud_options.c								\
			src/entities/hud/ent_hud_htp.c									\
			src/entities/hud/ent_hud_load.c									\
			src/entities/hud/ent_hud_keymap_button.c						\
			src/entities/hud/ent_hud_text.c									\
			src/entities/hud/ent_cancel_menu_selector.c						\
			src/entities/fight_ent/ent_player_fight.c						\

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
			src/systems/sys_sprite.c										\

SRC_INI =	src/init/init_img.c												\
			src/init/init_audio.c											\
			src/init/general_data.c											\
			src/init/init_general_data_for_new_game.c						\
			src/init/set_sprite_id.c										\
			src/init/parsing/skills/skills.c								\
			src/init/parsing/skills/parse_skills.c							\
			src/init/parsing/dialogs/init_dialogs.c							\
			src/init/parsing/dialogs/parse_dialogs.c						\
			src/init/parsing/map/set_map_data.c								\
			src/init/parsing/map/map.c										\
			src/init/parsing/map/map_events.c								\
			src/init/parsing/map/get_map_content.c							\
			src/init/parsing/map/set_path.c									\
			src/init/parsing/events/create_event.c							\
			src/init/parsing/events/event.c									\
			src/init/parsing/events/get_event_content.c						\
			src/init/parsing/events/set_path.c								\

SRC_EVT =	src/events/variable.c											\
			src/events/create_events.c										\
			src/events/set_from_calcul.c									\
			src/events/type.c												\
			src/events/ins_set_intern.c										\
			src/events/instructions/ins_set.c								\
			src/events/instructions/ins_if.c								\
			src/events/instructions/ins_while.c								\
			src/events/instructions/ins_for.c								\
			src/events/instructions/ins_end.c								\
			src/events/instructions/ins_give.c								\
			src/events/instructions/ins_take.c								\
			src/events/instructions/ins_tp.c								\
			src/events/instructions/ins_dialog.c							\
			src/events/instructions/ins_talk.c								\
			src/events/instructions/ins_answer.c							\
			src/events/instructions/answer.c								\
			src/events/instructions/ins_battle.c							\
			src/events/instructions/ins_move.c								\
			src/events/instructions/give.c									\
			src/events/instructions/event_calculate.c						\
			src/events/instructions/calcul_condition.c						\

SRC_SPT =	src/scripts/script_player_controller.c							\
			src/scripts/scp_link_camera.c									\
			src/scripts/hud/button_action.c									\
			src/scripts/hud/scp_hud_progress_bar.c							\
			src/scripts/hud/menu_selector/script_hud_menu_selector.c		\
			src/scripts/hud/menu_selector/menu_selector_utils.c				\
			src/scripts/hud/menu_selector/menu_selector_set_data.c			\
			src/scripts/hud/inventory/scp_hud_inventory.c					\
			src/scripts/hud/inventory/inventory_utils.c						\
			src/scripts/hud/inventory/inventory_set_data.c					\
			src/scripts/hud/inventory/inventory_move.c						\
			src/scripts/hud/inventory/inventory_update_selector.c			\
			src/scripts/hud/inventory/inventory_update_slot.c				\
			src/scripts/hud/inventory/inventory_update_weight.c				\
			src/scripts/hud/inventory/inventory_action.c					\
			src/scripts/hud/inventory/invetory_action_action.c				\
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
			src/scripts/hud/options/options_set_main.c						\
			src/scripts/hud/options/options_set_escape.c					\
			src/scripts/hud/how_to_play/scp_hud_htp.c						\
			src/scripts/hud/how_to_play/htp_set_data.c						\
			src/scripts/hud/load/scp_hud_load.c								\
			src/scripts/hud/load/load_utils.c								\
			src/scripts/hud/load/load_set_data.c							\
			src/scripts/hud/keymap_button/scp_hud_keymap_button.c			\
			src/scripts/hud/keymap_button/kb_utils.c						\
			src/scripts/event/script_event.c								\
			src/scripts/event/get_event_from_name.c							\
			src/scripts/event/script_use.c									\
			src/scripts/fight/fight_manager.c								\

SRC_SAV =	src/save_load/save_load_utils.c									\
			src/save_load/set_save_infos.c									\
			src/save_load/game/save_game.c									\
			src/save_load/game/load_saved_game.c							\
			src/save_load/game/player/save_player_info.c					\
			src/save_load/game/player/load_saved_player_info.c				\
			src/save_load/game/player/save_player_status.c					\
			src/save_load/game/player/load_saved_player_status.c			\
			src/save_load/game/progression/save_inventory.c					\
			src/save_load/game/progression/load_saved_inventory.c			\
			src/save_load/game/progression/save_clues.c						\
			src/save_load/game/progression/load_saved_clues.c				\
			src/save_load/options/save_options.c							\
			src/save_load/options/load_saved_options.c						\
			src/save_load/options/save_options_volume.c						\
			src/save_load/options/load_saved_options_volume.c				\
			src/save_load/options/save_options_keymap.c						\
			src/save_load/options/load_saved_options_keymap.c				\

SRC_OTH =	src/other/tilemap.c												\
			src/other/transform.c											\
			src/other/objects.c												\
			src/other/update_options.c										\
			src/other/key_is_clicked.c										\
			src/other/keymap.c												\
			src/other/keycode_to_text.c										\
			src/other/inventory.c											\
			src/other/get_map_data.c										\
			src/other/objects/calming.c										\
			src/other/clues.c												\

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
		$(SRC_SAV)	\
		$(SRC_OTH)	\
		$(SRC_EVT)	\

LIB	=	$(SRC_LIB)	\

CFLAGS = -Iinclude -L./ -ldragon -fdiagnostics-color -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -g3

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o)

NAME	=	my_rpg

DEBUG	=	rpg.d

all:	$(NAME)	## Build the project

make_lib:
	@make -C dragon/

$(NAME): make_lib $(OBJ)
	@$(CC) -g3 -o $(NAME) $(OBJ) $(CFLAGS)
	@printf "[\e[1;34m-Link Obj-\e[0m] % 43s\n" $(NAME) | tr ' ' '.'
	@printf "[\e[1;34m-Link Main-\e[0m] % 43s\n" $(OBJ) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished compiling sources ▄▀▄▀▄▀\e[0m\n"
	@printf "[\e[1;35m-Link Lib-\e[0m] % 43s\n" $(LIB) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished compiling lib ▄▀▄▀▄▀\e[0m\n"

debug: make_lib $(OBJ) ## Lunch the debug
	@make -C dragon/
	@$(CC) -g3 -o $(DEBUG) $(OBJ) $(CFLAGS)
	@printf "[\e[1;34m-Link Obj-\e[0m] % 43s\n" $(DEBUG) | tr ' ' '.'
	@printf "[\e[1;34m-Link Main-\e[0m] % 43s\n" $(OBJ) | tr ' ' '.'
	@printf "[\e[1;34m-Link Main-\e[0m] % 43s\n" $(LIB) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished compiling sources debug ▄▀▄▀▄▀\e[0m\n"

clean: ## Clean the useless file
	@make clean -C dragon/
	@rm -rf $(OBJ)

fclean:	clean ## Clean the project
	@make fclean -C dragon/
	@rm -f $(NAME)
	@rm -f $(DEBUG)
	@rm -f saves/*.save
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(NAME) | tr ' ' '.'
	@printf "[\e[1;31m-RM-\e[0m] % 42s\n" $(DEBUG) | tr ' ' '.'
	@printf "\e[1;3;5;32m▀▄▀▄▀▄ Finished RM ▄▀▄▀▄▀\e[0m\n"


re:	fclean all ## Clean then compile

valgrind: fclean debug ## Launch valgrind
	@valgrind --show-leak-kinds=all --track-origins=yes ./$(DEBUG)

help: ## Help for the Makefile
	@cat $(MAKEFILE_LIST) | sed -En 's/^([a-zA-Z_-]+)\s*:.*##\s?(.*)/\1 "\2"/p' | xargs printf "\033[32m%-30s\033[0m %s\n"

.PHONY:	all build clean fclean re tests_run re_tests valgrind help