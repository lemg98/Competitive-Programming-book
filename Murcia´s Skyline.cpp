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


int main(){

	int c; cin >> c;
	int idx = 1;

	while(c--){	

		int n;
		cin >> n;

		vector<int> vec[2];
		for(int i = 0 ; i < n ; i++){
			int t; cin >> t;
			vec[0].push_back(t);
		}
		for(int i = 0 ; i < n ; i++){
			int t; cin >> t;
			vec[1].push_back(t);
		}

		vector<int> dp[2];
		dp[0].push_back(vec[1][0]);
		dp[1].push_back(vec[1][0]);		

		for(int i = 1 ; i < n ; i++){
			dp[0].push_back(0);
			dp[1].push_back(0);	
			for(int j = i-1 ; j >= 0 ; j--){
				if(vec[0][j] < vec[0][i])
					dp[0][i] = max(dp[0][i], dp[0][j]);
				else if(vec[0][j] > vec[0][i])
					dp[1][i] = max(dp[1][i], dp[1][j]);
			}
			dp[0][i] += vec[1][i];
			dp[1][i] += vec[1][i];
		}

		int may_a, may_b;
		may_a = may_b = 0;
		for(int i = 0 ; i < n ; i++){
			may_a = max(may_a, dp[0][i]);
			may_b = max(may_b, dp[1][i]);
		}

		cout << "Case " << idx << ". ";
		if(may_a >= may_b)
			cout << "Increasing (" << may_a << "). " << "Decreasing (" << may_b <<").";
		else
			cout << "Decreasing (" << may_b <<"). "<< "Increasing (" << may_a <<").";
		cout << endl;
		idx++;
	}

return 0;   
}