/*
   Exercise 1.1
   Selection of integers with k = N/2 
     select1 => sorting and selecting
	 select2 => keeping top k 
*/

#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;



void sort(vector<int> & vec)
{ // bubble sort ascending
  bool sorted = false;
  while (!sorted)
  {
	sorted = true;
	for (auto i = 1; i < vec.size(); i++)
	{
	  if (vec[i-1]> vec[i])
	  {
        swap(vec[i],vec[i-1]);
		sorted = false;
	  }
	}
  }
}

void sortDec(vector<int> & vec)
{ // bubble sort descending
  bool sorted = false;
  while (!sorted)
  {
	sorted = true;
	for (auto i = 1; i < vec.size(); i++)
	{
	  if (vec[i-1]< vec[i])
	  {
        swap(vec[i],vec[i-1]);
		sorted = false;
	  }
	}
  }
}

int  select1(vector<int>  nums)
{
  int k = (nums.size()+1)/2;
  sort(nums);
  return nums[k];
}


int  select2(const vector<int> &nums)
{
	int k = nums.size()/2;
	vector<int> topK(nums.begin(), nums.begin() + k);
	 
	sortDec(topK);
	for (auto i = k; i < nums.size(); i++)
	{
		if (nums[i] > topK[k-1])
		{
			for (auto j = k-2; j >=0 ; j--)
				if (nums[i] < topK[j])
				{topK[j+1] = nums[i]; break;}
				else
					topK[j+1] = topK[j];
			if (topK[0] < nums[i])
				topK[0] = nums[i];
		}
	}
	return topK[k-1];
}

int main()
{
  vector<int> nums;
  int selected;
  time_t start, end;

  srand(time(NULL));
  for (auto numInts = 1000; numInts<=10000; numInts+=1000)
	  // sizes 1,000, 2,000, 3,000, ...10,000
  {
	nums.resize(numInts);
    
     start = time(NULL);
     for (auto i = 0; i < 10; i++) // run 10 times
	 {
	  for (auto j = 0; j < numInts; j++)
		  nums[j] = rand()%(2*numInts);
	  selected = select1(nums); // or selected = select2(nums);
	 }
     end = time(NULL);
	 cout<<numInts<<"\t"<<difftime(end,start)<<endl;
  }
  return 0;
}

