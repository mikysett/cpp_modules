#include <iostream>
#include <fstream>
#include <string>

bool correctInput(int argc, char **argv);
bool replace(const std::string& inFileStr,
	const std::string& s1, const std::string& s2);
std::string updatedLine(const std::string& line,
	const std::string& s1, const std::string& s2);

int	main(int argc, char **argv)
{
	if (!correctInput(argc, argv))
		return (1);
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (!replace(argv[1], s1, s2))
		return (1);
	return (0);
}

bool correctInput(int argc, char **argv)
{
	if (argc != 4
		|| *argv[1] == '\0' || *argv[2] == '\0' || *argv[3] == '\0')
	{
		std::cout << "Wrong number of arguments or empty arguments:"
			<< std::endl
			<< "./replace FILENAME STRING_TO_FIND STRING_REPLACING"
			<< std::endl;
		return (false);
	}
	return (true);
}

bool replace(const std::string& inFileStr,
	const std::string& s1, const std::string& s2)
{
	std::ifstream inFile;
	std::ofstream outFile;
	std::string outFileStr = inFileStr + ".replace";
	std::string currLine;

	inFile.open(inFileStr.c_str());
	outFile.open(outFileStr.c_str());
	if (!inFile.is_open() || !outFile.is_open())
	{
		std::cout << "Can't open the file: " << inFileStr
			<< " or create the file: " << outFileStr << std::endl;
		return (false);
	}
	while (std::getline(inFile, currLine))
	{
		outFile << updatedLine(currLine, s1, s2) << std::endl;
	}
	inFile.close();
	outFile.close();
	return (true);
}

std::string updatedLine(const std::string& line,
	const std::string& s1, const std::string& s2)
{
	std::size_t s1_start = 0;
	std::size_t copied_pos = 0;
	std::string newLine;

	for (s1_start = line.find(s1, s1_start)
		; s1_start != std::string::npos
		; s1_start = line.find(s1, s1_start))
	{
		newLine += line.substr(copied_pos, s1_start - copied_pos) + s2;
		s1_start += s1.length();
		copied_pos = s1_start;
	}
	newLine += line.substr(copied_pos);
	return (newLine);
}
