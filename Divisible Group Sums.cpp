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

	int idx = 1;
	int n,q;

	while(cin >> n >> q){	

		if(n == 0 && q == 0) break;

		cout << "SET " << idx << ":" << endl;

		vector<ll> vec;
		for(int i = 0 ; i < n ; i++){
			ll t; cin >> t;
			vec.push_back(t);
		}

		int d,m;
		for(int i = 0 ; i < q ; i++){
			
			cin >> d >> m;
			vector<ll> val[m];

			for(int i = 0 ; i < m; i++)
				val[i].resize(d,0);
				
			vector<ll> num;	
			for(int i = 0 ; i < n ; i++){
				if(vec[i] >= 0) num.push_back(vec[i]%(ll)d);
				else num.push_back( d-abs(vec[i])%(ll)d); 	
			}

			for(int i = 0 ; i < n ; i++){
				ll t;
				for(int j = m-1 ; j > 0 ; j--){
					if(j > i) continue;
					for(int w = 0 ; w < d ; w++){
					    t = num[i];
						t += (ll)w;
						t %= (ll)d;
						val[j][t] += val[j-1][w];  
					}
				}

				t = num[i];
				t %= (ll)d;
				val[0][t]++;

			}
			cout << "QUERY " << i+1 << ": " << val[m-1][0] << endl;

		}

		idx++;
	}

return 0;   
}