#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *start = NULL;

// Insert First
void InsertFirst(int value)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	temp->link=start;
	start=temp;
}

// Insert Last
void InsertLast(int value)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	if(start==NULL)
	{
		temp->link=NULL;
		start=temp;
	}
	else if(start->link==NULL)
	{
		start->link=temp;
		temp->link=NULL;
	}
	else
	{
		struct node *p=start;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
		temp->link=NULL;
	}
}

//Insert Position
void InsertPosition(int value,int pos)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	if(start==NULL)
	{
		if(pos==1)
		{
			temp->link=NULL;
			start=temp;
		}
		else
		{
			printf("%d position not found ",pos);
		}
	}
	else
	{
		struct node *p=start,*q=start->link;
		int i;
		for(i=1;i<=pos-2;i++)
		{
			if(q!=NULL)
			{
				p=p->link;
				q=q->link;
			}
			else
				break;
		}
		if(i<pos-2)
		{
			printf("Position Not Found");
		}
		else
		{
			p->link=temp;
			temp->link=q;
		}
	}
}

// Insert After
void InsertAfter(int value,int AV)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	if(start==NULL)
	{
		printf(" Value not found");
	}
	else
	{
		struct node *p=start,*q=start->link;
		while(q!=NULL)
		{
			if(p->data==AV)
			{
				p->link=temp;
				temp->link=q;
				return;
			}
			else
			{
				p=p->link;
				q=q->link;
			}
		}
		if(p->data==AV)
		{
			p->link=temp;
			temp->link=q;
		}
		else
		{
			printf("Data Not Found");
		}
	}
}

//Insret Before
void InsertBefore(int value,int BV)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	if(start==NULL)
	{
		printf("value not found");
	}
	else
	{
		struct node *p=start,*q=start->link;
		while(q!=NULL)
		{
			if(q->data==BV)
			{
				p->link=temp;
				temp->link=q;
				return;
			}
			else
			{
				p=p->link;
				q=q->link;
			}
		}
		if(start->data==BV)
		{
			temp->link=start;
			start=temp;
		}
		else
		{
			printf("Data not found");
		}
	}
}

//Count
int count()
{
	int c=0;
	if(start==NULL)
	{
		return c;
	}
	else
	{
		struct node *p=start;
		while(p!=NULL)
		{
			p=p->link;
			c++;
		}
		return c;
	}
}

//Searching
int Search(int value)
{
	struct node *p=start;
	int pos=1;
	while(p!=NULL)
	{
		if(p->data==value)
			return pos;
		else
		{
			p=p->link;
			pos++;
		}	
	}
	return -1;
}

//Display
void Display()
{
	struct node *p=start;
	printf("Start ->");
	while(p!=NULL)
	{
		printf(" %d  ->",p->data);
		p=p->link;
	}
	printf(" NULL ");
}

// Delete First
int deleteFirst()
{
	int x;
	struct node *p=start;
	if(start==NULL)
	{
		printf("Linked list is Empty");
		x=-1;
	}
	else
	{
		x=p->data;
		start=p->link;
		p->link=NULL;
		free(p);
	}
	return x;
}

//Delete Last
int deleteLast()
{
	int x;
	struct node *p=start;
	if(start==NULL)
	{
		printf("Linked List Empty ");
		x=-1;
	}
	else if(start->link==NULL)
	{
		x=p->data;
		free(p);
		start=NULL;
	}
	else
	{
		struct node *q=start->link;
		while(q->link!=NULL)
		{
			p=p->link;
			q=q->link;
		}
		x=q->data;
		p->link=NULL;
		free(q);
	}
	return x;
	
}

// Delete Value
void deleteValue(int v)
{
	if(start==NULL)
	{
		printf(" deelete not possible");
	}
	else
	{
		struct node *p=start,*q=start->link;
		if(p->data==v)
		{
			start=q;
			p->link=NULL;
			free(p);
		}
		else
		{
			while(q!=NULL)
			{
				if(q->data==v)
				{
					p->link=q->link;
					q->link=NULL;
					free(q);
					break;
				}
				p=p->link;
				q=q->link;
			}
			if(q==NULL)
			{
				printf(" Data not Found ");
			}
		}
	}
}

// delete Any Position 
int deleteAny(int pos)
{
	struct node *p=start,*q=start->link;
	int x,c;
	if(start==NULL)
	{
		printf("Delete Not Possible");
		x=-1;
	}
	if(start->link==NULL)
	{
		if(pos==1)
		{
			x=p->data;
			free(p);
			start=NULL;
		}
		else
		{
			x=-1;
			printf("Delete Not Possible");
		}
	}
	else
	{
		c=1;
		while(c<=pos-1)
		{
			c++;
			p=p->link;
			q=q->link;
			if(q==NULL)
			{
				printf("Position not found delete not possible ");
				return -1;
			}
		}
		x=q->data;
		p->link=q->link;
		q->link=NULL;
		free(q);
	}
	return x;
}

//Delete Before

int deleteBefore(int BV)
{
	int x=-1;
	if(start==NULL||start->link==NULL|| start->data==BV)
	{
		printf(" Delete Not Possible");
	}
	else
	{
		struct node *p=start,*q=start->link,*r=q->link;
		if(q->data==BV)
		{
			start=q;
			x=p->data;
			p->link=NULL;
			free(p);
		}
		else
		{
			while(r!=NULL)
			{
				if(r->data==BV)
				{
					p->link=q->link;
					x=q->data;
					q->link=NULL;
					free(q);
					break;
				}
				p=p->link;
				q=q->link;
				r=r->link;
			}
			if(r==NULL)
			{
				printf(" Data Not Found ");
			}
		}
	}
	return x;
	
}

// delete After
int deleteAfter(int AV)
{
	int x;
	if(start==NULL||start->link==NULL)
	{
		printf(" Delete Not Possible");
		x=-1;
	}
	else
	{
		struct node *p=start,*q=start->link;
		while(q!=NULL)
		{
			if(p->data==AV)
			{
				p->link=q->link;
				x=q->data;
				q->link=NULL;
				free(q);
				break;
			}
			p=p->link;
			q=q->link;
		}
		if(q==NULL)
		{
			if(p->data==AV)
			{
				printf("Data present at last and Delete not Possible ");
			}
			else
			{
				printf(" Data not found and Delete not possible ");
			}
		}
	}
	return x;
}

//Main Function
int main()
{
	int x,key,pos,AV,BV;
	while(1)
	{
		
		printf("\n1. Insert First 2.Insert Last 3.Insert Position 4.Insert After 5.Insert Before ");
		printf("\n6. Delete First 7.Delete Last 8.Delete Before 9.Delete After 10. Delete value 11. Delete Any");
		printf("\n12. Display 13. Count 14. Search 15. Exit");
		printf("\nEnter Your Choice ");
		scanf("%d",&key);
		switch(key)
		{
			case 1:
				printf("Enter Value :");
				scanf("%d",&x);
				InsertFirst(x);
				break;
			case 2:
				printf("Enter Value :");
				scanf("%d",&x);
				InsertLast(x);
				break;
			case 3:
				printf("Enter Value :");
				scanf("%d",&x);
				printf("Enter Position :");
				scanf("%d",&pos);
				InsertPosition(x,pos);
				break;
			case 4:
				printf("Enter Value :");
				scanf("%d",&x);
				printf("Enter After Value :");
				scanf("%d",&AV);
				InsertAfter(x,AV);
				break;
			case 5:
				printf("Enter Value :");
				scanf("%d",&x);
				printf("Enter Before Value :");
				scanf("%d",&BV);
				InsertBefore(x,BV);
				break;	
			case 6:
				x=deleteFirst();
				if(x==-1)
					printf(" Delete Not Possible ");
				else
					printf("%d value is deleted ",x);	
				break;
			case 7:
				x=deleteLast();
				if(x==-1)
					printf(" Delete Not Possible ");
				else
					printf("%d value is deleted ",x);
				break;
			case 8:
				printf("Enter Before Value");
				scanf("%d",&BV);
				x=deleteBefore(BV);
				if(x==-1)
					printf(" Delete Not Possible ");
				else
					printf("%d value is deleted ",x);
				break;
			case 9:
				printf("Enter After Value");
				scanf("%d",&AV);
				x=deleteAfter(AV);
				if(x==-1)
					printf(" Delete Not Possible ");
				else
					printf("%d value is deleted ",x);
				break;
			case 10:
				printf("Enter Value");
				scanf("%d",&x);
				deleteValue(x);
				break;
			case 11:
				printf("Enter Position");
				scanf("%d",&pos);
				x=deleteAny(pos);
				if(x==-1)
					printf(" Delete Not Possible ");
				else
					printf("%d value is deleted ",x);
				
				break;
			case 12:
				Display();
				break;
			case 13:
				x=count();
				printf("%d number of node present ",x);
				break;
			case 14:
				printf("Enter Searching value :");
				scanf("%d",&x);
				if(Search(x)==-1)
					printf("Value not found");
				else
					printf("Position is %d",Search(x));	
				break;	
			case 15:
				exit(0);
				break;
			default:
				printf("\nInvalid Choice");									
		}
		
	}
	return 0;
}







