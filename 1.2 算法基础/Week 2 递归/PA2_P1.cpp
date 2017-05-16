#include <iostream>
using namespace std;

//http://www.cnblogs.com/drizzlecrj/archive/2008/12/23/1360670.html

int a[30], b[30];

class Fischer{
public:
	Fischer(){
		a[0] = 1; a[1] = 0;
		b[0] = 0; b[1] = 1;
		for (int i = 2; i < 30; i++){
			a[i] = b[i] = -1;
		}
	}

	int Cala(int m){
		if(a[m] == -1){
			a[m] = 2 * Calb(m-1) + Cala(m-2);
		}
		return a[m];
	}

	int Calb(int m){
		if(b[m] == -1){
			b[m] =Cala(m-1) + Calb(m-2);
		}
		return b[m];
	}

	int CalT(int m){
		return Cala(m) + Calb(m);
	}
};

void main(){
	int n;
	cin >> n;
	Fischer ans;
	while(n != -1){
		cout<<ans.CalT(n)<<endl;
		cin>>n;
		if (n == -1) cout<<endl;
	}

	system("pause");
}


