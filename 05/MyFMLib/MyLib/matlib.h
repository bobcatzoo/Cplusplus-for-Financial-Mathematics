#pragma once

static const double PI = 3.14159265358979; //����Piֵ��const

double normcdf(double x); //������׼��̬�ֲ��ۻ��ֲ�����

//��norminv�������ã����ڹ������ʺ���������Ҫ�ṩ���û�������Information hiding��ԭ�򣬿���ɾ��������
//double norminv_noncheck(double x);

double norminv(double x, bool checkRange = 1); //������׼��̬�ֲ����ۻ��ֲ�����

// ���ļ���Ҫ���ں������������������ڶ�Ӧ�ļ���.cpp��