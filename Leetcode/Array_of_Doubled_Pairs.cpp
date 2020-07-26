/* 
954.

Given an array of integers A with even length, return true if and only if it is possible to reorder it such that A[2 * i + 1] = 2 * A[2 * i] for every 0 <= i < len(A) / 2.

*/
    bool canReorderDoubled(vector<int>& A) {
        map<int,int>m;
        int count=0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]!=0) m[A[i]]++;             									// take count of 0 separately
            else count++;
        }
        if(count%2==1) return false;
        for(auto &x:m)																								// pair all positives together
        {
            if(x.first<0 || x.second==0) continue;										// skip over paired elements
            if(m[2*x.first] >= m[x.first])
            {
                m[2*x.first]-=m[x.first];															//pair 2*x with x
                x.second=0;
            }
            else return false;
        }
        for(auto &x:m)																							// pair negatives
        {
            if(x.second==0) continue;
            if(m[x.first/2] >=m[x.first] && x.first%2==0)  					// element should be even as now we're dividing by 2
            {
                m[x.first/2]-=m[x.first];
                x.second=0;																			// mark visited elements
            }
            else return false;
        }
        return true;
    }
