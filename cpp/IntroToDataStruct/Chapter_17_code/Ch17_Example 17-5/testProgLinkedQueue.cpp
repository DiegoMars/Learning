//Test Program linked queue 
   
#include <iostream>
#include "linkedQueue.h"

using namespace std; 

int main()
{
    linkedQueueType<int> queue;
    int x, y;
     
    queue.initializeQueue(); 
    x = 20;
    y = 35;
    queue.addQueue(x);
    queue.addQueue(y);
    x = queue.front();
    queue.deleteQueue();
    queue.addQueue(x + 7);
    queue.addQueue(78);
    queue.addQueue(x);
    queue.addQueue(y - 6);

    cout << "Queue Elements: ";

    while (!queue.isEmptyQueue())
    {
        cout << queue.front() << " ";
        queue.deleteQueue();
    }

    cout << endl;
     
    return 0;
}