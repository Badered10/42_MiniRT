/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baouragh <baouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 05:10:23 by abchikhi          #+#    #+#             */
/*   Updated: 2025/03/18 23:17:06 by baouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// t_trp_clrd will include a->total and b->light :) and c->base
static
void	light_result_(t_shadow *shad,
		t_light *l, t_vec3 *normal, t_trp_clrd *t_l)
{
	double	diffuse;
	double	specular;

	diffuse = 0.0;
	specular = 0.0;
	if (shad->shin > 0.0)
	{
		if (shad->shin == 1.0)
			diffuse = diffuse_light(normal, &shad->light_vec,
					l->brightness, shad->distance_to_light);
		if (shad->shin == 1.0)
			specular = specular_light(t_l->point, normal, l);
		if (shad->distance_to_light > 0)
		{
			t_l->b.r = t_l->b.r / shad->distance_to_light;
			t_l->b.g = t_l->b.g / shad->distance_to_light;
			t_l->b.b = t_l->b.b / shad->distance_to_light;
		}
		t_l->a.r += diffuse * t_l->b.r * t_l->c.r * shad->shin;
		t_l->a.g += diffuse * t_l->b.g * t_l->c.g * shad->shin;
		t_l->a.b += diffuse * t_l->b.b * t_l->c.b * shad->shin;
		t_l->a.r += specular * t_l->b.r * shad->shin;
		t_l->a.g += specular * t_l->b.g * shad->shin;
		t_l->a.b += specular * t_l->b.b * shad->shin;
	}
}

static
void	calc_sph_cy(t_shadow *shad, void *self)
{
	t_sphere	*s;
	t_cylinder	*cy;

	s = scene()->sphere_list;
	while (s)
	{
		shad->t = instersect_sphere(&shad->shadow_ray, s);
		if (s != self && shad->t > 0)
			effect_shadow(shad);
		s = s->next;
	}
	cy = scene()->cylinder_list;
	while (cy)
	{
		shad->t = intersect_cylinder(&shad->shadow_ray, cy);
		if (cy != self && shad->t > 0)
			effect_shadow(shad);
		cy = cy->next;
	}
}

static
void	calculate_shadow_int(t_shadow *shad, void *self)
{
	t_cone	*co;
	t_plane	*p;

	calc_sph_cy(shad, self);
	co = scene()->cone_list;
	while (co)
	{
		shad->t = intersect_cone(&shad->shadow_ray, co);
		if (co != self && shad->t > 0)
			effect_shadow(shad);
		co = co->next;
	}
	p = scene()->plane_list;
	while (p)
	{
		shad->t = intersect_plane(&shad->shadow_ray, p);
		if (p != self && shad->t > 0)
			effect_shadow(shad);
		p = p->next;
	}
	if (shad->delta > 0.0)
		shad->shin = shad->delta / shad->distance_to_light;
}

void	shadow_setup(t_shadow *shad, t_light *l,
		void *self, t_trp_clrd *tl)
{
	shad->shin = 1.0;
	shad->distance_to_light = sqrt(dot_(shad->light_vec, shad->light_vec));
	norm_(&shad->light_vec);
	shad->shadow_ray.origin = shad->shadow_origin;
	shad->shadow_ray.direction = shad->light_vec;
	shad->delta = 0.0;
	calculate_shadow_int(shad, self);
	tl->b.r = l->color.r / 255.0;
	tl->b.g = l->color.g / 255.0;
	tl->b.b = l->color.b / 255.0;
	shad->rand = shad->rand / 100.0;
}

t_color	shaded_color(t_vec3 *point, t_vec3 *normal,
		t_color *obj_color, void *self)
{
	t_trp_clrd	tl;
	double		ambient;
	t_shadow	shad;
	t_light		*l;

	ambient = ambient_light();
	tl.c = t_coloro_double(obj_color);
	tl.a.r = tl.c.r * ambient;
	tl.a.g = tl.c.g * ambient;
	tl.a.b = tl.c.b * ambient;
	l = scene()->light_list;
	while (l)
	{
		shad.light_vec = sub_(l->pos, *point);
		shad.shadow_origin = *point;
		tl.point = point;
		shadow_setup(&shad, l, self, &tl);
		light_result_(&shad, l, normal, &tl);
		l = l->next;
	}
	tl.a.r = pow(fmin(fmax(tl.a.r, 0.0), 1.0), 1.0 / 2.2);
	tl.a.g = pow(fmin(fmax(tl.a.g, 0.0), 1.0), 1.0 / 2.2);
	tl.a.b = pow(fmin(fmax(tl.a.b, 0.0), 1.0), 1.0 / 2.2);
	return (rgbd(tl.a.r, tl.a.g, tl.a.b));
}
