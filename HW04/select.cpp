#include <iostream>
#include<fstream>
#include <vector>
using namespace std;

//Recursively find k-th smallest number in L
int select( const vector<int> & L, int k)
{
    vector<int> L1, L2;
    //use L[0] instead of asking the oracle a number.
    cout<<"The pivot is "<<L[0]<<endl;
    
    // split L into two list L1 < L[0] <= L2
    int i;
    for (i=1;i<L.size();i++)
    {
        if (L[i] < L[0])
            L1.push_back(L[i]);
        else
            L2.push_back(L[i]);
    }

    // the following can help you to see whether your L1 and L2 are correctly formed
    cout<<"L1: ";
    for (i=0;i<L1.size();i++) cout<<L1[i]<<" ";
    cout<<endl<<"L2: ";
    for (i=0;i<L2.size();i++) cout<<L2[i]<<" ";
    cout<<endl;

    // recursively call select to find k-th smallest number
    if (k <= L1.size())
        return select(L1, k);                    // answer is in L1
    else if (k == L1.size() + 1)
        return L[0];                             // the pivot is the answer
    else
        return select(L2, k - L1.size() - 1);    // answer is in L2
}



int main()
{
  int num;
  ifstream dataFile;
  vector<int> data;

  // READING NUMBERS FROM A FILE
  dataFile.open("data4.txt");

  if (dataFile.is_open()) {
    while (dataFile>>num)
      data.push_back(num);
  }

  dataFile.close();

    for (int i=0; i<data.size(); i++)
      cout<<"Number "<<i<<" is "<< data[i]<<endl;


  int result, k;
  cout<<"Please input k for k-th samllest number in the list: ";
  cin>>k;
  result = select( data,  k);
  cout <<endl << "The k-th smallest number is " <<  result << endl;

  return 0;
}
