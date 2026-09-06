class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftMax=height;
        leftMax[0]=height[0];
        vector<int>rightMax=height;
        rightMax[n-1]=height[n-1];

        for(int i=1; i<n-1; i++){
            if(leftMax[i]<leftMax[i-1]){
                leftMax[i]=leftMax[i-1];
            }
        }

        for(int i=n-2; i>=1; i--){
            if(rightMax[i]<rightMax[i+1]){
                rightMax[i]=rightMax[i+1];
            }
        }

        int water=0;
        for(int i=1; i<n-1; i++){
            int minHeight=min(leftMax[i], rightMax[i]);
            if(minHeight>height[i]){
                water+=(minHeight-height[i]);
            }    
        }

        return water;
    }
};