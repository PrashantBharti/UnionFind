#include "basicdef.h"
#include "unionfind.h"
using namespace unionfinddef;

int main(int argc, char *argv[])
{
	UNIONFIND *unionfind = UNIONFIND::Create(10);
	unionfind->Union(4, 3);
	unionfind->Union(3, 8);
	unionfind->Union(6, 5);
	unionfind->Union(4, 9);
	unionfind->Union(1, 2);
	unionfind->Union(0, 5);
	unionfind->Union(2, 7);
	unionfind->Union(1, 6);
	unionfind->Union(3, 7);
	bool IsConnected19 = unionfind->IsConnected(1, 9);
	UNIONFIND::Destroy(&unionfind);
	return 0;
}