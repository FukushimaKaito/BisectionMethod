/*---------------------------------------------------
二分法により方程式	sin(x^2)=0.5	の解のう
ち0<x<5の範囲にあるものを自動的に探索するプログラムを作成せよ。
ただしプログラムで最初に与えられる情報は解の範囲のみとし、
解の数は８個以下とわかっているものとする。
また、解の許容誤差は10^-8、xはの単位は[rad]

2014/07/18	4I31	福嶋開人
---------------------------------------------------*/
#include <stdio.h>
#include <math.h>

#define k 8//解の数

double f(double x){
	return sin(x*x) - 0.5;
}

int main(void) {
	double a = 0.0, b = 5.0, c = 0.0, e = pow(10.0, -8.0), s;
	double ans[k];

	printf("課題4B:2分法	:\n");
	printf("sin(x^2)=0.5	(0<x<5)の解を自動的に探索するプログラム\n\n未ソート\n");
	for (int i = 0; i < k; i++)
	{
		//前回作ったやつ．
		do{
			c = (a + b) / 2;
			if (f(c) == 0) {
				printf("ans:%lf\n", c);
				return (0);
			}
			else {
				if (f(a)*f(c) < 0) {
					b = c;
				}
				else {
					a = c;
				}
			}
			//printf("output:%lf\n", b - a);うざい
		} while (b - a > e);
		ans[i] = (a + b) / 2;
		//複数個の解に対応した．
		if (i < 3)//半分より大きい部分
		{
			a = ans[i];
			b = 5.0;
		}
		else if (i == 3)//半分より小さい部分用にリセット
		{
			a = 0.0;
			b = ans[0];
		}
		else if (i == 4 || i == 6)//例外処理
		{
			a = ans[i];
			b = ans[0];
		}
		else//一般処理
		{
			a = 0.0;
			b = ans[i];
		}
		//未ソートで解を出力
		printf("ans%d:%lf\n", i, ans[i]);
	}
	//ソート
	for (int i = 0; i < k; i++){
		for (int j = i + 1; j < k; j++){
			if (ans[i] > ans[j]){
				s = ans[i];
				ans[i] = ans[j];
				ans[j] = s;
			}
		}
	}
	printf("\nソートしたものを表示\n");
	for (int i = 0; i < k; i++)
	{
		printf("ans%d	:%lf\n", i, ans[i]);
	}
	return 0;
}
