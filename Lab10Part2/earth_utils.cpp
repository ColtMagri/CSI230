#include "earth_utils.h"

using namespace std;

int processCSV(ifstream& inFile, string kmlFileName)
{
    string strCountry, strCapital, strLat, strLong;
    string strLine;
    int recordCount = 0;

    ofstream outputKml;
    outputKml.open(kmlFileName, ios_base::app);

    outputKml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    outputKml << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << endl;
    outputKml << "<Document>" << endl;

    if(inFile)
    {
        getline(inFile, strLine);

        while(getline(inFile, strLine))
        {
            //cout << strLine << endl;
            stringstream s_stream(strLine);
            getline(s_stream, strCountry, ',');
            getline(s_stream, strCapital, ',');
            getline(s_stream, strLat, ',');
            getline(s_stream, strLong, ',');
            cout << strCountry << "~" << strCapital << "~" << strLat << "~" << strLong << endl;

            if(outputKml)
            {
                writePlacemark(outputKml, strCapital + ", " + strCountry, strLat, strLong);
            }

            recordCount += 1;
        }
    }

    outputKml << "</Document>" << endl;
    outputKml << "</kml>" << endl;

    outputKml.close();
    return recordCount;
}

void writePlacemark(ofstream& kmlFile, string name, string latitude, string longitude)
{
    kmlFile << "<Placemark>" << endl;
    kmlFile << "<name>" << name << "</name>" << endl;
    kmlFile << "<Point><coordinates>" << longitude << "," << latitude << "</coordinates></Point>" << endl;
    kmlFile << "</Placemark>" << endl;
}