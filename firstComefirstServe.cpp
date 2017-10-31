#include<iostream>
using namespace std;

struct process
{
    int rt, et, wt, tat, starttime, endtime;
    int pname;
};

int main()
{
    process allProcesses[5];
    float total_tat = 0, total_wt = 0, avg_tat, avg_wt;
    int n;
    cout<<"\nEnter number of processes : ";
    cin>>n;
    for(int i=0; i<n ; i++)
    {
        allProcesses[i].pname = i+1;
        cout<<"\nEnter release time and execution time of process P"<<i+1<<" : ";
        cin>>allProcesses[i].rt;
        cin>>allProcesses[i].et;
    }
    
    allProcesses[0].starttime = allProcesses[0].rt;
    allProcesses[0].endtime = allProcesses[0].starttime + allProcesses[0].et;
    allProcesses[0].wt = 0;
    allProcesses[0].tat = allProcesses[0].endtime - allProcesses[0].rt;
    total_tat += allProcesses[0].tat;
    total_wt += allProcesses[0].wt;

    for(int i=1; i<n ; i++)
    {
        if(allProcesses[i].rt <= allProcesses[i-1].endtime)
        {
            allProcesses[i].starttime = allProcesses[i-1].endtime;
            allProcesses[i].endtime = allProcesses[i].starttime + allProcesses[i].et;
            allProcesses[i].wt = allProcesses[i].starttime - allProcesses[i].rt;
            allProcesses[i].tat = allProcesses[i].endtime - allProcesses[i].rt;
        }
        else
        {
            allProcesses[i].starttime = allProcesses[i].rt;
            allProcesses[i].endtime = allProcesses[i].starttime + allProcesses[i].et;
            allProcesses[i].wt = 0;
            allProcesses[i].tat = allProcesses[i].endtime - allProcesses[i].rt;
        }

        total_tat += allProcesses[i].tat;
        total_wt += allProcesses[i].wt;
    }

    avg_tat = total_tat/(float)n;
    avg_wt = total_wt/(float)n;

    cout << "Processes " << " Execution Time " << " Release Time "
         << " Waiting Time " << " Turn-Around Time "
         << " Completion Time \n";

    for(int i=0; i<n; i++)
    {
        cout << " " <<"P"<< allProcesses[i].pname << "\t\t" << allProcesses[i].et << "\t\t"
             << allProcesses[i].rt << "\t\t" << allProcesses[i].wt << "\t\t "
             << allProcesses[i].tat  <<  "\t\t " << allProcesses[i].endtime << endl;
    }

     cout << "Average waiting time = "
         << avg_wt;
    cout << "\nAverage turn around time = "
         << avg_tat;
}