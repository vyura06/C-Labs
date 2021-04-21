#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string sArray[20] ={
            "0000000000000000000000000000000000000000",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0               00                     0",
            "0               00  00                 0",
            "0           00  00  00              hhh0",
            "0           00  00  00          e   h p0",
            "000000000   00  00  00   000000000000000",
            "000000000   00  00  00   000000000000000",
            "0llllllllllllllllllllllllllllllllllllll0",
            "0llllllllllllllllllllllllllllllllllllll0",
            "0llllllllllllllllllllllllllllllllllllll0",
            "0000000000000000000000000000000000000000",
    } ;
    string line1="12313";
    string *line=&line1;

    ifstream in("C:\\Users\\User\\source\\repos\\Project8\\Project8\\Maps\\LVL2.txt"); // окрываем файл для чтения
    int index=0;
    if (in.is_open())

    {
        while (getline(in, line1))
        {
            sArray[index]=line1;
            index++;
        }

    }
    for(int i=0;i<20;i++){
        cout<<sArray[i]<<endl;
    }
    in.close(); // закрываем файл
    return 0;
}