/*==================
Your Name: Keira Walker
Your Login ID: 931135148
==================*/

#include <iostream>
#include<fstream>
#include <vector>
#include <iterator>
using namespace std;

void showHeap(vector<int> h)
{
  /*
    vector <int> :: iterator it;
    for(it = h.begin(); it != h.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
  */

    for(int i=1; i < h.size(); ++i)
        cout << '\t' << h[i];
    cout << '\n';

}

void percolateUp(vector<int> &h, int i)
{
  int tmp = h[i];
  while (i > 1 && tmp < h[i / 2])
  {
    h[i] = h[i / 2];
    i = i / 2;
  }
  h[i] = tmp;
}

void percolateDown(vector<int> &h, int i, int n)
{
  int tmp = h[i];
  while (2 * i <= n)
  {
    int child = 2 * i;
    if (child + 1 <= n && h[child + 1] < h[child])
      child++;
    if (h[child] < tmp)
    {
      h[i] = h[child];
      i = child;
    }
    else
      break;
  }
  h[i] = tmp;
}

void insert(vector<int> &h, int x)
{
  h.push_back(x);
  percolateUp(h, h.size() - 1);
}

int deleteMin(vector<int> &h)
{
  int minVal = h[1];
  h[1] = h.back();
  h.pop_back();
  if (h.size() > 1)
    percolateDown(h, 1, h.size() - 1);
  return minVal;
}

void buildHeap1(vector<int> &h1)
{
  int n = h1.size() - 1;
  for (int i = 2; i <= n; i++)
    percolateUp(h1, i);
}

void buildHeap2(vector<int> &h2)
{
  int n = h2.size() - 1;
  for (int i = n / 2; i >= 1; i--)
    percolateDown(h2, i, n);
}


/*====================================================
Compare the running time of both algorithms in a and b
for sorted, reverse-ordered, and random inputs.

buildHeap1: sorted O(n), reverse-ordered O(n log n), random O(n) average.
buildHeap2: O(n) for sorted, reverse-ordered, and random.
====================================================*/


int findKthLargest(vector<int> &h, int k)
{
  int n = h.size() - 1;
  if (k < 1 || k > n)
    return 0;

  // first build a heap with the first k numbers
  vector<int> kh;
  kh.push_back(0);
  for (int i = 1; i <= k; i++)
    kh.push_back(h[i]);
  buildHeap2(kh);

  //compare the new number with the top and
  //decide whether we should insert the new number.
  for (int i = k + 1; i <= n; i++)
  {
    if (h[i] > kh[1])
    {
      deleteMin(kh);
      insert(kh, h[i]);
    }
  }

  return kh[1];
}

void printLessThan(vector<int> &h, int i, int x)
{
  if (i >= (int)h.size() || h[i] >= x)
    return;
  cout << '\t' << h[i];
  printLessThan(h, 2 * i, x);
  printLessThan(h, 2 * i + 1, x);
}

void findAllLessThanX(vector<int> &h, int x)
{
  printLessThan(h, 1, x);
  cout << endl;
}

int main()
{

  ifstream dataFile;
  vector<int> heap, heap1, heap2;
  int num;

  // READING NUMBERS FROM A FILE
  dataFile.open("data.txt");

      heap.push_back(0);
      heap1.push_back(0);
      heap2.push_back(0);

  if (dataFile.is_open())
    while (dataFile>>num)
      {
      heap.push_back(num);
      heap1.push_back(num);
      heap2.push_back(num);
      }
  dataFile.close();

  buildHeap1(heap1);
  showHeap(heap1);

  buildHeap2(heap2);
  showHeap(heap2);

  int k, x;
  cout<<"Please input a number k: ";
  cin>>k;

  cout<<k<<"-th largest number is "<<findKthLargest(heap,k)<<endl;

  cout<<"Please input a number X: ";
  cin>>x;
  findAllLessThanX(heap1, x);

  return 0;

}
