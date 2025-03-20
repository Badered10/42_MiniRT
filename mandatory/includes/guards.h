/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guards.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:48:16 by baouragh          #+#    #+#             */
/*   Updated: 2025/03/18 07:50:26 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUARDS_H
# define GUARDS_H

int					split_len(char **split);
double				double_guard(char *arg, int line, double min, double max);
t_color				color_guard(char *color, int line);

t_vec3				point_guard(char *str, int line, double min, double max);

t_tambient_light	*ambient_lighting_guard(char **split, int line);
t_camera			*camera_guard(char **split, int line);
t_light				*light_guard(char **split, int line);
t_sphere			*sphere_guard(char **split, int line_count);
t_plane				*plane_guard(char **split, int line);
t_cylinder			*cylinder_guard(char **split, int line);
t_cone				*cone_guard(char **split, int line);
int					*anti_aliasing_guard(char **split, int line);
int					*screen_res_guard(char **split, int line);

#endif