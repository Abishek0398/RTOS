#include "Queues.h"
#include "os.h"
struct tcb *ready_queue_head=NULL;
void add_ready_queue(struct tcb *temp_pt)
{
	struct tcb *temp=ready_queue_head;
	if(temp_pt->priority < current_tcb->priority)
	{
		new_high_tcb=temp_pt;
		context_switch();
	}
	else if(temp==NULL)
	{
		ready_queue_head=temp_pt;
	}
	else if(temp->priority > temp_pt->priority)
	{
		temp_pt->next=temp;
		temp->prev=temp_pt;
		temp_pt->prev=NULL;
		ready_queue_head=temp_pt;
	}
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
	}
}