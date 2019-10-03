#include <OS/tasks.h>
#include <OS/os.h>

void Func1(void *args)
{
	int a=0;
	int i=0;
	for( i=0; i<25; i++)
	a = a+1;
	for(i=0;i<50;i=i+2)
	a=a+2;
	os_scheduler();
}

void Func2(void *args)
{
	int b=0,a=0;
	int i=0;
  for( i=0; i<50;i++)
	{
	  a = a+1;
	  b = a+2;
  }
	os_scheduler();
}

void Func3(void *args)
{
	int b=0,a=0;
	int i=0;
  for( i=0; i<500;i++)
  {
	  a = a-1;
	  b = a+2;
  }
	os_scheduler();
}

void idle(void *args)
{
	while(1)
	{
	}
}

uint32_t stack1[200];
uint32_t stack2[200];
uint32_t stack3[200];
uint32_t stack_idle[200];

struct tcb a1,a2,a3,a4;

int main()
{
	os_init();
	struct tcb *temp1=&a1;
  struct tcb *temp2=&a2;
	struct tcb *temp3=&a3;
	struct tcb *temp4=&a4;
	
	uint32_t *stack_base1 = &stack1[199];
	uint32_t priority1 = 1;
	void (*user1_pt)(void*) = &Func1;
	os_task_create(temp1,user1_pt,(void*)0,stack_base1,200,priority1);
	
	uint32_t *stack_base2 = &stack2[199];
	uint32_t priority2 = 2;
	void (*user2_pt)(void*) = &Func2;
	os_task_create(temp2,user2_pt,(void*)0,stack_base2,200,priority2);
	
	uint32_t *stack_base3 = &stack3[199];
	uint32_t priority3 = 3;
	void (*user3_pt)(void*) = &Func3;
	os_task_create(temp3,user3_pt,(void*)0,stack_base3,200,priority3);
	
	uint32_t *stack_base_idle = &stack_idle[199];
	uint32_t priority_idle = 63;
	void (*idle_pt)(void*) = &idle;
	os_task_create(temp4,idle_pt,(void*)0,stack_base_idle,200,priority_idle);
	
	os_start();
	return 0;
}
