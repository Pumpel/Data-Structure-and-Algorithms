#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int guess(int n, int* wall_, int* paint_){
	int c, r;
	int count = 0;

	//first count 1st row
	for(c=1; c<n+1; ++c){
		if(paint_[(n+2)+c] == 1) count++;
	}
	//count following rows
	for(r=1; r<n; r++){
		for(c=1; c<n+1; ++c){
			paint_[(r+1)*(n+2)+c] = (wall_[r*(n+2)+c]+paint_[r*(n+2)+c]+
			paint_[(r-1)*(n+2)+c]+ paint_[r*(n+2)+c-1]+paint_[r*(n+2)+c+1]) %2;
		if(paint_[(r+1)*(n+2)+c] == 1) count++;
		}
	}
	//check last row;
	for(c=1; c<n+1; c++){
		if ((paint_[n*(n+2)+c-1] + paint_[n*(n+2)+c] + paint_[n*(n+2)+c+1] +
			paint_[(n-1)*(n+2)+c]) %2 != wall_[n*(n+2)+c] ){
			return -1;
		}
	}
	return count;
}

int enumerate(int n, int* wall_, int* paint_){
	int c, sum = -1;
	int nn = (int)pow(2.0,n);
	
	for ( c=1; c<n+1; c++){
		paint_[n+2+c] = 0;
	}

	if(guess(n, wall_, paint_) != -1){
		sum = guess(n, wall_, paint_);
	}

	while(nn--){
		paint_[(n+2)+1]++;
		c = 1;
		while (paint_[(n+2)+c] > 1) {
			paint_[(n+2)+c] = 0;
			c++;
			paint_[(n+2)+c]++;
		}
		if(guess(n, wall_,paint_) != -1){
			if(sum == -1){
				sum = guess(n, wall_, paint_);
			}
			else if (guess(n, wall_, paint_) < sum){
				sum = guess(n, wall_, paint_);
			}
		}
	}
	return sum;
}

int main() {
	int cases, n;
	cin>>cases;
	while(cases--){
		cin>>n;
		int size = (n+1) * (n+2);
		int *paint = new int[size];
		int *wall = new int[size];
		int r, c;

		for ( r=0; r<n+1; r++ ){
			paint[r*(n+2)+0] = paint[r*(n+2)+n+1] = 0;
		}
		for ( c=1; c<n+1; c++ ){
			paint[c] = 0;
		}
		for(r=1; r<n+1; r++){
			for(c=1; c<n+1; c++){
				char s;
				cin>>s;
				if(s == 'w'){
					wall[r*(n+2)+c] = 1;
				}
				else{
					wall[r*(n+2)+c] = 0;
				}
			}
		}
		/*
		for(r=0; r<n+1; r++){
			for(c=0; c<=n+1; c++){
				cout<<paint[r*(n+2)+c]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		*/
		int result = enumerate(n, wall, paint);
		/*
		for(r=0; r<n+1; r++){
			for(c=0; c<=n+1; c++){
				cout<<paint[r*(n+2)+c]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		*/
		if(result == -1){
			cout<<"inf"<<endl;
		}
		else{ 
			cout<<result<<endl;
		}
	}
	system("pause");
	return 0;
}

