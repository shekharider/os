#include<stdio.h>
#include<conio.h>
#define max 30

void main(){
    int i, j, n, bt[max], at[max], wt[max], tat[max], temp[max];
    float awt= 0, atat = 0; // Fixed variable names
    //clrscr ();
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the arrival time of the processes: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }
    printf("Enter the burst time of processes: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    temp[0]=0;
    printf("process\tarrivaltime\tbursttime\twaitingtime\tturnaroundtime\n");
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        temp[i+1]=temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i+1, at[i], bt[i], wt[i], tat[i]);
    }
    awt = awt/n;
    atat = atat/n;
    printf("Average waiting time = %f\n",awt);
    printf("Average turn around time = %f",atat);
    getch ();
}
