#ifndef __CRO_NODE_H__
#define __CRO_NODE_H__

#include "triple.h"

template<class ElemType>
struct CrossNode
{
	CrossNode();
	CrossNode(const Triple<ElemType> &e, CrossNode<ElemType> *rLink = NULL, CrossNode<ElemType> *dLink = NULL);	

	Triple<ElemType> triElem;
	CrossNode<ElemType>* right, * down;
};

template<class ElemType>
CrossNode<ElemType>::CrossNode()
{
	right = NULL;	
	down = NULL;
}

template<class ElemType>
CrossNode<ElemType>::CrossNode(const Triple<ElemType> &e, CrossNode<ElemType> *rLink, CrossNode<ElemType> *dLink)
{
	triElem.row = e.row;	
	triElem.col = e.col;	
	triElem.value = e.value;
	right = rLink;		
	down = dLink;			
}

#endif
