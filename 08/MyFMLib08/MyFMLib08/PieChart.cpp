//#include "stdafx.h"
#include "PieChart.h"

void PieChart::setTitle(const std::string& t)
{
    title = t;
}

void PieChart::addEntry(const std::string& label, double value)
{
    labels.push_back(label);
    values.push_back(value);
}
void PieChart::writeAsHTML(std::ostream& out) const
{
    writeTopBoilerPlateOfPieChart(out, title);
    writeDataOfPieChart(out, labels, values);
    writeBottomBoilerPlateOfPieChart(out, title);
}
void PieChart::writeAsHTML(std::string& file) const
{
    std::ofstream out;
    out.open(file.c_str());
    writeAsHTML(out);
    out.close();
}

static void writeTopBoilerPlateOfPieChart(std::ostream& out, const std::string& title)
{
    out << ("<html>") << std::endl;
    out << ("<head>") << std::endl;
    out << ("<title>") << title << ("</title>") << std::endl; //ä¯ÀÀÆ÷±êÇ©ÏÔÊ¾title
    out << ("<script type = \"text/javascript\" src = \"https://www.gstatic.com/charts/loader.js\"></script>") << std::endl;
    out << ("<script type=\"text/javascript\">") << std::endl;
    out << ("google.charts.load('current', {'packages':['corechart']});") << std::endl;
    out << ("google.setOnLoadCallback(drawChart);") << std::endl;
    out << ("function drawChart() {") << std::endl;
    out << ("var data = new google.visualization.DataTable();") << std::endl;
    out << ("data.addColumn('string', 'Label');") << std::endl;
    out << ("data.addColumn('number', 'Value');") << std::endl;
}

static void writeDataOfPieChart(std::ostream& out, const std::vector<std::string>& labels, const std::vector<double>& values)
{
    out << "data.addRows([" << std::endl;
    int nLabels = labels.size();
    for (int i = 0; i < nLabels; i++)
    {
        std::string label = labels[i];
        double value = values[i];
        out << "['" << label << "', " << value << "]";
        if (i != nLabels - 1)
        {
            out << ",";
        }
        out << std::endl;
    }
    out << "]);" << std::endl;
}

static void writeBottomBoilerPlateOfPieChart(std::ostream& out, std::string title)
{
    out << "var options = {'title':'" << title << "'," << std::endl;
    out << "'width':400," << std::endl;
    out << "'height':300" << std::endl;
    out << "};" << std::endl;
    out << "var chart = new google.visualization.PieChart(document.getElementById('chart_div'));" << std::endl;
    out << "chart.draw(data, options);" << std::endl;
    out << "}" << std::endl;
    out << "</script>" << std::endl;
    out << "</head>" << std::endl;
    out << "<body>" << std::endl;
    out << "<div id='chart_div'>" << std::endl;
    out << "</body>" << std::endl;
    out << "</html>";
}