#pragma once

// 该文件主要用于函数声明，函数定义在对应文件名.cpp里

static const double PI = 3.14159265358979; //定义Pi值，const

double normcdf(double x); //声明标准正态分布累积分布函数

//被norminv函数调用，属于过渡性质函数，不需要提供给用户。基于Information hiding的原则，可以删除声明。
//double norminv_noncheck(double x);

double norminv(double x, bool checkRange = 1); //声明标准正态分布反累积分布函数

double blackScholesCallPrice(double K, double T, double S_t, double vol, double r); //声明看涨期权定价公式

double blackScholesPutPrice(double K, double T, double S_t, double vol, double r); //声明看跌期权定价公式

double myPrctile(const std::vector<double>& v, double percentage);



