
class Solution {
public:
	bool solve(long long currSum,long long finalSum,vector<long long>&temp,long long i)
	{
		if(currSum == 0)
		{
			return true;
		}
		if(currSum < 0 || currSum < i) return false;

		for(int j=i;j<finalSum;j+=2)
		{
			temp.push_back(j);
			if(solve(currSum-j,finalSum,temp,j+2)) return true;
			temp.pop_back();
		}
		return false;
	}
	vector<long long> maximumEvenSplit(long long finalSum) {
		if(finalSum % 2 != 0) return {};
		if(finalSum == 2 || finalSum == 4) return {finalSum};
		vector<long long>temp;
		if( solve(finalSum,finalSum,temp,2)) return temp;
		return {};
	}
};