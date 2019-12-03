/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:39:51 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/03 21:20:13 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		x_close(t_env *env)
{
	Mix_FreeMusic(env->music[0]);
	Mix_FreeMusic(env->music[1]);
	Mix_FreeMusic(env->music[2]);
	Mix_FreeMusic(env->music[3]);
	SDL_Quit();
	(void)env;
	exit(0);
}
