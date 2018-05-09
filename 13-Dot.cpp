#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <list>
#include <map>

using namespace std;

typedef long long ll;

int main(){

	int n, m, k;
	while(cin >> m >> n){

		vector<int> vec[2]; //0 is price and 1 is value
		for(int i = 0 ; i < n ; i++){
			int p,v; cin >> p >> v;
			vec[0].push_back(p);
			vec[1].push_back(v);
		}

		k = m;
		k += m > 1800 ? 200 : 0;

		vector<int> dp(k+1,0);
		for(int i = 0 ; i < n ; i++){			
			int price = vec[0][i], val = vec[1][i];
			
			for(int j = k ; j >= price ; j--){
				//if can spend exaclty j
				if(dp[j-price] > 0 || j-price == 0) dp[j] = max(dp[j], dp[j-price] + val);
			}

		}

		int r;
		if(m > 1800 && m < 2001){
			r = *max_element(dp.begin(), dp.begin()+ m + 1);
			r = max(r, *max_element(dp.begin()+2001, dp.end()) );
		}

		else r = *max_element(dp.begin(), dp.end());

		cout << r << endl;
	}

return 0;   
}