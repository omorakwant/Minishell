/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:47:53 by odahriz           #+#    #+#             */
/*   Updated: 2025/04/10 13:30:43 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int checksyntax(char *line)
{
	int i = 0;
	
	while(line[i])
	{
		if(line[i] == '|' && line[i + 1] == '|')
		{
			printf("Syntax error: unexpected token '||'\n");
			return (1);
		}
		if(line[i] == '&' && line[i + 1] == '&')
		{
			printf("Syntax error: unexpected token '&&'\n");
			return (1);
		}
		if(line[i] == '|' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
		{
			printf("Syntax error: unexpected token '|'\n");
			return (1);
		}
		if(line[i] == '&' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
		{
			printf("Syntax error: unexpected token '&'\n");
			return (1);
		}
		if(line[i] == '<' && line[i + 1] == '<')
		{
			printf("Syntax error: unexpected token '<<'\n");
			return (1);
		}
	}
	return	(0);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char *line;
	//char **args;
	
	while(1)
	{
		line = readline("minishell> ");
		if(!line)
		{
			printf("exit\n");
			break;
		}
		checksyntax(line);
		add_history(line);
	}
	return (0);
}