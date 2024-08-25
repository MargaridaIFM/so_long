/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:27:40 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/25 00:55:09 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void check_map(t_data *data, char *file_name)
{
    int fd;

    if(check_file_name(file_name) != 1)
        free_exit(data, "Error - Wrong file name format\n");
    fd = open(file_name, O_RDONLY);
    if(fd == -1)
        free_exit(data, "Error - File is not in the repository.\n");
    check_map_shape(data, fd);
    ft_printf("Number of coluns: %d\n", data->cols_nb); 
    ft_printf("Number of rows: %d\n", data->rows_nb); 
    loading_map(data, fd);
    
    //check_map_criteria
    
}

int check_file_name(char *file_name)
{   
    int len;
    if(!file_name)
        return(0);
    len = ft_strlen(file_name);
    if (len < 4)
        return (0);
    if(strncmp(&file_name[len-4], ".ber", 4) == 0)
       return(1);
    return (0);
}

void check_map_shape(t_data *data, int fd)
{
    char *line;
    int check_cols;

    line = get_next_line(fd);
    if(!line)
        free_exit(data, "Error - File is empty.\n");
    data->cols_nb = ft_strlen_no_newline(line);
     ft_printf("First line length: %d\n", data->cols_nb);
    while(line)
    {
        data->rows_nb++;
        loading_map(data, line);
        check_cols = ft_strlen_no_newline(line); 
        ft_printf("Line %d length: %d\n", data->rows_nb, check_cols);
        if(data->cols_nb != check_cols)
        {
            free(line);
            free_exit(data, "Error - Isn't a parallelogram.\n");             
        }
        free(line);
        line = get_next_line(fd);
    }
    if(data->cols_nb == data->rows_nb)
        free_exit(data, "Error - Isn't a rectangule\n");
}
void loading_map(t_data *data, char *line)
{
    data->map = malloc()
    if(!data->map)
        
}
int	ft_strlen_no_newline(char *s)
{
	int	idx;

	idx = 0;
	if (!s)
		return (0);
	while (s[idx] && s[idx] != '\n')
		idx++;
	return (idx);
}
/*
[]PARSING 
	[] Map checklist
		[x] finish in .ber
        [x] Does the file exist
		[x] Is rectangular
			[x]num of line != num of colum
		[x] the map have content
		[] must contain
			[] be closed/surrounded by walls
			[] 1 exit
			[] 1 or more collectible
			[] 1 starting position 
		[] The map can be composed of only these 5 characters:
			[] 0 for an empty space,
			[] 1 for a wall,
			[] C for a collectible,
			[] E for the exit,
			[] P for the player’s starting position.
IMP --->[] message"Error\n"

	[]	Exit accessible and all the collectibles accessible from the start position 
		[] flood fill
		[] counter for the C and E;
		[] compare the counter with the number of C and E(parsing)
*/




// void check_map(t_data *data, char *file_name)
// {
//     int fd;
    
//     if(check_file_name(file_name) != 1)
//         free_exit(data, "Error - Wrong file name format.\n");
//     //ft_printf("%d %s", check_file_name(file_name), file_name);
//     fd = open(file_name, O_RDONLY);
//     if(fd == -1)
//         free_exit(data, "Error - File is not in the repository.\n");
//     reading_file(data, fd);
//     close(fd);
//     fd = open(file_name, O_RDONLY);
//     loading_map(data, fd);
//     ft_printf("Saiu do loading map.\n");
//     int i = 0;
//     while (i < data->rows_nb)
//     {
//         int j = 0;
//         ft_printf("Linha %d: ", i);
//         while (j < data->cols_nb)
//         {
//             ft_printf("%d", data->map[i][j]);
//             j++;
//         }
//         ft_printf("\n");
//         i++;
//     }
// }

// void reading_file(t_data *data, int fd)
// {
//     char *line;
//     int check_cols;
//     ft_printf("Entrou no reading file.\n");
//     line = get_next_line(fd);
//     if(!line)
//         free_exit(data, "Error - File is empty.\n");
//     data->cols_nb  = counting_cols(data, line);
//     while(line)
//     {
//         free(line);
//         line = get_next_line(fd);
//         if (line)
//             check_cols = counting_cols(data, line);        
//         if(data->cols_nb != check_cols)
//             free_exit(data, "Error - Isn't a parallelogram.\n" );
//         data->rows_nb++;
//         //ft_printf("Dentro do loop no reading file.\n");
//         //ft_printf("Number of coluns: %d\n", data->cols_nb); 
//         //ft_printf("Number of rows: %d\n", data->rows_nb);        
//     }
//     ft_printf("Number of coluns: %d\n", data->cols_nb); 
//     ft_printf("Number of rows: %d\n", data->rows_nb);        
//    // ft_printf("Antes do loading map.\n");

//    // loading_map(data, fd);
//    // ft_printf("saiu do loading map.\n");

// }

// void loading_map(t_data *data, int fd)
// {
//     char *line;
//     char **temp;
//     int i;
//     int j;
    
//     ft_printf("Entrou no loading map.\n");
    
//     i = 0;
//     data->map = malloc(data->rows_nb *sizeof(int *));
//     if(!data->map)
//         free_exit(data, "Error - Malloc error.\n");
//     while(i < data->rows_nb)
//     {
//         //ft_printf("Entrou no loop do loading map.\n");
//         line = get_next_line(fd);
//         data->map[i] = malloc(data->cols_nb * sizeof(int));
//         if(!data->map[i])
//             free_exit(data, "Error - Malloc error.\n");
        
        
       
//         //ft_printf("Fez o split:\n");
//         //for(int k = 0; temp[k] != NULL; k++)
//         //   ft_printf("%s", temp[k]);
//         // confirmar se preciso de protecao aqui em caso de falha a ler a memoria;
        
//         j = -1;
//          while(++j < data->cols_nb)
//         {
//             temp = ft_split(line, ' ');
//             //for(int k = 0; temp[k] != NULL; k++)
//             // ft_printf("%s", temp[k]);
//            //ft_printf("Dentro do loop dentro loading map. antes do atoi.\n");
//            // ft_printf("i: %d\n", i);
//            // ft_printf("j: %d\n", j);
//             //ft_printf("temp[j]: %s\n", temp[j]);
//             data->map[i][j]= ft_atoi(temp[j]);
//             //ft_printf("data->map[%d][%d]: %d\n", i, j, data->map[i][j]);
//             //ft_printf("Dentro do loop dentro loading map. depois do atoi.\n");
//         }
//         free_array_char(temp);
//         free(line);
//         i++;
//     }
//     //free_array_char(temp);
// }
