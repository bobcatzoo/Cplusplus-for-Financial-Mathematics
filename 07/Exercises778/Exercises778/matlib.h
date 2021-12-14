#pragma once

// ���ļ���Ҫ���ں������������������ڶ�Ӧ�ļ���.cpp��

static const double PI = 3.14159265358979; //����Piֵ��const

double normcdf(double x); //������׼��̬�ֲ��ۻ��ֲ�����

//��norminv�������ã����ڹ������ʺ���������Ҫ�ṩ���û�������Information hiding��ԭ�򣬿���ɾ��������
//double norminv_noncheck(double x);

double norminv(double x, bool checkRange = 1); //������׼��̬�ֲ����ۻ��ֲ�����

double blackScholesCallPrice(double K, double T, double S_t, double vol, double r); //����������Ȩ���۹�ʽ

double blackScholesPutPrice(double K, double T, double S_t, double vol, double r); //����������Ȩ���۹�ʽ

double myPrctile(const std::vector<double>& v, double percentage);



