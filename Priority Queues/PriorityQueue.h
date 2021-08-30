#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue() {}

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    //return the size of priorityQueue -- no of elements present
    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0; //pq is empty
        }
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }

            childIndex = parentIndex;
        }
    }

    /*
    int removeMin()
    {
        if (pq.size() == 0)
        {
            return 0;
        }

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int i = 0;
        int left_child_index = 2 * i + 1;
        int right_child_index = 2 * i + 2;

        while (left_child_index <= pq.size() - 1 || right_child_index <= pq.size() - 1)
        {
            if (left_child_index == pq.size() - 1)
            {
                if (pq[i] > pq[left_child_index])
                {
                    int a = pq[i];
                    pq[i] = pq[left_child_index];
                    pq[left_child_index] = a;
                    i = left_child_index;
                }
                else
                {
                    break;
                }
            }
            else if (left_child_index < pq.size() - 1)
            {
                if (pq[left_child_index] < pq[right_child_index])
                {
                    if (pq[i] > pq[left_child_index])
                    {
                        int a = pq[i];
                        pq[i] = pq[left_child_index];
                        pq[left_child_index] = a;
                        i = left_child_index;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (pq[i] > pq[right_child_index])
                    {
                        int a = pq[i];
                        pq[i] = pq[right_child_index];
                        pq[right_child_index] = a;
                        i = right_child_index;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            left_child_index = 2 * i + 1;
            right_child_index = 2 * i + 1;
        }

        return ans;
    }
    */

    int removeMin()
    {
        if (isEmpty())
        {
            return 0; //priority queue is empty
        }

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        //down heapify
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while (leftChildIndex < pq.size())
        {
            int minIndex = parentIndex;
            if (pq[leftChildIndex] < pq[minIndex])
            {
                minIndex = leftChildIndex;
            }

            if (rightChildIndex < pq.size() && pq[rightChildIndex] < pq[minIndex])
            {
                minIndex = rightChildIndex;
            }

            if (minIndex == parentIndex)
            {
                break;
            }

            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }

        return ans;
    }
};

