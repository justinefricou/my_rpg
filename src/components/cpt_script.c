/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** tracker component
*/

#include <stdlib.h>
#include "libdragon.h"
#include "script.h"
#include "ecs.h"

static void component_destroy(void *data)
{
    script_t *script = (script_t *)data;

    if (script->end)
        script->end(script->data);
    free(script);
}

dg_component_t *cpt_script(void *(*init)(void *), dg_sysf_t loop,
    void (*end)(void *), void *idata)
{
    void (*destroy)(void *) = &component_destroy;
    dg_component_t *component = 0;
    script_t *script = malloc(sizeof(script_t));
    void *data = 0;

    script->init = init;
    script->loop = loop;
    script->end = end;
    if (init)
        data = init(idata);
    script->data = data;
    component = dg_component_create("script", script, destroy);
    return component;
}