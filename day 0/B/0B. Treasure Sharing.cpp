#include <bits/stdc++.h>

using namespace std;

#define MAXN 200001

int LoVoglio[MAXN];

int main(){
	#ifdef EVAL
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int N,P,Q;
	cin >> N >> P >> Q;
	vector <int> H(N),A(P),B(Q);
	for(int i = 0; i < N; i++){
		cin >> H[i];
	}
	for(int i = 0; i < P; i++){
		cin >> A[i];
		A[i]--;
		LoVoglio[A[i]] = true;
	}
	priority_queue <pair <int,int>> q;
	for(int i = 0; i < Q; i++){
		cin >> B[i];
		B[i]--;
		if(LoVoglio[B[i]]){
			q.push({H[B[i]],B[i]});
		}
	}
	bool ok = true;
	long long int ans = 0;
	while(!q.empty()){
		int index = q.top().second;
		int value = q.top().first;
		q.pop();
		LoVoglio[index] = false;
		if(ok){
			ans += value;
		}
		ok = !ok;
	}
	for(int i = 0; i < P; i++){
		if(LoVoglio[A[i]]){
			ans += H[A[i]];
		}
	}
	cout << ans;
}
