#include "basicdef.h"
#include "unionfind.h"
using namespace unionfinddef;
/***********************************************/
QUICKFIND::QUICKFIND(void)
: szNbNodes(0)
, arrNodes(nullptr)
{
}
/***********************************************/
QUICKFIND::~QUICKFIND(void)
{
	delete[] arrNodes;
}
/***********************************************/
/*static*/ QUICKFIND* QUICKFIND::Create(size_t szNbNodes_)
{
	QUICKFIND* quickfind = new QUICKFIND();
	int iRet = quickfind->Initialze(szNbNodes_);
	if(!iRet)
		delete quickfind, quickfind = nullptr;
	return quickfind;
}
/***********************************************/
/*static*/ void QUICKFIND::Destory(QUICKFIND** ppquickfind)
{
	delete *ppquickfind;
	*ppquickfind = nullptr;
}
/***********************************************/
int QUICKFIND::Initialze(size_t szNbNodes_)
{
	szNbNodes = szNbNodes_;
	arrNodes = new size_t[szNbNodes];
	if(IS_NULL(arrNodes))
		return FALSE;

	for(size_t szIdx = 0; szIdx < szNbNodes; szIdx++)
		arrNodes[szIdx] = szIdx;

	return TRUE;
}
/***********************************************/
int QUICKFIND::Union(size_t szNodeIndex1, size_t szNodeIndex2)
{
	if(szNodeIndex1 >= szNbNodes || szNodeIndex2 >= szNbNodes)
		return FALSE;

	size_t szValue1 = arrNodes[szNodeIndex1];
	size_t szValue2 = arrNodes[szNodeIndex2];

	for(size_t szIdx = 0; szIdx < szNbNodes; szIdx++)
	{
		if(arrNodes[szIdx] == szValue2)
			arrNodes[szIdx] = szValue1;
	}

	return TRUE;
}
/***********************************************/
bool QUICKFIND::IsConnected(size_t szNodeIndex1, size_t szNodeIndex2) const
{
	if(szNodeIndex1 >= szNbNodes || szNodeIndex2 >= szNbNodes)
		return FALSE;

	if(arrNodes[szNodeIndex1] == arrNodes[szNodeIndex2])
		return TRUE;

	return FALSE;
}
/***********************************************/