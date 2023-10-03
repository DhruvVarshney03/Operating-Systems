#include <stdio.h>


void calculateTime(int process[], int n, int arrival[], int burst[])
{
    int exit[n], turn_around[n], waiting_time[n];
    float avg_waiting_time = 0, avg_turn_around_time = 0;
    
    exit[0] = arrival[0] + burst[0];
    for (int i = 1; i < n; i++)
        exit[i] = exit[i - 1] + burst[i];
        

    for (int i = 0; i < n; i++)
    {
        turn_around[i] = exit[i] - arrival[i];
        waiting_time[i] = turn_around[i] - burst[i];
        avg_waiting_time += waiting_time[i];
        avg_turn_around_time += turn_around[i];
    }
   
    avg_waiting_time /= n;
    avg_turn_around_time /= n;
    
    
    printf("\nProcess\t Arrival Time\t Burst Time\t Exit Time\t Turn Around Time\t Waiting Time\n");
    for (int i = 0; i < n; i++)
    printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n", process[i], arrival[i], burst[i], exit[i],
    turn_around[i], waiting_time[i]);
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turn Around Time: %.2f\n", avg_turn_around_time);
}
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int process[n], arrival[n], burst[n];
    printf("Enter the arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        process[i] = i + 1;
        printf("\nEnter the arrival time: ");
        scanf("%d", &arrival[i]);
        printf("\nEnter the burst time: ");
        scanf("%d",&burst[i]);
    
    }

    calculateTime(process, n, arrival, burst);
    return 0;
}