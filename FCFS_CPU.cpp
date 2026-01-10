#include <iostream>
using namespace std;

struct Process{
    int pid;
    int arrival;
    int burst;
    int waiting;
    int turnaround;
    int completion;
};

class ProcessQueue{
    Process arr[100];
    int front,rear;

    public:
        ProcessQueue(){
            front=0;
            rear=-1;
        }

        void enqueue(Process p){
            if(rear==99){
                cout<<"Queue overflow"<<endl;
                return;
            }
            arr[++rear]=p;
        }

        Process dequeue(){
            if(front>rear){
                cout<<"Queue underflow"<<endl;
                Process empty;
                empty.pid=-1;
                return empty;
            }
            return arr[front++];
        }

        bool isEmpty(){
            return front>rear;
        }
};

void printChart(Process gprocess[], int k) {
    cout << "\nCHART:\n\n ";

    
    for (int i=0; i < k; i++) {
        for (int j=0;j<gprocess[i].burst; j++) cout << "--";
        cout << " ";
    }

    cout << "\n|";

   
    for (int i=0; i<k;i++) {
        for (int j = 0; j<gprocess[i].burst-1; j++) cout << " ";
        cout << "P" << gprocess[i].pid;
        for (int j = 0; j < gprocess[i].burst-1; j++) cout << " ";
        cout << "|";
    }

    cout << "\n ";

    // bottom bar
    for (int i=0; i<k;i++) {
        for(int j=0; j<gprocess[i].burst; j++) cout <<"--";
        cout << " ";
    }

    cout << "\n";
}

void FCFS(ProcessQueue q,int n){
    cout<<endl<<"     FCFS SCHEDULING     "<<endl;

    int currentTime=0;
    Process gprocess[100];
    int k=0;

    cout<<"PID\tAT\tBT\tWT\tTAT\tCT\n";

    while(!q.isEmpty()){
        Process cur=q.dequeue();

        if(currentTime<cur.arrival){
            currentTime=cur.arrival;
        }

        cur.completion=currentTime+cur.burst;
        cur.turnaround=cur.completion-cur.arrival;
        cur.waiting=cur.turnaround-cur.burst;

        currentTime+=cur.burst;
        gprocess[k++]=cur;

        cout<<cur.pid<<"\t"<<cur.arrival <<"\t"<<cur.burst<<"\t"
            <<cur.waiting<<"\t"<<cur.turnaround << "\t"
            <<cur.completion <<endl;
    }
    printChart(gprocess,k);
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    ProcessQueue q;
    cout << "\nEnter Arrival Time and Burst Time\n";
    for (int i = 0; i < n; i++) {
        Process p;
        p.pid=i+1;
        cout<<"P"<<i + 1<< " Arrival: ";
        cin>>p.arrival;
        cout<< "P"<<i+1<<" Burst: ";
        cin>>p.burst;
        cout<< "\n";
        q.enqueue(p);
    }

    FCFS(q, n);
    

    return 0;
}