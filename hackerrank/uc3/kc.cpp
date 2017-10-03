#include <bits/stdc++.h>

using namespace std;

using namespace std;


string mat[8];
bool visited[8][8];
unordered_map<long long, long long> arr[2];
string target;
int mid;

int count_bit(long long a){
	int res = 0;
	while (a){
		res++;
		a = (a&(a - 1));
	}
	if (res % 2 == 0) return 1;
	else return -1;
}

void dfs(int row, int col, int l,int depth,long long mask,int dir){
	//cout << row << " " << col << " " <<l<<" "<< depth << endl;
	visited[row][col] = true;
	int index = row * 8 + col;
	if (depth != 0){
		mask = mask | (1ll << index);
		//cout << index << endl;
	}
	if (depth == l){
		if (dir == 1){
			for (long long temp = mask; ; temp = ((temp - 1)&mask)){
				if (arr[dir].find(temp) == arr[dir].end()) arr[dir][temp] = 1;
				else arr[dir][temp]++;
				if (temp == 0) break;
			}
		}
		else{
			//__builtin_popcountll()
			//cout << row << " " << col << " " << mask << endl;
			if (arr[dir].find(mask) == arr[dir].end()) arr[dir][mask] = 1;
			else arr[dir][mask]++;
		}
	}
	int mul = 2 * dir - 1;
	//cout << "ok" << endl;
	if (depth < l){
		for (int dr = -1; dr <= 1; dr++){
			if (row + dr < 0 || row + dr >= 8) continue;
			for (int dc = -1; dc <= 1; dc++){
				if (dr == dc&& dc == 0) continue;
				if (col + dc < 0 || col + dc >= 8) continue;
				if (visited[row + dr][col + dc]) continue;
				//cout << mat[row + dr][col + dc] << " " << target[mid + mul*(depth + 1)] <<" "<<mid<< endl;
				if (target[mid + mul*(depth + 1)] != mat[row + dr][col + dc]) continue;
				//cout <<" dr="<<dr << "  dc=" << dc << endl;
				dfs(row + dr, col + dc, l, depth + 1,mask,dir);
			}
		}
	}
	visited[row][col] = false;
}

int main() {

	int l;
	cin >> l;
	cin >> target;
	for (int i = 0; i < 8; i++) cin >>mat[i];
	mid = l / 2;
	long long ans = 0;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (mat[i][j] == target[mid]){
				//cout << i << " new " << j <<" "<<mid<< endl;
				arr[0].clear();
				arr[1].clear();
				dfs(i, j, l - mid - 1, 0,0, 1);
				dfs(i, j, mid, 0, 0,0);
				
				for (unordered_map<long long, long long>::iterator it = arr[0].begin(); it != arr[0].end(); it++){
					long long mask = it->first;
					//cout << mask << endl;
					long long ts = 0;
					for (long long temp = mask; ; temp = ((temp - 1)&mask)){
						if (arr[1].find(temp) != arr[1].end()) ts+=arr[1][temp]*count_bit(temp);
						if (temp == 0) break;
					}
					ans += ts*(it->second);
				}
			
			}
		}
	}
	cout << ans << endl;
	//system("Pause");
	return 0;
}