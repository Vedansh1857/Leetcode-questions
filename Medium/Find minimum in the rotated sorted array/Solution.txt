class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int mid = (i+j)/2;
            if(a[mid] > a[j]) i = mid+1; // We will search in the right half.we will.
            else if(a[mid] < a[j]) j = mid; // We will search in the left half.
            else return a[j]; // When there is only one element in the array.
        }
        return a[j]; // When start pointer becomes equal to the end pointer.
    }
};
