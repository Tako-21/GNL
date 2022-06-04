#!/bin/bash
RED='0;31'
GREEN='1;32'
NC='0;0' # No Color
export GREP_COLOR=$GREEN
read -p "Insert size buffer : " buffersize
read -p "Insert number call : " nbcall
clear && gcc -g3 -D BUFFER_SIZE=$buffersize -D CALL=$nbcall *.c && valgrind --track-origins=yes --show-reachable=yes --leak-check=full ./a.out f1 | cat -e | grep --color -E "GNL.*$|/.*$|$"
#sed ''/a/s//`printf "\033[32mSTART\033[0m"`/''
