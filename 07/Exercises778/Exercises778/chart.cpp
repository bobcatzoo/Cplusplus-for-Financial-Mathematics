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

static void histWriteTopBoilerPlateOfLineChart(std::ostream& out)
{
	out << "<html>" << std::endl;
	out << "<head>" << std::endl;
	out << "<script type = \"text/javascript\" src = \"https://www.gstatic.com/charts/loader.js\"></script>" << std::endl;
	out << "<script type=\"text/javascript\">" << std::endl;
	out << "google.charts.load('current', {'packages':['line']});" << std::endl;
	out << "google.charts.setOnLoadCallback(drawChart);" << std::endl;
	out << "function drawChart() {" << std::endl;
	out << "var data = new google.visualization.DataTable();" << std::endl;
	out << "data.addColumn('number', 'values');" << std::endl;
	out << "data.addColumn('number', 'counts');" << std::endl;
	out << "data.addRows([" << std::endl;
}

static void histWriteBottomBoilerPlateOfLineChart(std::ostream& out)
{
	out << "var chart = new google.charts.Line(document.getElementById('linechart_material'));" << std::endl;
	out << "chart.draw(data, google.charts.Line.convertOptions(options));" << std::endl;
	out << "}" << std::endl;
	out << "</script>" << std::endl;
	out << "</head>" << std::endl;
	out << "<body>" << std::endl;
	out << "<div id=\"linechart_material\"></div>" << std::endl;
	out << "</body>" << std::endl;
	out << "</html>" << std::endl;
}

static void histWriteDataOfLineChart(std::ostream& out, const std::vector<double>& values, int numberOfBars)
{
	std::vector<double> copy = values;
	std::sort(copy.begin(), copy.end());
	std::vector<double> bars(numberOfBars, 0.0);
	std::vector<int> val = vhist(values, numberOfBars);
	int N = copy.size();
	double begin = copy[0];
	double end = copy[N - 1];
	double delta = (end - begin) / numberOfBars + 0.1;
	for (int i = 0; i < numberOfBars; i++)
		bars[i] = begin + i * delta;
	out << "[" << bars[0] << ", " << 0 << "]," << std::endl;
	for (int i = 0; i < numberOfBars; i++)
	{
		double label = bars[i];
		double value = val[i];
		
		out << "[" << label << ", " << value << "],";
		out << std::endl;
		
		out << "[" << label + delta << ", " << value << "],";
		out << std::endl;
		out << "[" << label + delta << ", " << 0 << "],";
		out << std::endl;
	}
	out << "[" << bars[numberOfBars-1]+delta << ", " << 0 << "]" << std::endl;
	out << "]);" << std::endl;
	out << "var options = {" << std::endl;
	out << "chart: {" << std::endl;
	out << "title: 'Histogram of <vector> values'," << std::endl;
	out << "}," << std::endl;
	out << "width: 900," << std::endl;
	out << "height: 500," << std::endl;
	out << "hAxis: { ticks: [" ;
	for (int i = 0; i < numberOfBars; i++)
		out << bars[i] << ", ";
	out << bars[numberOfBars - 1] + delta;
	out << "] }" << std::endl;
	out << "};" << std::endl;
}



std::map<double, int> mhist(const std::vector<double>& v, int numberOfBars)
{
	std::vector<double> copy = v;
	std::sort(copy.begin(), copy.end());
	std::map<double, int> count;
	int N = copy.size();
	double begin = copy[0];
	double end = copy[N - 1] +0.5;
	std::cout << begin << " " << end << std::endl;
	double delta = (end - begin) / numberOfBars;
	std::cout << delta << std::endl;
	for (auto val : copy)
		std::cout << val << "   ";
	std::cout << std::endl;
	for (int i = 0; i < numberOfBars; i++)
	{
		int valueCount = 0;
		for (int j = 0; j < N; j++)
		{
			if (copy[j] >= begin + i * delta && copy[j] < begin + (i + 1) * delta)
				valueCount++;
		}
		std::cout << "[" << begin + i * delta << " - " << begin + (i + 1) * delta << "): " << valueCount << std::endl;
		count[begin + i * delta] = valueCount;
	}
	return count;
}

std::vector<int> vhist(const std::vector<double>& v, int numberOfBars)
{
	std::vector<double> copy = v;
	std::sort(copy.begin(), copy.end());
	std::vector<int> count;
	int N = copy.size();
	double begin = copy[0];
	double end = copy[N - 1];
	std::cout << begin << " " << end << std::endl;
	double delta = (end - begin) / numberOfBars + 0.1;
	std::cout << delta << std::endl;
	for (auto val : copy)
		std::cout << val << "   ";
	std::cout << std::endl;
	for (int i = 0; i < numberOfBars; i++)
	{
		int valueCount = 0;
		for (int j = 0; j < N; j++)
		{
			if (copy[j] >= begin + i * delta && copy[j] < begin + (i + 1) * delta)
				valueCount++;
		}
		std::cout << "[" << begin + i * delta << " - " << begin + (i + 1) * delta << "): " << valueCount << std::endl;
		count.push_back(valueCount);
	}
	return count;
}

void histLineChart(const std::string& file, const std::vector<double>& values, int numberOfBars)
{
	std::ofstream out;
	out.open(file.c_str());
	histWriteTopBoilerPlateOfLineChart(out);
	histWriteDataOfLineChart(out, values, numberOfBars);
	histWriteBottomBoilerPlateOfLineChart(out);
	out.close();
}
