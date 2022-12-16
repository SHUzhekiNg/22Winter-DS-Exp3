#ifndef __CROSS_LIST_H__
#define __CROSS_LIST_H__

#include "Assistance.h"
#include "crossnode.h"
#include "triple.h"

template<class ElemType>
class CrossList
{
public:
	CrossList(int rs = DEFAULT_SIZE, int cs = DEFAULT_SIZE);
	~CrossList();
	void Clear();
	int GetRows() const { return rows; };
    int GetCols() const { return cols; };
    int GetNum() const { return num; };
	Status SetElem(int r, int c, const ElemType &v);
	Status GetElem(int r, int c, ElemType &v);
	CrossList(const CrossList<ElemType> &b);
	CrossList<ElemType> &operator =(const CrossList<ElemType> &b); 
	CrossList<ElemType> operator +(const CrossList<ElemType> &b); 
	void Transpose();

private:
	CrossNode<ElemType>** rowHead, ** colHead;
	int rows, cols, num;
};

template <class ElemType>
void CrossList<ElemType>::Transpose()
{
	for (int i = 0; i < rows; ++i) {
		CrossNode<ElemType>* ptr = rowHead[i];
		while (ptr != nullptr) {
			swap(ptr->triElem.row, ptr->triElem.col);
			CrossNode<ElemType>* temp = ptr->right;
			ptr->right = ptr->down;
			ptr->down = temp;
			ptr = ptr->down;
		}
	}
	swap(cols, rows);
	swap(rowHead, colHead);
}

template <class ElemType>
CrossList<ElemType>::CrossList(int rs, int cs)
{
	if (rs < 1 || cs < 1)							
		throw Error("行数或列数无效!");
	rows = rs;
	cols = cs;
	num = 0;
	rowHead = new CrossNode<ElemType> *[rows];
	colHead = new CrossNode<ElemType> *[cols];
	for (int row = 0; row < rows; row++) 
		rowHead[row] = NULL;
	for (int col = 0; col < cols; col++) 
		colHead[col] = NULL;
}

template <class ElemType>
CrossList<ElemType>::~CrossList()
{
	Clear();
	delete []rowHead;
	delete []colHead;
}

template <class ElemType>
void CrossList<ElemType>::Clear()
{
    CrossNode<ElemType> *p;
	for (int i = 0; i < rows; i++)	
		while (rowHead[i] != NULL)	{ 
			p =  rowHead[i];		
			rowHead[i] = p->right;	
			delete p;
		}
	for (int j = 0; j < cols; j++) 
		colHead[j] = NULL;
    num = 0;
}

template <class ElemType>
Status CrossList<ElemType>::SetElem(int r, int c, const ElemType &v)
{
	if (r >= rows || c >= cols || r < 0 || c < 0)
		return RANGE_ERROR;
	
	CrossNode<ElemType> *pre, *p;
	if (v == 0) { 
	    pre = NULL; p=rowHead[r];
		while (p != NULL && p->triElem.col < c)	{
			pre = p;
            p = p->right;
		}
  
	    if (p != NULL && p->triElem.col == c)  {
			if (rowHead[r] == p)
                rowHead[r] = p->right;
            else
                pre->right = p->right;

			if (colHead[c] == p)  
			   colHead[c] = p->down;
            else {
                pre = colHead[c];
                while (pre->down != p) 
                    pre = pre->down;
                pre->down = p->down;
            }
            delete p;            
		    num--;
        }
    }        		
	else{ 
	    pre = NULL; p=rowHead[r];
		while (p != NULL && p->triElem.col < c)	{
			pre = p;	p = p->right;
		}
  
	    if (p != NULL && p->triElem.col == c) 
            p->triElem.value == v;
        else { 
            Triple<ElemType> e(r, c, v);
	        CrossNode<ElemType> *ePtr = new CrossNode<ElemType>(e);
	        if (rowHead[r] == p)
                rowHead[r] = ePtr;
 	        else
			    pre->right = ePtr;
   	        ePtr->right = p;	
		    pre = NULL; p=colHead[c];
		    while (p != NULL && p->triElem.row < r)	{
			    pre = p;
   	            p = p->down;
		    }
	        if (colHead[c] == p)
                colHead[c] = ePtr;
 	        else
			    pre->down = ePtr;
   	        ePtr->down = p;	
		    num++;
	   }
	}	   
	return SUCCESS;	
}

template <class ElemType>
Status CrossList<ElemType>::GetElem(int r, int c, ElemType &v)
{
	if (r >= rows || c >= cols || r < 0 || c < 0)
		return RANGE_ERROR;
	
	CrossNode<ElemType> *p;
	for (p=rowHead[r]; p != NULL && p->triElem.col < c; p = p->right)
		;
	if (p != NULL && p->triElem.col == c)
		v = p->triElem.value;
	else v = 0;

	return SUCCESS;
}

template <class ElemType>
CrossList<ElemType>::CrossList(const CrossList<ElemType> &b)
{
    CrossNode<ElemType> *p;
	rows = b.rows;
	cols = b.cols;
	num = 0;
	rowHead = new CrossNode<ElemType> *[rows];
	colHead = new CrossNode<ElemType> *[cols];
	for (int i = 0; i < rows; i++) 
		rowHead[i] = NULL;
	for (int i = 0; i < cols; i++) 
		colHead[i] = NULL;
	
	for (int i = 0; i < rows; i++)
		for (p = b.rowHead[i]; p != NULL; p = p->right)
			SetElem(p->triElem.row, p->triElem.col, p->triElem.value);
}

template <class ElemType>
CrossList<ElemType> &CrossList<ElemType>::operator =(const CrossList<ElemType> &b)
{
    if (rows != b.rows || cols != b.cols)
        throw Error("行数或列数不相等!");	

	if (&b != this) {
	    CrossNode<ElemType> *p;
		Clear();
		num = b.num;
		for (int i = 0; i < rows; i++)
			for (p = b.rowHead[i]; p != NULL; p = p->right)
			   SetElem(p->triElem.row, p->triElem.col, p->triElem.value);
	}
	return *this;

}

template <class ElemType>
CrossList<ElemType> CrossList<ElemType>::operator +(const CrossList<ElemType> &b)
{
    if (rows != b.rows || cols != b.cols)
        throw Error("行数或列数不相等!");	

    CrossList<ElemType> temp(b.rows,b.cols);
    ElemType v;
    CrossNode<ElemType> *p, *q;

	for (int i = 0; i < rows; i++) {
		p = rowHead[i]; q = b.rowHead[i];
        while (p != NULL && q != NULL)  
           if (p->triElem.col < q->triElem.col) {
		       temp.SetElem(p->triElem.row, p->triElem.col, p->triElem.value);
		       p = p->right;
           }
           else  if (p->triElem.col > q->triElem.col) {
		       temp.SetElem(q->triElem.row, q->triElem.col, q->triElem.value);
		       q = q->right;
           }
           else  {
               v = p->triElem.value + q->triElem.value;
               if (v != 0)
		          temp.SetElem(q->triElem.row, q->triElem.col, v);
		       p = p->right;
		       q = q->right;
           }
        while (p != NULL)  {
 		   temp.SetElem(p->triElem.row, p->triElem.col, p->triElem.value);
		   p = p->right;
        }
        while (q != NULL)  {
           temp.SetElem(q->triElem.row, q->triElem.col, q->triElem.value);
		   q = q->right;
        }
	}			   
	return temp;

}
#endif
