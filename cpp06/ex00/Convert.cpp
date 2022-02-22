#include "Convert.hpp"

Convert::Convert()
{
	initConversion();
}

Convert::Convert( std::string literal )
{
	initConversion();
	(this->*(conversion[takeType(literal)].convFn))(literal);
}

Convert::Convert( const Convert &oldConvert )
{
	for (size_t i = 0; i < NB_CONVERSIONS; i++)
		conversion[i].status = oldConvert.conversion[i].status;
	converted = oldConvert.converted;
}

Convert& Convert::operator= ( const Convert &oldConvert )
{
	converted = oldConvert.converted;
	return (*this);
}

Convert::~Convert()
{}

void Convert::initConversion( void )
{
	for (size_t i = 0; i < NB_CONVERSIONS; i++)
		conversion[i].status = NOT_CONVERTED;
	conversion[T_CHAR].convFn = &Convert::convertToChar;
	conversion[T_INT].convFn = &Convert::convertToInt;
	conversion[T_FLOAT].convFn = &Convert::convertToFloat;
	conversion[T_DOUBLE].convFn = &Convert::convertToDouble;
	conversion[T_NONE].convFn = &Convert::convertToNone;
}

Convert::t_types Convert::takeType( const std::string& literal ) const
{
	if (isChar(literal))
		return (T_CHAR);
	else if (isInt(literal))
		return (T_INT);
	else if (isFloat(literal))
		return (T_FLOAT);
	else if (isDouble(literal))
		return (T_DOUBLE);
	else
		return (T_NONE);
}

bool Convert::isChar(const::std::string& literal)
{
	if (literal.length() == 1
		&& (!std::isdigit(literal[0])))
		return (true);
	return (false);
}

bool Convert::isInt(const::std::string& literal)
{
	const int lit_len = literal.length();
	int i;

	if (literal[0] == '-')
		i = 1;
	else
		i = 0;
	if (lit_len == i)
	return (false);
	for (; i < lit_len; i++)
		if (!std::isdigit(literal[i]))
			return (false);
	return (true);
}

bool Convert::isFloat(const::std::string& literal)
{
	size_t i = 0;

	if (literal == "-inff"
		|| literal == "+inff"
		|| literal == "nanf")
		return (true);

	if (literal[i] == '-')
		i++;
	while (std::isdigit(literal[i]))
		i++;
	if (i + 1 == literal.length() && literal[i] == 'f')
		return (true);
	if (i != literal.length()
		&& literal[i] != '.')
		return (false);
	if (literal[i] == '.')
		i++;
	while (std::isdigit(literal[i]))
		i++;
	if (i == literal.length()
		|| literal[i] != 'f'
		|| i + 1 != literal.length())
		return (false);
	return (true);
}

bool Convert::isDouble(const::std::string& literal)
{
	size_t i = 0;

	if (literal == "-inf"
		|| literal == "+inf"
		|| literal == "nan")
		return (true);

	if (literal[i] == '-')
		i++;
	while (std::isdigit(literal[i]))
		i++;
	if (literal[i] != '.')
		return (false);
	i++;
	while (std::isdigit(literal[i]))
		i++;
	if (i != literal.length())
		return (false);
	return (true);
}



void Convert::convertToChar( const std::string& literal )
{
	std::stringstream streamConv(literal);

	streamConv >> converted.c;
	conversion[T_CHAR].status = setCharStatus(converted.c);
	conversion[T_INT].status = IMPOSSIBLE;
	conversion[T_FLOAT].status = IMPOSSIBLE;
	conversion[T_DOUBLE].status = IMPOSSIBLE;
}

Convert::t_status Convert::setCharStatus(char c)
{
	if (std::isprint(c))
		return (OK);
	else
		return (NON_DISPLAYABLE);
}

void Convert::convertToInt( const std::string& literal )
{
	std::stringstream streamConv(literal);

	streamConv >> converted.i;
	if (int_to_string(converted.i) != literal)
	{
		convertToNone(literal);
		return ;
	}
	else
	{
		conversion[T_INT].status = OK;
		converted.c = static_cast<char>(converted.i);
		conversion[T_CHAR].status = setCharStatus(converted.c);
		converted.f = static_cast<float>(converted.i);
		conversion[T_FLOAT].status = OK;
		converted.d = static_cast<double>(converted.i);
		conversion[T_DOUBLE].status = OK;
	}
}

std::string Convert::int_to_string(int i)
{
	std::stringstream str_stream;
	std::string str_int;

	str_stream << i;
	str_stream >> str_int;
	return (str_int);
}

void Convert::convertToFloat( const std::string& literal )
{
	if (literal == "-inff")
		converted.f = -1. / 0.;
	else if (literal == "+inff")
		converted.f = 1. / 0.;
	else if (literal == "nanf")
		converted.f = std::numeric_limits<float>::quiet_NaN();
	else
	{
		std::stringstream streamConv(literal.substr(0, literal.length() - 2));
		streamConv >> converted.f;
	}
	conversion[T_FLOAT].status = OK;

	converted.i = static_cast<int>(converted.f);
	if (converted.i != static_cast<long long>(converted.f))
	{
		conversion[T_INT].status = IMPOSSIBLE;
		conversion[T_CHAR].status = IMPOSSIBLE;
	}
	else
	{
		conversion[T_INT].status = OK;
		converted.c = static_cast<char>(converted.f);
		conversion[T_CHAR].status = setCharStatus(converted.c);
	}
	converted.d = static_cast<double>(converted.f);
	conversion[T_DOUBLE].status = OK;
}

void Convert::convertToDouble( const std::string& literal )
{
	std::stringstream streamConv(literal);

	if (literal == "-inf")
		converted.d = -1. / 0.;
	else if (literal == "+inf")
		converted.d = 1. / 0.;
	else if (literal == "nan")
		converted.d = std::numeric_limits<double>::quiet_NaN();
	else
		streamConv >> converted.d;
	conversion[T_DOUBLE].status = OK;

	converted.i = static_cast<int>(converted.d);
	if (converted.i != static_cast<long long>(converted.d))
	{
		conversion[T_INT].status = IMPOSSIBLE;
		conversion[T_CHAR].status = IMPOSSIBLE;
	}
	else
	{
		conversion[T_INT].status = OK;
		converted.c = static_cast<char>(converted.f);
		conversion[T_CHAR].status = setCharStatus(converted.c);
	}
	converted.c = static_cast<char>(converted.d);
	conversion[T_CHAR].status = setCharStatus(converted.c);
	converted.f = static_cast<float>(converted.d);
	conversion[T_FLOAT].status = OK;
}

void Convert::convertToNone( const std::string& literal )
{
	literal.c_str(); // For compiler warnings
	for (size_t i = 0; i < NB_CONVERSIONS; i++)
		conversion[i].status = IMPOSSIBLE;
}

void Convert::printConversions( void ) const
{
	std::cout << "char: ";
	if (!printErrorValue(conversion[T_CHAR].status))
		std::cout << converted.c;
	std::cout << std::endl;
	std::cout << "int: ";
	if (!printErrorValue(conversion[T_INT].status))
		std::cout << converted.i;
	std::cout << std::endl;
	std::cout << "float: ";
	if (!printErrorValue(conversion[T_FLOAT].status))
		std::cout << std::fixed << std::setprecision(1) << converted.f << "f";
	std::cout << std::endl;
	std::cout << "double: ";
	if (!printErrorValue(conversion[T_DOUBLE].status))
		std::cout << converted.d;
	std::cout << std::endl;
}

bool Convert::printErrorValue( t_status convStatus ) const
{
	switch (convStatus)
	{
	case NOT_CONVERTED:
		std::cout << "Not converted";
		return (true);
	case IMPOSSIBLE:
		std::cout << "Impossible";
		return (true);
	case NON_DISPLAYABLE:
		std::cout << "Non displayable";
		return (true);
	default:
		return (false);
	}
}
