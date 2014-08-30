#include "basicdef.h"
#include "unionfind.h"
using namespace unionfinddef;

int main(int argc, char *argv[])
{
	QUICKFIND *quickfind = QUICKFIND::Create(4);
	quickfind->Union(1, 3);
	quickfind->Union(0, 2);
	bool bIsConnected03 = quickfind->IsConnected(0, 3);
	bool bIsConnected02 = quickfind->IsConnected(0, 2);
	QUICKFIND::Destory(&quickfind);
	return 0;
}