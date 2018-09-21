/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:47:07 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/29 17:36:41 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MALLOC_H
# define _MALLOC_H

# include <unistd.h>
# include <sys/mman.h>
# include <sys/resource.h>
# include <stdio.h>
# include <string.h>
# include "malloclib/malloclib.h"

typedef struct			s_tiny_memory_space
{
	int						tiny_space_used;
	void					*tiny_space_ptr;
	void					*tiny_trav;
}						t_tiny_memory_space;

typedef struct			s_small_memory_space
{
	int						small_space_used;
	void					*small_space_ptr;
	void					*small_trav;
}						t_small_memory_space;

typedef struct			s_mega_memory_space
{
	int						distance_from_start;
	void					*large_space_ptr;
	void					*large_trav;
}						t_large_memory_space;

typedef struct			s_malloc_infoi
{
	t_tiny_memory_space		tiny;
	t_small_memory_space	small;
	t_large_memory_space	large;
	int						flag;
	long long				memory_used;
	void					*main_ptr;
	unsigned long long		tiny_malloc;
	unsigned long long		small_malloc;
	int						large_malloc;
	char					tiny_block[10000];
	char					small_block[10000];
	char					large_block[10000];
	int						free_size_val;
	int						total;
	unsigned long long		max;
	size_t					ptr_number;
}						t_malloc;

t_malloc				g_info;

struct rlimit			limit;

# define TINY_BLK	1
# define SMALL_BLK	2
# define LARGE_BLK	3
# define TINY_SIZE 	getpagesize() / 2
# define SMALL_SIZE	getpagesize() * 12

t_tiny_memory_space		tiny_memory_alloc(void);
t_small_memory_space	small_memory_alloc(void);
t_large_memory_space	large_memory_alloc(size_t size);

void					*malloc(size_t size);
void					free(void *ptr);
void					*realloc(void *ptr, size_t size);

void					free_superblock(void) __attribute__((destructor));
char					*resize_mem_dataspace(char *memory,
						int alloc_size,
						int current_length);
void					decode(char *memory_list, char c, void *mem_ptr);
void					tiny_small_large(char ac);
char					*write_memory_record(size_t bytes_allocated,
						char *current_memory);
int						first_runthrough(void *map_ptr,
						char *memory_list, char c);
void					*adjust_pointer(unsigned long size);
void					show_alloc_mem(void);
void					tiny_small_large(char c);
void					print_address_distance(int equation[],
						int ptr_num);
int						print_address(int equation[], int ptr_num,
						int *count);

#endif
