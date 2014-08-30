#ifndef __union_find_h__
#define __union_find_h__
/***********************************************/
namespace unionfinddef
{
/***********************************************/
//QUICKFIND union takes O(N)
//QUICKFIND find takes O(1)
/***********************************************/
class QUICKFIND
{
public:
	static QUICKFIND* Create(size_t szNbNodes);
	static void Destory(QUICKFIND **ppquickfind);

private:
	QUICKFIND(void);
	~QUICKFIND(void);
	int Initialze(size_t szNbNodes_);

public:
	int Union(size_t szNodeIndex1, size_t szNodeIndex2);
	bool IsConnected(size_t szNodeIndex1, size_t szNodeIndex2) const;

private:
	size_t szNbNodes;
	size_t *arrNodes;
};
/***********************************************/
//UNIONFIND with weighted QuickUnion and path comprassion
//When any tree is totally flat
//Union takes O(1)
//Find takes O(1)
/***********************************************/
class UNIONFIND
{
public:
	static UNIONFIND* Create(size_t szNbNodes);
	static void Destroy(UNIONFIND **ppunionfind);

private:
	UNIONFIND(void);
	~UNIONFIND(void);
	int Intialze(size_t szNbNodes_);

public:
	int Union(size_t szNodeIndex1, size_t szNodeIndex2);
	bool IsConnected(size_t szNodeIndex1, size_t szNodeIndex2) const;

private:
	size_t Root(size_t szNodeIndex) const;

private:
	size_t szNbNodes;
	size_t *arrWeights; //Number of nodes in a tree rooted at ith node
	size_t *arrNodes;
};
/***********************************************/
}
/***********************************************/
#endif