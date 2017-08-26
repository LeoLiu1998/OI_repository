#include <cstring>


#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

struct Line
{
	int L, R;
	int length;
	const bool operator < (const Line & T)const {
		if (L == T.L) return R < T.R;
		return L < T.L;
	}
};

Line L[100100];
Line process[100100];

int main()
{
	int T;
	int n;
	long long m;

	while (std::cin >> n >> m)
	{

		if (n == 0){
			std::cout << m << std::endl;
			continue;
		}
		for (int i = 0; i < n; ++i){
			std::cin >> L[i].L >> L[i].R;
			if (L[i].L > L[i].R){
				std::swap(L[i].L, L[i].R);
			}
			L[i].length = L[i].R - L[i].L + 1;
		}

		std::sort(L, L + n);

		//预处理出线段合并
		int line_num = 0;
		int current_L = L[0].L;
		int current_R = L[0].R;
		for (int i = 1; i < n; ++i)
		{
			if (L[i].L >= current_L && L[i].L <= current_R + 1){
				current_L = std::min(current_L, L[i].L);
				current_R = std::max(current_R, L[i].R);
			}
			else{
				process[line_num].L = current_L;
				process[line_num].R = current_R;
				process[line_num].length = process[line_num].R - process[line_num].L + 1;
				++line_num;
				current_L = L[i].L;
				current_R = L[i].R;
			}
		}

		process[line_num].L = current_L;
		process[line_num].R = current_R;
		process[line_num].length = process[line_num].R - process[line_num].L + 1;
		++line_num;

		if (line_num == 0){
			std::cout << m << std::endl;
			continue;
		}

		std::queue<std::pair<int,int> >  q;//记录方块填充在哪两个区间之间
		long long  residue = m;
		long long  current_ans = process[0].length;
		long long  max_ans = process[0].length;

		for (int i = 1; i < line_num; ++i)
		{
			
			int need = process[i].L - process[i - 1].R - 1;
			//如果剩余的足够拼
			if (residue >= need){
				residue -= (need);
				current_ans += process[i].length + need;
				max_ans = std::max(max_ans, current_ans);
				q.push(std::make_pair(i - 1, i));
			}else if(!q.empty()){

				int add_blob = 0;
				
				while (!q.empty() || add_blob < need)
				{
					std::pair<int, int> blob = q.front(); q.pop();
					add_blob += (process[blob.second].L - process[blob.first].R - 1);//新增的块
					current_ans -= process[blob.first].length;
				}

				if (add_blob >= need){
					residue += add_blob - need;
					current_ans += process[i].length + need;
					max_ans = std::max(max_ans, current_ans);
					q.push(std::make_pair(i - 1, i));
				}
				else{//全部拆完都不够补，那就回收全部的方块
					residue = add_blob;
					current_ans = process[i].length;
					max_ans = std::max(max_ans, current_ans);
				}

			}else{//方块全都没用而且不够填充
				current_ans = process[i].length;
				max_ans = std::max(max_ans, current_ans);
			}
		}
		//扫描完还有剩余
		if (residue > 0){
			max_ans = std::max(max_ans, current_ans + residue);
		}

		std::cout << max_ans << std::endl;

		
	}
	return 0;
}
