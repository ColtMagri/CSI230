#include "logger.h"

using namespace std;

bool log(string msg, string programName, ofstream& logFile)
{
    string strTime;

    time_t logTime = time(0);
    strTime = ctime(&logTime);

    int timeSize = strTime.size();
    if(timeSize)
    {
        strTime[timeSize - 1] = ' ';
    }

    passwd *pws;
    pws = getpwuid(geteuid());

    string strProgramName = programName;
    pid_t pid = getpid();
    char hostname[1024];
    hostname[1023] = '\0';
    gethostname(hostname, 1023);
    string strHostName = hostname;
    if(logFile)
    {
        logFile << strTime << strHostName << " " << strProgramName << "[" << pid << "]: " << msg << endl;
        return true;
    }
    else
    {
        return false;
    }
    
}