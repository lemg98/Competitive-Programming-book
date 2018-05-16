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

	string cad1, cad2;
	int t; cin >> t;

	int n,m;

	while(cin >> n >> m){

		cin >> cad1 >> cad2;

		int dp[n+1][m+1];

		for(int i = 0 ; i <= n ; i++){
			for(int j = 0 ; j <= m ; j++){
				
				if(i == 0)
					dp[i][j] = j;
				
				else if(j == 0)
					dp[i][j] = i;

				else if(cad1[i-1] == cad2[j-1])
					dp[i][j] = dp[i-1][j-1];

				else 
					dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
			
			}
		}

		cout << dp[n][m] << endl;
		
	}	
		
return 0;	
}