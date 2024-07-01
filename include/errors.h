/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:49:09 by tiacovel          #+#    #+#             */
/*   Updated: 2024/07/01 17:22:44 by denizozd         ###   ########.fr       */
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
#define FILE_EXT_ERR 18
#define FILE_OPEN_ERR 19
#define FILE_COR_ERR 20
#define MEM_ALC_ERR 21

/* Memory allocation exit code */
#define GC_MEM_ERR 30
#define MTX_MEM_ERR 31
#define SPLIT_MEM_ERR 32
#define MLX_MEM_ERR 33
