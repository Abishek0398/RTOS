#include "Queues.h"
#include "os.h"
 struct tcb *dispatched;
 int d_flag = 0;
 int os_start = 0 ;
void add_ready_queue(struct tcb *temp_pt)
{
	struct tcb *temp=ready_queue_head;
	if(ready_queue_head==NULL)
	{
	//	context_switch(temp_pt);
		ready_queue_head = temp_pt;
		d_flag = 1;
	}
	else if(temp_pt->priority < running_prio)
	{
		temp_pt->next = ready_queue_head;
		ready_queue_head->prev = temp_pt;
		temp_pt->prev = NULL;
		ready_queue_head=temp_pt;
		d_flag = 1;
	}
	/*else if(ready_queue_head->priority > temp_pt->priority)
	{
		temp_pt->next=ready_queue_head;
		ready_queue_head->prev=temp_pt;
		temp_pt->prev=NULL;
		ready_queue_head=temp_pt;
	}*/
	else
	{
		while((temp->priority < temp_pt->priority) && temp->next!=NULL )
		{
			temp=temp->next;
		}
		if(temp->priority < temp_pt->priority && temp->next==NULL)
		{
			temp_pt->next=NULL;
			temp->next=temp_pt;
			temp_pt->prev=temp;
		}
		else
		{
		   temp->prev->next=temp_pt;
		   temp_pt->next=temp;
		   temp_pt->prev=temp->prev;
		}
		d_flag = 0;
	}
	if(os_start == 1 && d_flag == 0)
	{ 
		ready_queue_head = dispatched;
		if(ready_queue_head->next!=NULL)
		{ready_queue_head ->next ->prev = NULL;
		ready_queue_head ->next = ready_queue_head;
		}
		running_prio = ready_queue_head->priority;
		context_switch();
	}
	
}