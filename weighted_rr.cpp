#include<iostream>
using namespace std;

struct process
{
    int et, wt, tat, endtime, rem_bt, weight;
    int pname;
};

int main()
{
    process allProcesses[5];
    float total_tat = 0, total_wt = 0, avg_tat, avg_wt;
    int n, quantum, time = 0;
    bool done;
    cout<<"\nEnter time quantum : ";
    cin>>quantum;
    cout<<"\nEnter number of processes : ";
    cin>>n;
    for(int i=0; i<n ; i++)
    {
        allProcesses[i].pname = i+1;
        cout<<"\nEnter execution time and weight of process P"<<i+1<<" : ";
        cin>>allProcesses[i].et;
        cin>>allProcesses[i].weight;
        allProcesses[i].rem_bt = allProcesses[i].et;
    }

    while(1)
    {
        done = true;
        for(int x=0; x<n; x++)
        {
            for(int count = 0; count<allProcesses[x].weight; count++)
            {
                if(allProcesses[x].rem_bt > 0)
                {
                    done = false;
                    if(allProcesses[x].rem_bt > quantum)
                    {
                        time = time + quantum;
                        allProcesses[x].rem_bt -= quantum;
                    }
                    else
                    {
                        time = time + allProcesses[x].rem_bt;
                        allProcesses[x].rem_bt = 0;
                        allProcesses[x].endtime = time;
                        allProcesses[x].wt = allProcesses[x].endtime - allProcesses[x].et;
                        allProcesses[x].tat = allProcesses[x].wt + allProcesses[x].et;
                        total_tat += allProcesses[x].tat;
                        total_wt += allProcesses[x].wt;
                    }
                }
                else
                {
                    break;
                }
            }
        }

        if(done)
        {
            break;
        }
    }

    avg_tat = total_tat/(float)n;
    avg_wt = total_wt/(float)n;

    cout << "Processes " << " Execution Time " 
         << " Waiting Time " << " Turn-Around Time "
         << " Completion Time \n";

    for(int i=0; i<n; i++)
    {
        cout << " " <<"P"<< allProcesses[i].pname << "\t\t" << allProcesses[i].et
             << "\t\t" << allProcesses[i].wt << "\t\t "
             << allProcesses[i].tat  <<  "\t\t " << allProcesses[i].endtime << endl;
    }

     cout << "Average waiting time = "
         << avg_wt;
    cout << "\nAverage turn around time = "
         << avg_tat;
}