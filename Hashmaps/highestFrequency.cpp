/*You are given an array of integers that contain numbers in random order. 
Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.

Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.

The following line contains N space separated integers, that denote the value of the elements of the array.

Output Format :
The first and only line of output contains most frequent element in the given array.

Constraints:
0 <= N <= 10^8
Time Limit: 1 sec

Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2

Python:
def maxfreq(arr):
    d = {}
    for num in arr:
        if num in d:
            d[num] += 1
        else:
            d[num] = 1
    ans = arr[0]
    for num in arr[0]
        if d[num] > d[ans]:
            ans = num
    return ans
*/

#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;




int highestFrequency(int arr[], int n){
    unordered_map<int, int> freq;
    vector<int> unique_values;

    for (int i = 0; i < n; i++)
    {
        if (freq.count(arr[i]) > 0)
        {   
            freq[arr[i]] = freq[arr[i]]+1;
            continue;
        }
        freq[arr[i]] = 1;
        unique_values.push_back(arr[i]);
    }

    pair<int, int> p;
    p.first = unique_values[0];
    p.second = freq[unique_values[0]];

    for (int i = 1; i < unique_values.size(); i++)
    {
        if (freq[unique_values[i]] > p.second)
        {
            p.first = unique_values[i];
            p.second = freq[unique_values[i]];
        }
    }

    return p.first;
    
    
}

int main(){
    int n = 7;
    
    int arr[] = {2,4,2,3,6,6,6};
    
    cout << highestFrequency(arr, n);
}