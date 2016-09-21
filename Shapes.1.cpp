//Programmer: Ethan Chiang
//Programmer ID: 1538719

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include <cstdlib>// atof
#include <cmath>//pow(), sqtr()

//prototypes
vector<string> parseString(string);// get token function
void shapeCal(vector<string>&,ofstream&);// calculation function and output
int checkShape(string);// check if shape valid
double tokenToNum(string);// convert token string into float numbers

int main()
{
  ifstream fin;// intput file object
  ofstream fout;// output
  fin.open("Shapes.input.txt");
  fout.open("Shapes.output.txt");

  string str; // to store a single line of input from file
  vector<string> tokens; // store tokens

  while(!fin.eof())
  {
    getline(fin,str);// get string from file
    tokens = parseString(str);// turn string into tokens
    if(tokens.size() != 0)// ignore empty line
    shapeCal(tokens,fout);
  }

  fout << "EOF";
  fin.close();//close input.txt for input
  fout.close();//close output.txt for output
  return 0;
}

vector<string> parseString(string str)// get tokens function
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}

void shapeCal(vector<string>& tokens,ofstream& fout)
{
  double side,area,perimeter,length,width,radius,height,volume,surface;

  switch(checkShape(tokens[0]))
  {
    case -1://EOF
      break;

    case 0:// invalid shape
      cout << tokens[0] << " invalid object\n";
      break;

    case 1://square
      side = tokens.size() >= 2 ? tokenToNum(tokens[1]) : 0;
      area = side * side;
      perimeter = side * 4;

      fout << "SQUARE side=" << side;// file output
      cout << "SQUARE side=" << side;// console output

      fout.setf(ios::fixed);// fixed turn on
      fout.precision(2);
      cout.setf(ios::fixed);
      cout.precision(2);

      fout << " area=" << area
           << " perimeter=" << perimeter << endl;
      cout << " area=" << area
           << " perimeter=" << perimeter << endl;
      break;

    case 2:// rectangle
      length = tokens.size() >= 2 ? tokenToNum(tokens[1]) : 0;
      width = tokens.size() >= 3 ? tokenToNum(tokens[2]) : 0;
      area = length * width;
      perimeter = (length + width) * 2;

      fout << "RECTANGLE length=" << length << " width=" << width;// file output
      cout << "RECTANGLE length=" << length << " width=" << width;// console output

      fout.setf(ios::fixed);
      fout.precision(2);
      cout.setf(ios::fixed);
      cout.precision(2);

      fout << " area=" << area
           << " perimeter=" << perimeter << endl;
      cout << " area=" << area
           << " perimeter=" << perimeter << endl;
      break;

    case 3:// circle
      radius = tokens.size() >= 2 ? tokenToNum(tokens[1]) : 0;
      area = 3.14159 * pow(radius,2.0);
      perimeter = 2 * radius * 3.14159;

      fout << "CIRCLE radius=" << radius;// file output
      cout << "CIRCLE radius=" << radius;// console output

      fout.setf(ios::fixed);
      fout.precision(2);
      cout.setf(ios::fixed);
      cout.precision(2);

      fout << " area=" << area
           << " perimeter=" << perimeter << endl;
      cout << " area=" << area
           << " perimeter=" << perimeter << endl;
      break;

    case 4:// triangle
      side = tokens.size() >= 2 ? tokenToNum(tokens[1]) : 0;
      area = sqrt(3.0)/4 * pow(side,2.0);
      perimeter = 3 * side;

      fout << "TRIANGLE side=" << side;// file output
      cout << "TRIANGLE side=" << side;// console output

      fout.setf(ios::fixed);
      fout.precision(2);
      cout.setf(ios::fixed);
      cout.precision(2);

      fout << " area=" << area
           << " perimeter=" << perimeter << endl;
      cout << " area=" << area
           << " perimeter=" << perimeter << endl;
      break;

    case 5:// cube
      side = tokens.size() >= 2 ? tokenToNum(tokens[1]) : 0;
      volume = pow(side,3.0);
      surface = pow(side,2.0) * 6;

      fout << "CUBE side=" << side;// file output
      cout << "CUBE side=" << side;// console output

      fout.setf(ios::fixed);
      fout.precision(2);
      cout.setf(ios::fixed);
      cout.precision(2);

      fout << " surface area=" << surface
           << " volume=" << volume << endl;
      cout << " surface area=" << surface
           << " volume=" << volume << endl;
      break;

    case 6:// box
      length = tokens.size() >= 2 ? tokenToNum(tokens[1]) : 0;
      width = tokens.size() >= 3 ? tokenToNum(tokens[2]) : 0;
      height = tokens.size() >= 4 ? tokenToNum(tokens[3]) : 0;
      volume = length * width * height;
      surface = 2 * (length * width + width * height + length * height);

      fout << "BOX length=" << length << " width= " << width// file output
           << " height= " << height;
      cout << "BOX length=" << length << " width= " << width
           << " height= " << height;

      fout.setf(ios::fixed);
      fout.precision(2);
      cout.setf(ios::fixed);
      cout.precision(2);

      fout << " surface area=" << surface
           << " volume=" << volume << endl;
      cout << " surface area=" << surface
           << " volume=" << volume << endl;
      break;

    case 7:// cylinder
      radius = tokens.size() >= 2 ? tokenToNum(tokens[1]) : 0;
      height = tokens.size() >= 3 ? tokenToNum(tokens[2]) : 0;
      surface = 3.14159 * pow(radius,2.0) * 2 + height * 2 * 3.14159 * radius;
      volume = 3.14159 * pow(radius,2.0) * height;

      fout << "CYLINDER radius=" << radius;// file output
      cout << "CYLINDER radius=" << radius;// console output
      fout << " height=" << height;
      cout << " height=" << height;

      fout.setf(ios::fixed);
      fout.precision(2);
      cout.setf(ios::fixed);
      cout.precision(2);

      fout << " surface area=" << surface
           << " volume=" << volume << endl;
      cout << " surface area=" << surface
           << " volume=" << volume << endl;
      break;

    case 8:// prism
      side = tokens.size() >= 2 ? tokenToNum(tokens[1]) : 0;
      height = tokens.size() >= 3 ? tokenToNum(tokens[2]) : 0;
      volume = sqrt(3.0)/4 * pow(side,2.0) * height;
      surface = sqrt(3.0)/4 * pow(side,2.0) * 2 + side * height * 3;

      fout << "PRISM side=" << side;// file output
      cout << "PRISM side=" << side;// console output
      fout << " height=" << height;
      cout << " height=" << height;

      fout.setf(ios::fixed);
      fout.precision(2);
      cout.setf(ios::fixed);
      cout.precision(2);

      fout << " surface area=" << surface
           << " volume=" << volume << endl;
      cout << " surface area=" << surface
           << " volume=" << volume << endl;
      break;
  }

  //reset back to default
  fout.unsetf(ios::fixed);
  fout.precision(6);
  cout.unsetf(ios::fixed);
  cout.precision(6);
}

int checkShape(string shape)// return 0 if not valid
{
  if(shape == "SQUARE")
    return 1;
  else if(shape == "RECTANGLE")
    return 2;
  else if(shape == "CIRCLE")
    return 3;
  else if(shape == "TRIANGLE")
    return 4;
  else if(shape == "CUBE")
    return 5;
  else if(shape == "BOX")
    return 6;
  else if(shape == "CYLINDER")
    return 7;
  else if(shape == "PRISM")
    return 8;
  else if (shape == "EOF")
    return -1;
  else
    return 0;
}

double tokenToNum(string token)// covert to float pt num
{
  return atof(token.c_str());
}