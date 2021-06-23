#include "stdafx.h"
#include "chart.h"
#include "optionChart.h"

static void optionWriteTopBoilerPlateOfLineChart(std::ostream& out)
{
	out << "<html>" << std::endl;
	out << "<head>" << std::endl;
	out << "<script type = \"text/javascript\" src = \"https://www.gstatic.com/charts/loader.js\"></script>" << std::endl;
	out << "<script type=\"text/javascript\">" << std::endl;
	out << "google.charts.load('current', {'packages':['corechart']});" << std::endl;
	out << "google.charts.setOnLoadCallback(drawChart);" << std::endl;
	out << "function drawChart() {" << std::endl;
	out << "var data = google.visualization.arrayToDataTable([" << std::endl;
	out << "['spot price', 'call value against spot price']," << std::endl;
}

static void optionWriteBottomBoilerPlateOfLineChart(std::ostream& out)
{
	out << "var view = new google.visualization.DataView(data);" << std::endl;
	out << "view.setColumns([0, 1, {" << std::endl;
	out << "calc: \"stringify\"," << std::endl;
	out << "sourceColumn: 1," << std::endl;
	out << "type: \"string\"," << std::endl;
	out << "role: \"annotation\"" << std::endl;
	out << "},]);" << std::endl;


	out << "var options = {" << std::endl;
	out << "title: 'Line of call price against spot price'," << std::endl;
	//out << "curveType:'function'," << std::endl;
	//out << "legend:{position:'bottom'}," << std::endl;
	out << "pointSize: 5" << std::endl;
	out << "};" << std::endl;
	out << "var chart = new google.visualization.LineChart(document.getElementById('payout_ratio'));" << std::endl;
	out << "chart.draw(view, options);" << std::endl;
	out << "}" << std::endl;
	out << "</script>" << std::endl;
	out << "</head>" << std::endl;
	out << "<body>" << std::endl;
	out << "<div id=\"payout_ratio\" style=\"width: 1600px; height: 800px; \"></div>" << std::endl;
	out << "</body>" << std::endl;
	out << "</html>" << std::endl;
}


static void optionWriteDataOfLineChart(std::ostream& out, std::vector<double>& spotPrices, std::vector<double>& callValues)
{
	int nLabels = spotPrices.size();
	for (int i = 0; i < nLabels; i++)
	{
		double label = spotPrices[i];
		double value = callValues[i];
		out << "['" << label << "', " << value << "]";
		if (i != nLabels - 1)
			out << ",";
		out << std::endl;
	}
	out << "]);" << std::endl;
}

void optionChart(const std::string& file, std::vector<double>& spotPrices, std::vector<double>& callValues)
{
	std::ofstream out;
	out.open(file.c_str());
	optionWriteTopBoilerPlateOfLineChart(out);
	optionWriteDataOfLineChart(out, spotPrices, callValues);
	optionWriteBottomBoilerPlateOfLineChart(out);
	out.close();
}