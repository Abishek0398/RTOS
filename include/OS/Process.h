#ifndef PROCESS_H
#define PROCESS_H
#include <stdint.h>
void os_task_create(void(*fun_ptr)(),uint32_t *stack_base,uint32_t stack_size,uint32_t priority);
void os_stack_init(uint32_t **stack_base,void(*fun_ptr)());
struct tcb
{
	uint32_t *stak_base;
	uint32_t pid;
	struct tcb *next;
	struct tcb *prev;
	uint8_t priority;
	uint32_t process_state;     
	uint32_t stack_size;
	uint32_t program_counter;
};
#endif