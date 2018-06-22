#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	int temp;
	while(b != 0){
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

class ExtendedEuclidean{
	public:
		int a, b, x, y, gcd;
		int a_coeff, b_coeff;
		ExtendedEuclidean(int a, int b){
			this->a = a;
			this->b = b;
			set_extended_euclidean(a, b);
		}
		
		void set_extended_euclidean(int a, int b){
			int r_prev = a; int r = b;
			int s_prev = 1; int s = 0;
			int t_prev = 0; int t = 1;
			int q = 0, temp = 0;
			while(r != 0){
				q = r_prev / r;
		
				temp = r;
				r = r_prev - q * r; 
				r_prev = temp;

				temp = s;
				s = s_prev - q * s;
				s_prev = temp;

				temp = t;
				t = t_prev - q * t;
				t_prev = temp;
			}
			this->a_coeff = s_prev;
			this->x = s_prev;
			this->b_coeff = t_prev;
			this->y = t_prev;
			this->gcd = r_prev;
		}

		void set(int a, int b){
			set_extended_euclidean(a, b);
		}		
};



int main(int argc, char const *argv[])
{
	int a = 21, b = 27;
	ExtendedEuclidean e(a, b);
	while(true){
		cin >> a >> b;
		e.set(a, b);
		cout << "ax + by = GCD(a, b)\t|\twhere a = " << a << " and b = " << b;
		cout << "\nx: " << e.x << "\ny: " << e.y << "\nGCD: " << e.gcd << "\n-------------------------------------------------\n";
		assert(a * e.x + b * e.y == e.gcd);
	}
	return 0;
}