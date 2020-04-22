/*
** EPITECH PROJECT, 2020
** script_monster
** File description:
** script player controller
*/

#include <stdlib.h>
#include "libdragon.h"
#include "ecs.h"
#include "script.h"

typedef struct data {
    sfVector2f *from;
    sfVector2f *to;
} data_t;

static void set_updated_camera(char *name, sfVector2f c_pos)
{
    dg_scene_t *scene = dg_scene_manager_get_scene(name);
    dg_entity_t *camera = dg_get_entity(scene->entities, "camera");
    sfVector2f *pos = dg_entity_get_component(camera, "pos");

    pos->x = c_pos.x;
    pos->y = c_pos.y;
}

void update_other_camera(sfVector2f c_pos)
{
    set_updated_camera("layer_bottom", c_pos);
    set_updated_camera("layer_bh", c_pos);
    set_updated_camera("layer_middle", c_pos);
    set_updated_camera("layer_top", c_pos);
}

void *scp_link_camera_init(void *init_data)
{
    void **idata = (void **) init_data;
    data_t *data = malloc(sizeof(data_t));

    data->from = idata[0];
    data->to = idata[1];
    return data;
}

void scp_link_camera_loop(dg_entity_t *entity, dg_window_t *w,
    dg_array_t **entities, sfTime dt)
{
    script_t *script = (script_t *)dg_entity_get_component(entity, "script");
    data_t *data = script->data;

    update_other_camera(*(data->from));
}

void scp_link_camera_end(void *data)
{
    data_t *d = (data_t *)data;

    free(d);
}