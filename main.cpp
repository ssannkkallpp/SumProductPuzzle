#include <iostream>
#include <cmath>


using namespace std;




int is_prime(int x) {
	if(x<=1) return 0;
	for(int i=2;i<=sqrt(x);i++) {
		if(x%i == 0) {
			return 0;
		}
	}
	return 1;

}

int first_condition(int s) {
	for(int a=2;a<=s/2;a++) {
		if(is_prime(a) && is_prime(s-a)) {
			return 0;
		}
	}		
	return 1;
}

int second_condition(int p, int answer) {
	for(int i=2; i<=sqrt(p); i++) {
		if(p%i == 0) {
			int j = p/i;
			if(!(2<=j && j<=99)) {
				continue;
			}
			if(first_condition(i+j)){
				if(answer) return 0;
				answer = 1;
			}
	
		}
	}

	return answer;
	
}

int third_condition(int s, int answer) {
	if(!first_condition(s)) return 0;
	for(int a=2;a<=s/2;a++) {
		int b = s-a;
		if(second_condition(a*b, 0)) {
			if(answer) return 0;
			
			answer = a;
		}
		
	}
	return answer;

}

	
int main(void) {
	for(int s=5;s<=200;s++) {
		int a = third_condition(s, 0);
		if(a != 0) {
			cout << s << " " << a << " " << s-a << endl; 
		//	break;

		}

	}

	return 0;
}
