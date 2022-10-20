class Solution {
public:
   static bool cmp(string &a,string &b){
         if(a+b>b+a) return true;
         else return false;
    }
    string largestNumber(vector<int>& nums) {
        if(count(nums.begin(),nums.end(),0)==nums.size()) return "0";
        vector<string> arr;
        string res;
        for(int i=0;i<nums.size();i++){
            res = to_string(nums[i]);
            arr.push_back(res);
        }
        sort(arr.begin(),arr.end(),cmp);
        string str = "";
	    for(auto i : arr){
	        str += i;
	    }
	    return str;
    }
};
