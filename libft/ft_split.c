/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 14:19:58 by varodrig          #+#    #+#             */
/*   Updated: 2024/06/05 12:11:51 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char c)
{
	int	trigger;
	int	words;

	trigger = 0;
	words = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			words++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (words);
}

static char	*ft_write_words(char const *str, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i++] = str[start++];
	}
	word[i] = '\0';
	return (word);
}

static int	free_all(char **result, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

static int	split_words(char **result, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index == -1)
			index = i;
		else if ((s[i] == c || s[i] == '\0') && index != -1)
		{
			result[j] = ft_write_words(s, index, i);
			if (!(result[j]))
				return (free_all(result, j));
			index = -1;
			j++;
		}
		i++;
	}
	result[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!split_words(result, s, c))
		return (NULL);
	return (result);
}
/*
int main(void)
{
	char	*str;
	char	**result;
	char	**temp;

	str = "lundi   mardi mercredi ";
	result = ft_split(str, ' ');
	temp = result;
	while (*temp)
	{
		printf("%s\n", *temp);
		free(*temp);
		temp++;
	}
	free(result);
	return (0);
}
*/
