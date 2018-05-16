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

typedef set<int>::iterator set_it;

struct pt{

	int x,y;

	pt(int _x, int _y){
		x = _x, y = _y;
	}

};

int main(){

	int n; cin >> n;
	
	while(n--){

		int m,s;

		cin >> m >> s;

		vector<pt> dir;
		for(int i = 0 ; i < m ; i++){
			int a,b; cin >> a >> b;
			dir.push_back(pt(a,b));
		}

		vector<pt> exp;
		exp.push_back(pt(0,0));

		int vis[s+1][s+1];
		for(int i = 0 ; i <= s ; i++)
			fill(vis[i],vis[i] +s +1 , 0);
		vis[0][0] = 1;

		int c = 1; bool ok = false;
		while(!exp.empty() && ok == false){
		
			vector<pt> _exp;

			for(int i = 0 ; i < exp.size() ; i++){

				int _x = exp[i].x , _y = exp[i].y;

				for(int j = 0 ; j < dir.size() ; j++){
						
					int x = _x + dir[j].x , y = _y + dir[j].y;
					if(x <= s && y <= s && vis[x][y] == 0){
						if(x*x + y*y == s*s){
							ok = true; break;
						}
						vis[x][y] = 1;
						_exp.push_back(pt(x,y));
					}
				}
				if(ok) break;
			}
			if(ok) break;
			exp = _exp;
			c++;
		}
		if(ok == false) cout << "not possible";
		else cout << c;
		cout << endl;

	}		
		
return 0;	
}