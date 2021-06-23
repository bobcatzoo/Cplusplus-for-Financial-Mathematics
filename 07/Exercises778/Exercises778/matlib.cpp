#include "stdafx.h" //放在首行，确保matlib里面的函数定义能找到对应库如<vector>，否则报错
#include "matlib.h"

static const double root2Pi = sqrt(2.0 * PI);

static inline double hornerFunction(double x, double a0)
{
    return a0;
}

static inline double hornerFunction(double x, double a0, double a1)
{
    return a0 + x * hornerFunction(x, a1);
}

static inline double hornerFunction(double x, double a0, double a1, double a2)
{
    return a0 + x * hornerFunction(x, a1, a2);
}

static inline double hornerFunction(double x, double a0, double a1, double a2, double a3)
{
    return a0 + x * hornerFunction(x, a1, a2, a3);
}

static inline double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4)
{
    return a0 + x * hornerFunction(x, a1, a2, a3, a4);
}

static inline double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5)
{
    return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5);
}

static inline double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6)
{
    return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5, a6);
}

static inline double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7)
{
    return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5, a6, a7);
}

static inline double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
    return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5, a6, a7, a8);
}

double normcdf(double x)
{
    if (x < 0)
        return 1 - normcdf(-x);
    double k = 1 / (1 + 0.2316419 * x);
    //double poly = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));
    double poly = hornerFunction(k, 0.0, 0.319381530, -0.356563782, 1.781477937, -1.821255978, 1.330274429);
    double approx = 1.0 - 1.0 / root2Pi * exp(-0.5 * x * x) * poly;
    return approx;
}

static const double a0 = 2.50662823884;
static const double a1 = -18.61500062529;
static const double a2 = 41.39119773534;
static const double a3 = -25.44106049637;
static const double b1 = -8.47351093090;
static const double b2 = 23.08336743743;
static const double b3 = -21.06224101826;
static const double b4 = 3.13082909833;
static const double c0 = 0.3374754822726147;
static const double c1 = 0.9761690190917186;
static const double c2 = 0.1607979714918209;
static const double c3 = 0.0276438810333863;
static const double c4 = 0.0038405729373609;
static const double c5 = 0.0003951896511919;
static const double c6 = 0.0000321767881768;
static const double c7 = 0.0000002888167364;
static const double c8 = 0.0000003960315187;

double norminv_noncheck(double x)
{
    double r;
    double s;
    double t;

    double y = x - 0.5;
    if (y <0.42 && y >-0.42)
    {
        r = y * y;
        return y * hornerFunction(r, a0, a1, a2, a3) / hornerFunction(r, 1.0, b1, b2, b3, b4);
    }
    else
    {
        if (y < 0)
            r = x;
        else
            r = 1 - x;
        s = log(-log(r));
        t = hornerFunction(s, c0, c1, c2, c3, c4, c5, c6, c7, c8);
        if (x > 0.5)
            return t;
        else
            return -t;
    }

}

//watch out -> double norminv(double x, bool checkRange = 1) is error!!!
//debug throw redefinition of default argument parameter 1(checkRange)
double norminv(double x, bool checkRange)
{
    if (checkRange && (x < 0 || x > 1.0))
    {
        throw std::logic_error::logic_error("The value is out of range for norminv, which should be between 0 and 1.");
    }
    else
    {
        return norminv_noncheck(x);
    }
}

//S_t: spotPrice
//T: maturity
//K: strikePrice
//vol: volatility
//r: riskFreeInterestRate

double blackScholesCallPrice(double K, double T, double S_t, double vol, double r)
{
    double d1 = pow((vol * sqrt(T)), -1) * (log(S_t / K) + (r + 0.5 * pow(vol, 2)) * sqrt(T));
    double d2 = d1 - vol * sqrt(T);

    double callPrice = normcdf(d1) * S_t - normcdf(d2) * K * exp(-r * T);
    return callPrice;
}

double blackScholesPutPrice(double K, double T, double S_t, double vol, double r)
{
    double d1 = pow((vol * sqrt(T)), -1) * (log(S_t / K) + (r + 0.5 * vol * vol) * sqrt(T));
    double d2 = d1 - vol * sqrt(T);

    double putPrice = normcdf(-d2) * K * exp(-r * T) - normcdf(-d1) * S_t;
    return putPrice;
}

double myPrctile(const std::vector<double>& v, double percentage)
{
    if (percentage < 0.0 || percentage > 100.0)
    {
        throw std::logic_error::logic_error("percentage value should be between 0 and 100.");
    }
    std::vector<double> copy = v;
    std::sort(copy.begin(), copy.end());
    int N = copy.size();
    double correction = 0.0;
    int indexBelow = (int) (percentage * N / 100.0 - 0.5); //<vector>索引从0开始，-0.5确保索引准确
    int indexAbove = indexBelow + 1;

    if (indexAbove > N - 1) //p > 87.5时, 类比下面percentage的if语句
    {
        return copy[N - 1];
    }
    if (indexBelow < 0) //p < 12.5时
    {
        return copy[0];
    }

    double valueBelow = copy[indexBelow]; //插值值域下限值
    double valueAbove = copy[indexAbove]; //插值值域上限值
    //返回分位数p所在分位数区间下限100 * (2 * indexBelow + 1) / 2N, 用于计算插值斜率时的定义域下限值
    double percentageBelow = 100.0 * (indexBelow+0.5) / N;
    //返回分位数p所在分位数区间上限100 * (2 * indexAbove + 1) / 2N, 用于计算插值斜率时的定义域上限值
    double percentageAbove = 100.0 * (indexAbove+0.5) / N;

    if (percentage <= percentageBelow) //12.5% - 87.5%范围内可以进行插值，其余区间不进行插值，直接返回首位端点值
    {
        return valueBelow;
    }
    if (percentage >= percentageAbove)
    {
        return valueAbove;
    }
    correction = (percentage - percentageBelow) * (valueAbove - valueBelow) / (percentageAbove - percentageBelow);
    
    return valueBelow + correction;
}

