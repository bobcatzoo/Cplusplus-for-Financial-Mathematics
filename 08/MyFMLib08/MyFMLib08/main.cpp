
#include <iostream>
#include "stdafx.h"
#include "geometry.h"
#include "matlib.h"
#include "BlackScholesModel.h"
#include "PieChart.h"
#include "PutOption.h"
#include "LineChart.h"
#include "Polynomial.h"
using namespace std;

int main()
{
    //�ѿ�������
    CartesianPoint c;
    c.x = 10;
    c.y = 20;
    cout << "Coordinates of p (" << c.x << ", " << c.y << ")." << endl;
    c.x *= 2;
    c.y *= 2;
    cout << "Rescaled coordinates of p (" << c.x << ", " << c.y << ")." << endl;
    cout << endl;

    //������ת���ɵѿ�������
    PolarPoint p;
    CartesianPoint cp;
    p.r = 100.0;
    p.theta = PI / 3;
    cp = polarToCartesion(p);
    cout << "polarPoint is (" << p.r << ", " << p.theta << ")." << endl;
    cout << "polarToCartesian is (" << cp.x << ", " << cp.y << ")." << endl;
    cout << endl;

    //Բ�ܳ������
    Circle cc;
    cc.radius = 10;
    double areaCC = 0.0;
    double circumferenceCC = 0.0;
    areaCC = cc.area();
    circumferenceCC = cc.circumference();
    cout << "Area of circle: " << areaCC << ", Circumference is: " << circumferenceCC << "." << endl;
    cout << endl;

    //����CallOption::price
    BlackScholesModel bsm;
    bsm.stockPrice = 110.0;
    bsm.volatility = 0.1;
    bsm.reskFreeRate = 0.03;
    bsm.date = 0.0;
    CallOption call;
    call.strike = 100.0;
    call.maturity = 0.5;
    double callPrice = call.price(bsm);
    cout << "CallOption price: " << callPrice << "." << endl;
    cout << endl;

    //����PieChart��ͼ
    PieChart pc;
    string file("OptionPie.html");
    pc.setTitle("A big option pie!");
    pc.addEntry("Math", 30.0);
    pc.addEntry("Finance", 40.0);
    pc.addEntry("C++", 20.0);
    pc.addEntry("Python", 10.0);
    pc.writeAsHTML(file);

    //Test PutOption pricing Exercises 8.6.1
    PutOption put;
    put.strike = 100.0;
    put.maturity = 0.5;
    double putPrice = put.price(bsm);
    cout << "PutOption price: " << putPrice << "." << endl;
    cout << endl;
    cout << "<Put-Call-Parity = Call Price - Put Price> Testing" << endl;
    double putCallParity = bsm.stockPrice - exp(-bsm.reskFreeRate * call.maturity) * call.strike;
    cout << "<Put-Call-Parity> is: " << putCallParity << endl;
    cout << "<Call Price - Put Price> is: " << callPrice - putPrice << endl;
    cout << endl;

    //Test LineChart Exercises 8.6.2
    LineChart lc;
    string file2("LineChart.html");
    lc.setTitle("Beautiful line");
    lc.addEntry(1.0, 1.0);
    lc.addEntry(2.0, 4.0);
    lc.addEntry(3.0, 9.0);
    lc.addEntry(4.0, 16.0);
    lc.addEntry(5.0, 25.0);
    lc.writeAsHTML(file2);

    //���Ծ��뺯�� Exercises 8.6.3
    CartesianPoint cp1, cp2, cp3;
    cp1.x = 1.0, cp1.y = 1.0;
    cp2.x = 4.0, cp2.y = 5.0;
    double distance = cp1.distanceTo(cp2);
    cout << "The distance between cp1 and cp2 is " << distance << "." << endl;
    cout << endl;

    //�����ܳ����� Exercises 8.6.4
    cp3.x = 4.0, cp3.y = 1.0;
    double perimeter3 = perimeter(cp1, cp2, cp3);
    cout << "The perimeter is " << perimeter3 << "." << endl;
    cout << endl;

    //Point
    Point pp;
    cout << "What is the value of x?" << endl;
    cout << pp.x << endl;
    cout << endl;

    //���Թ��캯��
    CallOption call1(100.0,0.5);
    double callPrice1 = call1.price(bsm);
    cout << "CallOption price1: " << callPrice1 << "." << endl;
    cout << endl;

    //����explicit
    BlackScholesModel bsm1(110);
    bsm1.volatility = 0.1;
    bsm1.reskFreeRate = 0.03;
    bsm1.date = 0.0;
    CallOption call2(100.0, 0.5);
    double callPrice2 = call2.price(bsm1);
    cout << "CallOption price2: " << callPrice2 << "." << endl;
    cout << endl;

    //���Զ���ʽ Exercises 8.8.2
    //Ĭ�Ϲ��캯��
    Polynomial px;
    for (auto val : px.coefficients)
        cout << val << " ";
    cout << endl;

    //����Ϊ������ֵ�Ĺ��캯��
    Polynomial px0(32.0);
    for (auto val : px0.coefficients)
        cout << val << " ";
    cout << endl;
    double eva0 = px0.evaluate(2);
    cout << "Evaluate: " << eva0 << endl;
    
    //����Ϊ<vector>�Ĺ��캯��
    vector<double> coff1{ 1, 2, 3 };
    Polynomial px1(coff1);
    for (auto val : px1.coefficients)
        cout << val << " ";
    cout << endl;
    
    //evaluate��������
    double eva1 = px1.evaluate(2);
    cout << "Evaluate: " << eva1 << endl;

    //add��������
    vector<double> coff2{ 3, 2, 1, 2 };
    Polynomial px2(coff2);
    Polynomial addpx = px1.add(px2);
    for (auto val : addpx.coefficients)
        cout << val << " ";
    cout << endl;

    return 0;
}

