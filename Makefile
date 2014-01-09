## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2014/01/09 10:12:01 by elhmn             #+#    #+#             ##
##   Updated: 2014/01/09 10:12:01 by elhmn            ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

SRC = main.c ft_tri.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(SRC)
	$(CC) $(FLAGS) $(SRC)

clean:
	rm a.out

re: clean all
