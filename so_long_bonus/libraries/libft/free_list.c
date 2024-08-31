/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:04:15 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/31 14:01:47 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void free_exit(t_data *data, char *str)
// {
//     if(str && str[0] != '\0')
//         ft_putstr_fd(str, 2);
//     if(data->a_head)
//         free_node(data->a_head);
//     if(data->b_head)
//         free_node(data->b_head);
//     exit(0);    
// }
// void free_node(t_node *node)
// {
//     t_node *temp;
//     while (node) 
//     {
//         temp = node->next;
//         free(node);
//         node = temp;
//     }
// }