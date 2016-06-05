/*---------------------------------------------------
�񕪖@�ɂ�������	sin(x^2)=0.5	�̉��̂�
��0<x<5�͈̔͂ɂ�����̂������I�ɒT������v���O�������쐬����B
�������v���O�����ōŏ��ɗ^��������͉��͈݂̔͂̂Ƃ��A
���̐��͂W�ȉ��Ƃ킩���Ă�����̂Ƃ���B
�܂��A���̋��e�덷��10^-8�Ax�͂̒P�ʂ�[rad]

2014/07/18	4I31	�����J�l
---------------------------------------------------*/
#include <stdio.h>
#include <math.h>

#define k 8//���̐�

double f(double x){
	return sin(x*x) - 0.5;
}

int main(void) {
	double a = 0.0, b = 5.0, c = 0.0, e = pow(10.0, -8.0), s;
	double ans[k];

	printf("�ۑ�4B:2���@	:\n");
	printf("sin(x^2)=0.5	(0<x<5)�̉��������I�ɒT������v���O����\n\n���\�[�g\n");
	for (int i = 0; i < k; i++)
	{
		//�O��������D
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
			//printf("output:%lf\n", b - a);������
		} while (b - a > e);
		ans[i] = (a + b) / 2;
		//�����̉��ɑΉ������D
		if (i < 3)//�������傫������
		{
			a = ans[i];
			b = 5.0;
		}
		else if (i == 3)//������菬���������p�Ƀ��Z�b�g
		{
			a = 0.0;
			b = ans[0];
		}
		else if (i == 4 || i == 6)//��O����
		{
			a = ans[i];
			b = ans[0];
		}
		else//��ʏ���
		{
			a = 0.0;
			b = ans[i];
		}
		//���\�[�g�ŉ����o��
		printf("ans%d:%lf\n", i, ans[i]);
	}
	//�\�[�g
	for (int i = 0; i < k; i++){
		for (int j = i + 1; j < k; j++){
			if (ans[i] > ans[j]){
				s = ans[i];
				ans[i] = ans[j];
				ans[j] = s;
			}
		}
	}
	printf("\n�\�[�g�������̂�\��\n");
	for (int i = 0; i < k; i++)
	{
		printf("ans%d	:%lf\n", i, ans[i]);
	}
	return 0;
}