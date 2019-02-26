#include "Process.h"
#include "Queues.h"
#include "os.h"
void scheduler()
{
	start_critical();
	new_high_tcb=ready_queue_head;
	context_switch();
	end_critical();
}