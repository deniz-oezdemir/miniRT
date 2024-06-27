/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:49:09 by tiacovel          #+#    #+#             */
/*   Updated: 2024/06/27 17:41:01 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Parsing errors exit code */
#define AMB_LIGHT_ERR 10
#define CAMERA_ERR 11
#define CYLINDER_ERR 12
#define LIGHT_ERR 13
#define PLANE_ERR 14
#define SPHERE_ERR 15
#define CONE_ERR 16
#define MULTIPLE_OBJS 17

/* Memory allocation exit code */
#define GC_MEM_ERR 20
#define MTX_MEM_ERR 21
#define SPLIT_MEM_ERR 22
#define MLX_MEM_ERR 23
