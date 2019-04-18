#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

double det(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33){
	return a11*(a22*a33 - a23*a32) + a12*(a23*a31 - a21*a33) + a13*(a32*a21 - a22*a31);
}

double d(double x1, double y1, double x2, double y2){
	return fabs(x1 - x2) * sqrt(1 + (y1 - y2) / (x1 - x2) * (y1 - y2) / (x1 - x2));
}

int main(){ 
	double x1, x2, x3, y1, y2, y3;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
		double a_sr, b_sr, c_sr;
		a_sr = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		b_sr = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
		c_sr = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
		if(a_sr > c_sr || b_sr > c_sr){
			if(a_sr > b_sr){
				double t = a_sr;
				a_sr = c_sr;
				c_sr = t;
				t = x1;
				x1 = x3;
				x3 = t;
				t = y1;
				y1 = y3;
				y3 = t;
			}else{
				double t = b_sr;
				b_sr = c_sr;
				c_sr = t;
				t = x1;
				x1 = x2;
				x2 = t;
				t = y1;
				y1 = y2;
				y2 = t;
			}
		} 
		double ans_x, ans_y, ans_r;
		if(a_sr + b_sr > c_sr){
			double ans_det = 2 * det(x1,x2,x3,y1,y2,y3,1,1,1);
			ans_x = det(x1*x1 + y1*y1, x2*x2 + y2*y2, x3*x3+y3*y3, y1, y2, y3, 1, 1, 1) / ans_det;
			ans_y = det(x1, x2, x3, x1*x1 + y1*y1, x2*x2 + y2*y2, x3*x3+y3*y3, 1, 1, 1) / ans_det;
			ans_r = d(ans_x, ans_y, x1, y1);
		}else{
			ans_x = (x2 + x3) / 2;
			ans_y = (y2 + y3) / 2;
			ans_r = sqrt(c_sr) / 2;
	 	}
		printf("%.6f %.6f %.6f\n", ans_x, ans_y, ans_r);
	}
}
