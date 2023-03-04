#include "../client.h"

typedef std::map<std::string, int, std::less<std::string> > MapStringInt;

struct Private_Data
{
	MapStringInt theMap;
	MapStringInt::iterator pos;

};
#define THE_MAP ( (*((Private_Data*)data)).theMap)
#define THE_POS ( (*((Private_Data*)data)).pos)

StringFinder::StringFinder()
{
	data = new Private_Data;
}

StringFinder::~StringFinder()
{
	delete (Private_Data*)data;
}

void StringFinder::clear()
{
	THE_MAP.clear();
}

void StringFinder::add(const char* str, int num)
{
	if(!str || !*str){ return;}
    typedef MapStringInt::value_type Entry;
    THE_MAP.insert(Entry(str,num));
}

void StringFinder::erase( const char* str )
{
	MapStringInt::iterator foundPos = THE_MAP.find( std::string(str) );
	if(foundPos!=THE_MAP.end()) 
	{ 
	    THE_MAP.erase(foundPos);
	}
}

bool StringFinder::find(const char* str)
{
	if(!str || !*str){ return false; }

	MapStringInt::iterator foundPos = THE_MAP.find(std::string(str) );
	
	if(foundPos==THE_MAP.end()) 
	{ 
		return false;  
	}
	else 
	{
		num = (*foundPos).second;
		return true; 
	}
}

void StringFinder::it_start()
{
	THE_POS = THE_MAP.begin();
	num = (int)THE_POS->second;
	str = THE_POS->first.c_str();
}

bool StringFinder::it_running()
{
	return (THE_POS!=THE_MAP.end());
}

void StringFinder::it_next()
{
	++THE_POS;
	if (THE_POS == THE_MAP.end())
		return;
	num = THE_POS->second;
	str = THE_POS->first.c_str();
}