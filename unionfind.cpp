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
/*static*/ QUICKFIND* QUICKFIND::Create(size_t szNbNodes)
{
	QUICKFIND* quickfind = new QUICKFIND();
	if(IS_NULL(quickfind))
		return nullptr;

	int iRet = quickfind->Initialze(szNbNodes);
	if(!iRet)
		delete quickfind, quickfind = nullptr;
	return quickfind;
}
/***********************************************/
/*static*/ void QUICKFIND::Destory(QUICKFIND **ppquickfind)
{
	if(IS_NULL(ppquickfind))
		return;

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
	if(IS_NULL(this))
		return FALSE;

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
	if(IS_NULL(this))
		return false;

	if(szNodeIndex1 >= szNbNodes || szNodeIndex2 >= szNbNodes)
		return false;

	return arrNodes[szNodeIndex1] == arrNodes[szNodeIndex2] ? true : false;
}
/***********************************************/

/***********************************************/
UNIONFIND::UNIONFIND(void)
: szNbNodes(0)
, arrWeights(nullptr)
, arrNodes(nullptr)
{
}
/***********************************************/
UNIONFIND::~UNIONFIND(void)
{
	delete[] arrWeights;
	delete[] arrNodes;
}
/***********************************************/
/*static*/ UNIONFIND* UNIONFIND::Create(size_t szNbNodes)
{
	UNIONFIND* unionfind = new UNIONFIND();
	if(IS_NULL(unionfind))
		return nullptr;

	int iRet = unionfind->Intialze(szNbNodes);
	if(!iRet)
		delete unionfind, unionfind = nullptr;

	return unionfind;
}
/***********************************************/
/*static*/ void UNIONFIND::Destroy(UNIONFIND **ppunionfind)
{
	if(IS_NULL(ppunionfind))
		return;

	delete *ppunionfind;
	*ppunionfind = nullptr;
}
/***********************************************/
int UNIONFIND::Intialze(size_t szNbNodes_)
{
	szNbNodes = szNbNodes_;
	arrNodes = new size_t[szNbNodes];
	if(IS_NULL(arrNodes))
		return FALSE;

	arrWeights = new size_t[szNbNodes];
	if(IS_NULL(arrWeights))
		return FALSE;

	for(size_t szIdx = 0; szIdx < szNbNodes; szIdx++)
	{
		arrNodes[szIdx] = szIdx;
		arrWeights[szIdx] = 1;
	}

	return TRUE;
}
/***********************************************/
size_t UNIONFIND::Root(size_t szNodeIndex) const
{
	if(szNodeIndex >= szNbNodes)
		return szNbNodes;

	while(arrNodes[szNodeIndex] != szNodeIndex)
		szNodeIndex = arrNodes[szNodeIndex];

	return szNodeIndex;
}
/***********************************************/
int UNIONFIND::Union(size_t szNodeIndex1, size_t szNodeIndex2)
{
	if(IS_NULL(this))
		return FALSE;

	if(szNodeIndex1 >= szNbNodes || szNodeIndex2 >= szNbNodes)
		return FALSE;

	size_t szNodeIndex1Root = Root(szNodeIndex1);
	size_t szNodeIndex2Root = Root(szNodeIndex2);

	if(arrWeights[szNodeIndex1Root] <= arrWeights[szNodeIndex2Root])
	{
		arrNodes[szNodeIndex1Root] = szNodeIndex2Root;
		arrWeights[szNodeIndex2Root] = arrWeights[szNodeIndex2Root] + arrWeights[szNodeIndex1Root];
	}
	else
	{
		arrNodes[szNodeIndex2Root] = szNodeIndex1Root;
		arrWeights[szNodeIndex1Root] = arrWeights[szNodeIndex1Root] + arrWeights[szNodeIndex2Root];
	}

	return TRUE;
}
/***********************************************/
bool UNIONFIND::IsConnected(size_t szNodeIndex1, size_t szNodeIndex2) const
{
	if(IS_NULL(this))
		return FALSE;

	if(szNodeIndex1 >= szNbNodes || szNodeIndex2 >= szNbNodes)
		return FALSE;

	size_t szNodeIndex1Root = Root(szNodeIndex1);
	size_t szNodeIndex2Root = Root(szNodeIndex2);

	arrNodes[szNodeIndex1] = szNodeIndex1Root;
	arrNodes[szNodeIndex2] = szNodeIndex2Root;

	return szNodeIndex1Root == szNodeIndex2Root ? true : false;
}
/***********************************************/