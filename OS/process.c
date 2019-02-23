#include "Process.h"
#include "Queues.h"
#include "os.h"
void os_task_create(void(*fun_ptr)(),uint32_t *stack_base,uint32_t stack_size,uint32_t priority)
{
	struct tcb temp;
	uint32_t **t=&stack_base;
	temp.pid=counter++;
	temp.next=NULL;
	temp.prev=NULL;
	temp.priority=priority;
	temp.process_state=READY;
	temp.stak_base=stack_base;
	temp.stack_size=stack_size;
	temp.program_counter=(uint32_t)fun_ptr;
	os_stack_init(t,fun_ptr);
	struct tcb *temp_pt=&temp;
	start_critical();
	add_ready_queue(temp_pt);
	end_critical();
}
void os_stack_init(uint32_t **stack_base,void(*fun_ptr)())
{
	*(*stack_base)=0x01000000;
	*(*stack_base-1)=(uint32_t)fun_ptr;
	*(*stack_base-2)=0x14141414;
	*(*stack_base-3)=0x14141414;
	*(*stack_base-4)=0x14141414;
	*(*stack_base-5)=0x14141414;
	*(*stack_base-6)=0x14141414;
	*(*stack_base-7)=0x14141414;
	*(*stack_base-8)=0x14141414;
	*(*stack_base-9)=0x14141414;
	*(*stack_base-10)=0x14141414;
	*(*stack_base-11)=0x14141414;
	*(*stack_base-12)=0x14141414;
	*(*stack_base-13)=0x14141414;
	*(*stack_base-14)=0x14141414;
	*(*stack_base-15)=0x14141414;
	*stack_base=*stack_base-15;
}
	
	
 //Stacks[i][STACKSIZE-1] = 0x01000000; // Thumb bit 
  //Stacks[i][STACKSIZE-3] = 0x14141414; // R14 
  //Stacks[i][STACKSIZE-4] = 0x12121212; // R12 
  //Stacks[i][STACKSIZE-5] = 0x03030303; // R3 
  //Stacks[i][STACKSIZE-6] = 0x02020202; // R2 
  //Stacks[i][STACKSIZE-7] = 0x01010101; // R1 
  //Stacks[i][STACKSIZE-8] = 0x00000000; // R0 
  //Stacks[i][STACKSIZE-9] = 0x11111111; // R11 
  //Stacks[i][STACKSIZE-10] = 0x10101010; // R10 
  //Stacks[i][STACKSIZE-11] = 0x09090909; // R9 
  //Stacks[i][STACKSIZE-12] = 0x08080808; // R8 
  //Stacks[i][STACKSIZE-13] = 0x07070707; // R7 
  //Stacks[i][STACKSIZE-14] = 0x06060606; // R6 
  //Stacks[i][STACKSIZE-15] = 0x05050505; // R5 
  //Stacks[i][STACKSIZE-16] = 0x04040404; // R4 

	
	
	
	
	
	
	