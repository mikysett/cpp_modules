#ifndef Convert_HPP
# define Convert_HPP
# include <iostream>
# include <sstream>
# include <iomanip>
# include <limits>
# define NB_CONVERSIONS 4

class Convert
{
private:
	typedef enum e_status
	{
		NOT_CONVERTED,
		IMPOSSIBLE,
		NON_DISPLAYABLE,
		OK
	} t_status;
	typedef enum e_types
	{
		T_CHAR = 0,
		T_INT,
		T_FLOAT,
		T_DOUBLE,
		T_NONE
	} t_types;
	typedef struct s_conv
	{
		char c;
		int i;
		float f;
		double d;
	} t_conv;
	typedef struct s_conv_types
	{
		t_status status;
		void (Convert::*convFn)( const std::string& );
	}	t_conv_types;

	t_conv_types conversion[NB_CONVERSIONS + 1];
	t_conv converted;
	// typedef void (Convert::*t_conv_fn)( const std::string& );
	// t_conv_fn convFn[NB_CONVERSIONS + 1];

	static bool isChar(const::std::string& literal);
	static bool isInt(const::std::string& literal);
	static bool isFloat(const::std::string& literal);
	static bool isDouble(const::std::string& literal);
	static Convert::t_status setCharStatus(char c);
	static std::string int_to_string(int i);

	void initConversion( void );
	t_types takeType( const std::string& literal ) const;
	bool printErrorValue( t_status convStatus ) const;
public:
	Convert();
	Convert( std::string literal );
	Convert( const Convert &oldConvert );
	Convert& operator= ( const Convert &oldConvert );
	~Convert();

	void convertToChar( const std::string& literal );
	void convertToInt( const std::string& literal );
	void convertToFloat( const std::string& literal );
	void convertToDouble( const std::string& literal );
	void convertToNone( const std::string& literal );
	void printConversions( void ) const;
};

#endif
