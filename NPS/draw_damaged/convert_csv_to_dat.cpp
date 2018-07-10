#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>

using namespace std;

/*
 * A class to read data from a csv file.
 */
class CSVReader
{
  std::string fileName;
  std::string delimeter;

 public:
 CSVReader(std::string filename, std::string delm = ",") :
  fileName(filename), delimeter(delm)
  { }

  // Function to fetch data from a CSV File
  std::vector<std::vector<std::string> > getData();
};

/*
 * Parses through csv file line by line and returns the data
 * in vector of vector of strings.
 */
std::vector<std::vector<std::string> > CSVReader::getData()
{
  std::ifstream file(fileName);

  std::vector<std::vector<std::string> > dataList;

  std::string line = "";
  // Iterate through each line and split the content using delimeter
  while (getline(file, line))
    {
      std::vector<std::string> vec;
      boost::algorithm::split(vec, line, boost::is_any_of(delimeter));
      dataList.push_back(vec);
    }
  // Close the File
  file.close();

  return dataList;
}
int main(int argc, char** argv)
//argc : number of arguments as an input(default : 1, when there are N number of arguments, arc = N + 1)
//argv : argument that argc is pointing to.
//https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean
{

  string  output_directory = "../converted/";
  string output_file = argv[1];

  cout<<output_file<<endl;
  // Creating an object of CSVWriter
  CSVReader reader(argv[1]);

  // Get the data from CSV File
  std::vector<std::vector<std::string> > dataList = reader.getData();

  // Print the content of row by row on screen
  // for(std::vector<std::string> vec : dataList)
  //   {
  //     for(std::string data : vec)
  // 	{
  // 	  std::cout<<data << " , ";
  // 	}
  //     std::cout<<std::endl;
  //   }

  ofstream outfile(output_directory + output_file, ios::app);
  for(vector<string> vec : dataList)
    {
      for(string data : vec)
	{
	  outfile<<data<<" ";
	}
      outfile<<endl;
    }
  outfile.close();
  return 0;

}
