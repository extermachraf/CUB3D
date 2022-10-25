/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_outils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:27:22 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/10/25 01:04:31 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    free_double_p(char **str)
{
    int i;

    i = 0;
    while(str[i])
        free(str[i++]);
    free(str);
}

int lent_double_p(char **str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return(i);
}


int check_numbers(char **str)
{
    int i;
    int j;

    i = 0;
    while(str[i])
    {
        j = 0;
        while(str[i][j])
        {
            if(!(str[i][j] >= '0' && str[i][j] <= '9'))
                return(1);
            j++;
        }
        i++;
    }
    return(0);
}

char    **find_er(t_lexer *lexer, cub3d_t *cub, char *str)
{
    char    **spl_tmp;
    
    spl_tmp = ft_split(str, ',');
    free(str);
    if((lent_double_p(spl_tmp) < 3 
        || lent_double_p(spl_tmp) > 3) || check_numbers(spl_tmp))
    {
        free_double_p(spl_tmp);
        err_fre_lex_cub(lexer, cub);
    }
    return(spl_tmp);
}