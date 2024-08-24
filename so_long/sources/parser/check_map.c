/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrancis <mfrancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:27:40 by mfrancis          #+#    #+#             */
/*   Updated: 2024/08/24 11:51:46 by mfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void check_map(t_fdf *fdf, char *file_name)
{
    int fd;
    
    if(check_file_name(file_name) != 1)
        free_exit(fdf, "Error - Wrong file name format.\n");
    //ft_printf("%d %s", check_file_name(file_name), file_name);
    fd = open(file_name, O_RDONLY);
    if(fd == -1)
        free_exit(fdf, "Error - File is not in the repository.\n");
    reading_file(fdf, fd);
    close(fd);
    fd = open(file_name, O_RDONLY);
    loading_map(fdf, fd);
    ft_printf("Saiu do loading map.\n");
    int i = 0;
    while (i < fdf->rows_nb)
    {
        int j = 0;
        ft_printf("Linha %d: ", i);
        while (j < fdf->cols_nb)
        {
            ft_printf("%d", fdf->map[i][j]);
            j++;
        }
        ft_printf("\n");
        i++;
    }
}
int check_file_name (char *file_name)
{
    int len;
    if(!*file_name)
        return(0);
    len = strlen(file_name);
    if(ft_strncmp(&file_name[len - 4], ".fdf", 5 ) == 0)
        return(1);         
    return(0);
}

void reading_file(t_fdf *fdf, int fd)
{
    char *line;
    int check_cols;
    ft_printf("Entrou no reading file.\n");
    line = get_next_line(fd);
    if(!line)
        free_exit(fdf, "Error - File is empty.\n");
    fdf->cols_nb  = counting_cols(fdf, line);
    while(line)
    {
        free(line);
        line = get_next_line(fd);
        if (line)
            check_cols = counting_cols(fdf, line);        
        if(fdf->cols_nb != check_cols)
            free_exit(fdf, "Error - Isn't a parallelogram.\n" );
        fdf->rows_nb++;
        //ft_printf("Dentro do loop no reading file.\n");
        //ft_printf("Number of coluns: %d\n", fdf->cols_nb); 
        //ft_printf("Number of rows: %d\n", fdf->rows_nb);        
    }
    ft_printf("Number of coluns: %d\n", fdf->cols_nb); 
    ft_printf("Number of rows: %d\n", fdf->rows_nb);        
   // ft_printf("Antes do loading map.\n");

   // loading_map(fdf, fd);
   // ft_printf("saiu do loading map.\n");

}
int counting_cols(t_fdf *fdf, char *line)
{
    char **temp;
    int cols_nb;
    int i;

    //ft_printf("Entrou no counting cols.\n");
    cols_nb = 0;
    temp = ft_split (line, ' ');
    while(temp[cols_nb])
    {
        i = 0;
        while(temp[cols_nb][i] && temp[cols_nb][i] != '\n')
        {
            if(temp[cols_nb][i] == ',')
                break;
            if(temp[cols_nb][i] == '-' && i == 0)
                i++;
            if(!ft_isdigit(temp[cols_nb][i]))
                free_exit(fdf, "Error - Encounter a non digit in the file\n");
            i++;
           // ft_printf("Dentro do loop no counting cols. \n");              
        }
        cols_nb++;
    }
    free_array_char(temp);
    //ft_printf("Saiu no counting cols.\n");
    return(cols_nb);
}
void loading_map(t_fdf *fdf, int fd)
{
    char *line;
    char **temp;
    int i;
    int j;
    
    ft_printf("Entrou no loading map.\n");
    
    i = 0;
    fdf->map = malloc(fdf->rows_nb *sizeof(int *));
    if(!fdf->map)
        free_exit(fdf, "Error - Malloc error.\n");
    while(i < fdf->rows_nb)
    {
        //ft_printf("Entrou no loop do loading map.\n");
        line = get_next_line(fd);
        fdf->map[i] = malloc(fdf->cols_nb * sizeof(int));
        if(!fdf->map[i])
            free_exit(fdf, "Error - Malloc error.\n");
        
        
       
        //ft_printf("Fez o split:\n");
        //for(int k = 0; temp[k] != NULL; k++)
        //   ft_printf("%s", temp[k]);
        // confirmar se preciso de protecao aqui em caso de falha a ler a memoria;
        
        j = -1;
         while(++j < fdf->cols_nb)
        {
            temp = ft_split(line, ' ');
            //for(int k = 0; temp[k] != NULL; k++)
            // ft_printf("%s", temp[k]);
           //ft_printf("Dentro do loop dentro loading map. antes do atoi.\n");
           // ft_printf("i: %d\n", i);
           // ft_printf("j: %d\n", j);
            //ft_printf("temp[j]: %s\n", temp[j]);
            fdf->map[i][j]= ft_atoi(temp[j]);
            //ft_printf("fdf->map[%d][%d]: %d\n", i, j, fdf->map[i][j]);
            //ft_printf("Dentro do loop dentro loading map. depois do atoi.\n");
        }
        free_array_char(temp);
        free(line);
        i++;
    }
    //free_array_char(temp);
}

/*
[x]PARSING
	[] finish in .ber
	[] The map can be composed of only these 5 characters:
		[] 0 for an empty space,
		[] 1 for a wall,
		[] C for a collectible,
		[] E for the exit,
		[] P for the player’s starting position.
	[] must contain
		[] 1 exit,
		[] 1 or more collectible
		[] 1 starting position
		[] be closed/surrounded by walls
	[] rectangular;
	[] message"Error\n"
*/