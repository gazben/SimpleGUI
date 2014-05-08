#ifndef XMLparser_h__
#define XMLparser_h__

#include <string>

class SGengine;

class XMLparser{

public:

	XMLparser(SGengine*, std::string);

private:

	SGengine* engine;

};

#endif // XMLparser_h__
