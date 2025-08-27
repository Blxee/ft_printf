#include "ft_printf.h"

static unsigned int g_capacity = MEM_INIT_CAPACITY;
static void **g_memory = NULL;

void *mem_alloc(unsigned int size)
{
	unsigned int i;
	unsigned int j;
	void *ptr;
	void **new_memory;

	if (g_memory == NULL)
	{
		g_memory = malloc(sizeof(void *) * g_capacity);
		j = 0;
		while (j < g_capacity)
			g_memory[j++] = NULL;
	}
	i = 0;
	while (g_memory[i])
		i++;
	if (i >= g_capacity)
	{
		g_capacity *= 2;
		new_memory = malloc(sizeof(void *) * g_capacity);
		j = 0;
		while (j < g_capacity / 2)
		{
			if (g_memory[j])
				new_memory[j] = g_memory[j];
			j++;
		}
		free(g_memory);
		g_memory = new_memory;
	}
	ptr = malloc(size);
	g_memory[i] = ptr;
	return (ptr);
}

void *mem_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int size;
	unsigned int i;

	size = old_size;
	if (new_size < size)
		size = new_size;
	new_ptr = mem_alloc(new_size);
	i = 0;
	while (i < size)
	{
		((char *)new_ptr)[i] = ((char *)ptr)[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}

void mem_free(void *ptr)
{
	unsigned int i;

	i = 0;
	while (i < g_capacity)
	{
		if (ptr == g_memory[i])
		{
			free(ptr);
			g_memory[i] = NULL;
			break;
		}
		i++;
	}
}

void mem_free_all(void)
{
	unsigned int i;

	i = 0;
	while (i < g_capacity)
	{
		if (g_memory[i])
		{
			free(g_memory[i]);
			g_memory[i] = NULL;
		}
		i++;
	}
	free(g_memory);
}
