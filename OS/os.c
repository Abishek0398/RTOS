#include <OS/os.h>
#include <OS/Queues.h>
uint8_t start_flag=0;
void os_start()
{
	new_high_tcb=ready_queue_head;
	current_tcb=new_high_tcb;
	start_flag=1;
	os_first_task();
}