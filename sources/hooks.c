#include "wolf3d.h"

int x_close(t_env *env)
{
	(void)env;
	exit (0);
}

static void rotate(int key, t_env *env)
{
	if (key == ARR_LFT || key == KB_A)
		env->cntrls->angle -= 0.05;
	if (key == ARR_RGHT || key == KB_D)
		env->cntrls->angle += 0.05;
	if (key == ARR_DOWN)
		env->cam->view_height += 100;
	if (key == ARR_UP)
		env->cam->view_height -= 100;
	env->cam->c_v_dir[X] = env->cam->v_dir[X] * cos(env->cntrls->angle * env->cam->r_speed) - env->cam->v_dir[Y] * sin(env->cntrls->angle * env->cam->r_speed);
	env->cam->c_v_dir[Y] = env->cam->v_dir[X] * sin(env->cntrls->angle * env->cam->r_speed) + env->cam->v_dir[Y] * cos(env->cntrls->angle * env->cam->r_speed);

	env->cam->c_v_plane[X] = env->cam->v_plane[X] * cos(env->cntrls->angle * env->cam->r_speed) - env->cam->v_plane[Y] * sin(env->cntrls->angle * env->cam->r_speed);
	env->cam->c_v_plane[Y] = env->cam->v_plane[X] * sin(env->cntrls->angle * env->cam->r_speed) + env->cam->v_plane[Y] * cos(env->cntrls->angle * env->cam->r_speed);
	renderer(env);
}

void player_move(int key, t_env *env)
{
	if (key == KB_W)
	{
		env->cam->pos[Y] += env->cam->c_v_dir[Y] * env->cam->m_speed;
		env->cam->pos[X] += env->cam->c_v_dir[X] * env->cam->m_speed;
	}
	if (key == KB_S)
	{
		env->cam->pos[X] -= env->cam->c_v_dir[X] * env->cam->m_speed;
		env->cam->pos[Y] -= env->cam->c_v_dir[Y] * env->cam->m_speed;
	}
	if (env->cam->pos[X] < (1.0 + env->cam->m_speed))
		env->cam->pos[X] = 1.0 + env->cam->m_speed;
	if (env->cam->pos[X] > env->map->width - (1.0 + env->cam->m_speed))
		env->cam->pos[X] = env->map->width - (1.0 + env->cam->m_speed);
	if (env->cam->pos[Y] < (1.0 + env->cam->m_speed))
		env->cam->pos[Y] = 1.0 + env->cam->m_speed;
	if (env->cam->pos[Y] > env->map->height - (1.0 + env->cam->m_speed))
		env->cam->pos[Y] = env->map->height - (1.0 + env->cam->m_speed);
	renderer(env);
}

int key_press(int key, t_env *env)
{
	if (key == ESC)
		x_close(env);
	if (key == ARR_DOWN || key == ARR_LFT || key == ARR_RGHT || 
	key == ARR_UP || key == KB_A || key == KB_D)
		rotate(key, env);
	if (key == KB_W || key == KB_S)
		player_move(key, env);
	return (0);
}

int mouse_move(int x, int y, t_env *env)
{
	if (env->mode == MENU)
	{
		bg_paralax(x, y, env);
		check_button_select(x, y, env);
		draw_menu(env);
	}
	return (0);
}

void init_key_hooks(t_env *env)
{
	mlx_hook(env->win, 17, 0, x_close, env);
	mlx_hook(env->win, 2, 0, key_press, env);
	mlx_hook(env->win, 4, 0, push_buttons, env);
	//mlx_hook(env->win, 5, 0, mouse_controls_release, env);
	mlx_hook(env->win, 6, 0, mouse_move, env);
}