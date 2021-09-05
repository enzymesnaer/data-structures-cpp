/*
You have been given two integer arrays/lists (ARR1 and ARR2) of size N and M, respectively. 

You need to print their intersection; 
An intersection for this problem can be defined when both the arrays/lists contain a particular value 
or to put it in other words, when there is a common value that exists in both the arrays/lists.


Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in the order they appear in the first "sorted" array/list (ARR1).

The first line of input contains an integer 'N' representing the size of the first array/list.

The second line contains 'N' single space separated integers representing the elements of the first the array/list.

The third line contains an integer 'M' representing the size of the second array/list.

The fourth line contains 'M' single space separated integers representing the elements of the second array/list.

Print the intersection elements. Each element is printed in a separate line.


Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 

Sample Output 1 :
2
3 
4

def freqMap(arr):
    d = {}
    for num in arr:
        d[num] += 1
    else:
        d[num] = 1
    return d

def printIntersection(arr1, n1, arr2, n2):
    d1 = freqMap(arr1)
    for i in range(n2):
        if arr2[i] in d1:
            print(arr2[i])

            if d1[arr2[i]] > 1:
                d1[arr2[i]] -= 1
            else:
                d1.pop(arr2[i])
*/


#include <iostream>
using namespace std;
#include <unordered_map>>
#include <queue>




void printIntersection(int arr1[], int arr2[], int n, int m){
    unordered_map<int, int> intersection;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        if (intersection[arr1[i]]>0)
        {
            intersection[arr1[i]] = intersection[arr1[i]]+1;
            continue;
        }
        intersection[arr1[i]] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        if(intersection[arr2[i]]>0)
        {
            pq.push(arr2[i]);
            intersection[arr2[i]] = intersection[arr2[i]]-1;
        }
    }

    while (pq.size() != 0)
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}




int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}
