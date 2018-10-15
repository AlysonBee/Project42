

#include "woodpacker.h"



void		woody_woodpacker(unsigned char *content, size_t size)
{
	t_woody	woodyboi;

	woodyboi.ehdr = (Elf64_Ehdr *)content;
	woodyboi.shdr = (Elf64_Shdr *)&content[woodyboi.ehdr->e_shoff];
	woodyboi.phdr = (Elf64_Phdr *)&content[woodyboi.ehdr->e_phoff];
	woodyboi.patch_return = convert_address(woodyboi.ehdr->e_entry);
	woodyboi.string_table = &content[woodyboi.shdr[
			woodyboi.ehdr->e_shstrndx].sh_offset];
		
}
