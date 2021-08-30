#include <vector>
class PriorityQueue
{
    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getMax()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }
    int getSize()
    {
        return pq.size();
    }
    void insert(int element)
    {
        pq.push_back(element);
        int childindex = pq.size() - 1;
        while (childindex > 0)
        {
            int parentindex = (childindex - 1) / 2;
            if (pq[parentindex] < pq[childindex])
            {
                int temp = pq[parentindex];
                pq[parentindex] = pq[childindex];
                pq[childindex] = temp;
            }
            else
            {
                break;
            }
            childindex = parentindex;
        }
    }
    int removeMax()
    {
        if (isEmpty())
        {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentindex = 0;
        int leftchildindex = 2 * parentindex + 1;
        int rightchildindex = 2 * parentindex + 2;
        while (leftchildindex < pq.size())
        {
            int maxNode = parentindex;
            if (pq[leftchildindex] > pq[maxNode])
            {
                maxNode = leftchildindex;
            }
            if (rightchildindex < pq.size() && pq[rightchildindex] > pq[maxNode])
            {
                maxNode = rightchildindex;
            }
            if (maxNode == parentindex)
            {
                break;
            }
            int temp = pq[maxNode];
            pq[maxNode] = pq[parentindex];
            pq[parentindex] = temp;

            parentindex = maxNode;
            leftchildindex = 2 * parentindex + 1;
            rightchildindex = 2 * parentindex + 2;
        }
        return ans;
    }
};