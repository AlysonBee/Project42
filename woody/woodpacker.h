

#ifndef WOODPACKER_H
# define WOODPACKER_H

# include <stdio.h>
# include "alylibc/inc/lib.h"
# include <elf.h>

typedef struct 		s_woody
{
	Elf64_Ehdr	*ehdr;
	Elf64_Phdr	*phdr;
	Elf64_Shdr	*shdr;
	unsigned char	*patch_return;
	char		*string_table;
}			t_woody;

/*
** Code ot patch the original entry point to the start of the file
*/

unsigned char 		*convert_address(Elf64_Addr original_entry);

/*
** Main woodywoodpacker program
*/

void			woodywoodpacker(unsigned char *content, size_t size);


#endif 
