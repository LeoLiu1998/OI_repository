#Prime1 Solution
####Description
給出兩個正整數 m 和 n，滿⾜ 1 ≤ m ≤ n ≤ 10^9^ 且 n − m ≤ 10^5^，輸出所有滿⾜ m ≤ p ≤ n 的素數 p。

####Solution
首先线筛求出$(1,\sqrt{n})$的所有素数，然后再用这些素数筛一遍区间内的素数。
code:

		memset(ans,false,sizeof(ans));
		int l,r;R(l);R(r);
		if(l==1) l++;
		for(int i=0;i<cnt&&Prime[i]<r;++i)
			for(int j=l/Prime[i];j<=r/Prime[i];++j)
				if(Prime[i]*j>=l&&j!=1) ans[Prime[i]*j-l]=1;