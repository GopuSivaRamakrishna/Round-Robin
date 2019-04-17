#include<stdio.h>
struct process
{
    int pid,art,brt,priority,rt;
};
void mergesort(struct process pro[],int l,int mid,int r)
{
    int num1=mid-l+1;
    int num2=r-mid;
    struct process a[num1+1],b[num2+1];
    int i,x=0,y=0;
    for(i=0;i<num1;i++)
        a[i]=pro[l+i];
    a[num1].art=1000000000;
    for(i=0;i<num2;i++)
        b[i]=pro[mid+1+i];
    b[num2].art=1000000000;
    for(i=0;i<num1+num2;i++)
        pro[l+i]=a[x].art<=b[y].art?a[x++]:b[y++];
}
void mergesrt(struct process pro[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesrt(pro,l,mid);
        mergesrt(pro,mid+1,r);
        mergesort(pro,l,mid,r);
    }
}
int main()
{
    int n;
    printf("ENTER HOW MANY PROCESS DETAILS U  WOULD LIKE TO ENTER:");
    scanf("%d",&n);
    int i;
    struct process pro[n+1];
    if(n>0)
    {
        printf("\tENTER ALL REQUIREMENTS IN INTEGER ONLY\n");
        printf("PID AT BT priority\n");
        for(i=0;i<n;i++)
        {
            printf(" %d  ",i);
            pro[i].pid=i;
            scanf("%d%d%d",&pro[i].art,&pro[i].brt,&pro[i].priority);
            pro[i].rt=pro[i].brt;
        }
        mergesrt(pro,0,n-1);
        /*for(i=0;i<n;i++)
            printf("%d ",pro[i].at);
        printf("\n");*/
        int time=0,q2n=0;
        struct process que1,que2[n-1];
        int front=-1,rear=-1;
        i=0;
        que1=pro[i];time=pro[i].art;
        //printf("%d\n",queue1.at);
        printf("\n\tGantt chart of queue1 in the form PID(TIME):\n\t");
        while(1)
        {
            //printf("%d %d %d %d %d\n",i,queue1.at,queue1.rt,time,q2n);
            if(i+1<n && pro[i+1].art==time && pro[i+1].priority < que1.priority)
            {
                if(que1.rt>0)
                {
                    if(front==-1 && rear==-1)
                    {   front=0;  }
                    que2[(++rear)%n]=pro[i];q2n++;
                }
                que1=pro[i+1];
                i++;
            }
            else if(i+1<n && pro[i+1].art==time )
            {
                if(front==-1 && rear==-1)
                {   front=0;  }
                que2[(++rear)%n]=pro[i+1];i++;q2n++;
            }
            if(que1.rt>0)
                {
                    printf("P%d(%d) ",que1.pid,time);
                    que1.rt--;
                }
            else if(que1.rt==0)
                que1.priority=1000000000;
            if(i+1==n && que1.rt==0)
                break;
            time++;
        }
        printf("\n\n\tGantt chart for que2 in the form PID(TIME):\n\t");
        /*for(i=0;i<q2n;i++)
            printf("1 %d\n",queue2[i].pid);
            printf("%d\n",q2n);*/
        i=0;
        int tq=4,temp=q2n,tempr=rear;

        front-=1;time+=1;
        while(1)
        {
            front=(front+1)%q2n;
            que2[front].rt-=tq;
            if(que2[front].rt>0)
                {
                    printf("P%d(%d) ",que2[front].pid,time);
                    time+=4;
                    rear=(rear+1)%q2n;
                    que2[rear]=que2[front];
                }
            else
            {
                printf("P%d(%d) ",que2[front].pid,time);
                time=time+4+que2[front].rt;
                temp--;
            }
            if(front==tempr)
                {
                    tempr=temp-1;
                    front=-1;
                    q2n=temp;
                }
            if(q2n==0)
                break;
        }
        printf("\n\n");
    }
    else
        printf("\tTRY NEXT TIME\n");
    return 0;
}
