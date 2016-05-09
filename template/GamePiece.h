//GamePiece.h
#include <string>
using namespace std;

#ifndef DEFINES_GAMEPIECEH
#define DEFINES_GAMEPIECEH
class GamePiece{
public:
    GamePiece();
	virtual void setName(string inString) ;
	virtual string getName() ;
private:
	string name;
};
#endif 