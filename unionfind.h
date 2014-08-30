#ifndef __union_find_h__
#define __union_find_h__
/***********************************************/
namespace unionfinddef
{
/***********************************************/
//QUICKFIND inserts a generic type value in O(N)
//QUICKFIND finds the connection in O(N)
/***********************************************/
class QUICKFIND
{
public:
	static QUICKFIND* Create(size_t szNbNodes_);
	static void Destory(QUICKFIND** ppquickfind);

private:
	QUICKFIND(void);
	~QUICKFIND(void);
	int Initialze(size_t szNbNodes);

public:
	int Union(size_t szNodeIndex1, size_t szNodeIndex2);
	bool IsConnected(size_t szNodeIndex1, size_t szNodeIndex2) const;

private:
	size_t szNbNodes;
	size_t *arrNodes;
};
/***********************************************/
}
/***********************************************/
#endif