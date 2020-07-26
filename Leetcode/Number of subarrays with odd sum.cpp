    /*
       1524
       Find number of subarrays with odd sum modulo 1e9+7
    */
    int numOfSubarrays(vector<int>& arr) {
        map<int,int>m;
        long long int sum=0;
        long long int ans=0;
        long long int even=1;
        long long int odd=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum%2==0)
            {
                ans+=odd;
                even++;
            }
            else 
            {
                ans+=even;
                odd++;
            }
        }
        return ans%1000000007;
    }
