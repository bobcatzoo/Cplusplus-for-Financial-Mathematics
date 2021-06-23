#include "stdafx.h"
#include "chart.h"

static void writeTopBoilerPlateOfLineChart(std::ostream& out)
{
	out << "<html>" << std::endl;
	out << "<head>" << std::endl;
	out << "<script type = \"text/javascript\" src = \"https://www.gstatic.com/charts/loader.js\"></script>" << std::endl;
	out << "<script type=\"text/javascript\">" << std::endl;
	out << "google.charts.load('current', {'packages':['corechart']});" << std::endl;
	out << "google.charts.setOnLoadCallback(drawChart);" << std::endl;
	out << "function drawChart() {" << std::endl;
	out << "var data = google.visualization.arrayToDataTable([" << std::endl;
	out << "['value of x', 'value of y']," << std::endl;

}

static void writeBottomBoilerPlateOfLineChart(std::ostream& out)
{
	out << "var options = {" << std::endl;
	out << "title: 'Line of y = x^2'," << std::endl;
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

static void writeDataOfLineChart(std::ostream& out, std::vector<double>& labels, std::vector<double>& values)
{
	int nLabels = labels.size();
	for (int i = 0; i < nLabels; i++)
	{
		double label = labels[i];
		double value = values[i];
		out << "['" << label << "', " << value << "]";
		if (i != nLabels - 1)
			out << ",";
		out << std::endl;
	}
	out << "]);" << std::endl;
}

void lineChart(const std::string& file, std::vector<double>& labels, std::vector<double>& values)
{
	std::ofstream out;
	out.open(file.c_str());
	writeTopBoilerPlateOfLineChart(out);
	writeDataOfLineChart(out, labels, values);
	writeBottomBoilerPlateOfLineChart(out);
	out.close();
}
