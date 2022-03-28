#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
#include<algorithm>
static bool NewSort(std::pair<int,int> pair1,std::pair<int,int> pair2)
{
     return pair1.first<=pair2.first;
}
int sum_intervals(std::vector<std::pair<int,int>> intervals)
{
      std::sort(intervals.begin(),intervals.end(),NewSort);
      int result=0;
      for(int i=0;i<intervals.size();i++)
      {
	    if(i+1<intervals.size())
	    {
		if(intervals[i].second>=intervals[i+1].first)
		{
			intervals[i+1].second=std::max(intervals[i].second,intervals[i+1].second);
			intervals[i+1].first=std::min(intervals[i].first,intervals[i+1].first);

		}
		else result+=intervals[i].second-intervals[i].first;
	    }
	    else result+=intervals[i].second-intervals[i].first;
      }
      return result;
}
int main()
{
   std::vector<std::pair<int,int>> intervals={{1,4},{7,10},{3,5}};
   std::cout<<sum_intervals(intervals)<<std::endl;
   return 0;
}

