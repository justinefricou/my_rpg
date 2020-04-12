/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** include the ecs objects
*/

#ifndef ECS_H_
#define ECS_H_

#include "libdragon.h"
#include "general_data.h"
#include "enemy_data.h"
#include "hud.h"

// scenes
dg_scene_t *scene_main_menu(void);
dg_scene_t *scene_escape_menu(void);
dg_scene_t *scene_how_to_play(void);
dg_scene_t *scene_game_event(void);
dg_scene_t *scene_game_hud(void);
dg_scene_t *scene_game_top(void);
dg_scene_t *scene_game_bottom(void);
dg_scene_t *scene_game_middle(void);

// entities
dg_entity_t *ent_music(char *path);
dg_entity_t *ent_sprite(int id, float scale, float x, float y);
dg_entity_t *ent_text(int x, int y, int scale, char *text);
dg_entity_t *ent_button(sfVector2f pos, int size, char *text
    , void (*action)(dg_window_t *));
dg_entity_t *ent_map(char *sheet, float scale, int **map, int fmod);
dg_entity_t *ent_build_menu(dg_entity_t *camera, dg_scene_t *scene);
dg_entity_t *entity_player_create();
dg_entity_t *ent_hud_box(int x, int y, int sx, int sy);
dg_entity_t *ent_hud_menu_selector(sfVector2f pos, button_t *button_list,
    dg_scene_t *scene, int has_box);

// components
dg_component_t *cpt_action(void (*action)(dg_window_t *));
dg_component_t *cpt_text(sfVector2f pos, int scale, char *content);
dg_component_t *cpt_scale(float x, float y);
dg_component_t *cpt_box_collider(float left, float top
    , float height, float width);
dg_component_t *cpt_spritesheet(dg_spritesheet_t *sheet);
dg_component_t *cpt_sound(char *path);
dg_component_t *cpt_tag(char *tag);
dg_component_t *cpt_subentity(void);
dg_component_t *cpt_script(void *(*init)(void *), dg_sysf_t loop,
    void (*end)(void *), void *idata);
dg_component_t *cpt_color(sfColor color);
dg_component_t *cpt_tilemap(int **map, dg_spritesheet_t *sheet,
    int free_map_on_destroy);
dg_component_t *cpt_shape_circle(sfVector2f pos, int size,
    sfColor fill, sfColor outline);
dg_component_t *cpt_shape_rectangle(sfVector2f pos, sfVector2f size,
    sfColor fill, sfColor outline);

// systems
void sys_render(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_display_text(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_button(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_escape(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_camera(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_script(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_player_control(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_tm_render(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_interact_dialogue(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_shape_circle(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);
void sys_shape_rectangle(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);

// init
void init_img(void);
void init_audio(void);
void set_build_id(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt);

// utilities
void sound_play(sfMusic *sound);
sfSprite *render_sprite(sfVector2f *scale, dg_spritesheet_t *sheet,
    sfVector2f *pos, sfColor *color);
void scn_change(dg_scene_t *scene, int status);
void scn_change_music(dg_scene_t *scene, int status);

#endif