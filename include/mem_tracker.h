#ifndef MEM_TRACKER_H
#define MEM_TRACKER_H

#define MEM_INIT_CAPACITY (128)

void *mem_alloc(unsigned int size);
void *mem_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void mem_free(void *ptr);
void mem_free_all(void);

#endif
