class Solution {
public:
    void sortColors(vector<int>& a) 
    {
    int low=0;
    int mid=0;
    int high=a.size()-1;
    while(mid<=high)
    {
        if(a[mid]==0)
        {
            swap(a[mid],a[low]);
            mid++;
            low++;
        }
        else if(a[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(a[high],a[mid]);
            high--;
            
        }
    }
   
    }
};