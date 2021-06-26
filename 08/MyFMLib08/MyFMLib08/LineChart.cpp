
#include "LineChart.h"

void LineChart::setTitle(const std::string& t)
{
    title = t;
}

void LineChart::addEntry(double xvalue, double yvalue)
{
    xvalues.push_back(xvalue);
    yvalues.push_back(yvalue);
}
void LineChart::writeAsHTML(std::ostream& out) const
{
    writeTopBoilerPlateOfPieChart(out, title);
    writeDataOfPieChart(out, xvalues, yvalues);
    writeBottomBoilerPlateOfPieChart(out, title);
}
void LineChart::writeAsHTML(std::string& file) const
{
    std::ofstream out;
    out.open(file.c_str());
    writeAsHTML(out);
    out.close();
}

static void writeTopBoilerPlateOfPieChart(std::ostream& out, const std::string& title)
{
    out << "<html>" << std::endl;
    out << "<head>" << std::endl;
    out << ("<title>") << title << ("</title>") << std::endl; //ä¯ÀÀÆ÷±êÇ©ÏÔÊ¾title
    out << "<script type = \"text/javascript\" src = \"https://www.gstatic.com/charts/loader.js\"></script>" << std::endl;
    out << "<script type=\"text/javascript\">" << std::endl;
    out << "google.charts.load('current', {'packages':['corechart']});" << std::endl;
    out << "google.charts.setOnLoadCallback(drawChart);" << std::endl;
    out << "function drawChart() {" << std::endl;
    out << "var data = google.visualization.arrayToDataTable([" << std::endl;
    out << "['xvalues', 'yvalue']," << std::endl;
}

static void writeDataOfPieChart(std::ostream& out, const std::vector<double>& xvalues, const std::vector<double>& yvalues)
{
    int index = xvalues.size();
    for (int i = 0; i < index; i++)
    {
        double xvalue = xvalues[i];
        double yvalue = yvalues[i];
        out << "['" << xvalue << "', " << yvalue << "]";
        if (i != index - 1)
            out << ",";
        out << std::endl;
    }
    out << "]);" << std::endl;
}

static void writeBottomBoilerPlateOfPieChart(std::ostream& out, std::string title)
{
    out << "var options = {'title':'" << title << "'," << std::endl;
    out << "curveType:'function'," << std::endl;
    out << "legend:{position:'bottom'}" << std::endl;
    out << "};" << std::endl;
    out << "var chart = new google.visualization.LineChart(document.getElementById('curve_chart'));" << std::endl;
    out << "chart.draw(data, options);" << std::endl;
    out << "}" << std::endl;
    out << "</script>" << std::endl;
    out << "</head>" << std::endl;
    out << "<body>" << std::endl;
    out << "<div id=\"curve_chart\" style=\"width: 900px; height: 500px; \"></div>" << std::endl;
    out << "</body>" << std::endl;
    out << "</html>" << std::endl;
}