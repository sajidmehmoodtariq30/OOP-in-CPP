#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class FileHandler
{
private:
    fstream file;
    string fileName;

public:
    FileHandler(const string &fName) : fileName(fName)
    {
        file.open(fileName, ios::in | ios::out | ios::app);
        if (!file.is_open())
        {
            cout << "Failed to open the file: " << fileName << endl;
        }
        else
        {
            cout << "File opened successfully: " << fileName << endl;
        }
    }

    ~FileHandler()
    {
        if (file.is_open())
        {
            file.close();
            cout << "File closed: " << fileName << endl;
        }
    }

    void writeToFile(const string &data)
    {
        if (file.is_open())
        {
            file << data << endl;
            cout << "Data written to file: " << data << endl;
        }
        else
        {
            cout << "File is not open for writing." << endl;
        }
    }

    void readFromFile()
    {
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                cout << line << endl;
            }
            // Clear EOF flag to allow further operations on the file
            file.clear();
            // Move the file pointer back to the beginning of the file
            file.seekg(0, ios::beg);
        }
        else
        {
            cerr << "File is not open for reading." << endl;
        }
    }
};



int main()
{
    FileHandler fh("example.txt");
    fh.writeToFile("Hello, World!");
    fh.readFromFile();
    return 0;
}