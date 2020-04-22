/*
** EPITECH PROJECT, 2019
** libdragon
** File description:
** include the whole lib
*/

#ifndef LIBDRAGON_H_
#define LIBDRAGON_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "dragon/dg_array.h"
#include "dragon/dg_framebuffer.h"
#include "dragon/dg_window.h"
#include "dragon/dg_math.h"
#include "dragon/dg_spritesheet.h"
#include "dragon/dg_animation.h"
#include "dragon/dg_animator.h"
#include "dragon/dg_component.h"
#include "dragon/dg_entity.h"
#include "dragon/dg_system.h"
#include "dragon/dg_scene.h"
#include "dragon/dg_scene_manager.h"
#include "dragon/dg_cpt.h"
#include "dragon/dg_ressources.h"
#include "dragon/dg_event.h"

int dg_play(sfVector2u, char *, int, void *);
#endif
