#ifndef __TRI_SPARSE_MATRIX_H__
#define __TRI_SPARSE_MATRIX_H__

#include "Assistance.h"
#include "triple.h"	

template<class ElemType>
class TriSparseMatrix
{
public:
	TriSparseMatrix(int rs = DEFAULT_SIZE, int cs = DEFAULT_SIZE, int size = DEFAULT_SIZE);
	~TriSparseMatrix();
    int GetRows() const;
    int GetCols() const;
    int GetNum() const;
	Status SetElem(int r, int c, const ElemType &v);
	Status GetElem(int r, int c, ElemType &v);
	TriSparseMatrix(const TriSparseMatrix<ElemType> &copy);
	TriSparseMatrix<ElemType>& operator =(const TriSparseMatrix<ElemType>& copy);
	TriSparseMatrix<ElemType>& operator +(TriSparseMatrix<ElemType>& a);

private:
	Triple<ElemType>* triElems;
	int maxSize;
	int rows, cols, num;
};

template <class ElemType>
TriSparseMatrix<ElemType>::TriSparseMatrix(int r, int c, int size)
{
	if (r < 1 || c < 1)							
		throw Error("行数或列数无效!");
	maxSize = size;
	rows = r;
	cols = c;
	num = 0;
	triElems = new Triple<ElemType>[maxSize];
} 

template <class ElemType>
TriSparseMatrix<ElemType>::~TriSparseMatrix()
{
	if (triElems != NULL) delete []triElems;
}

template <class ElemType>
int TriSparseMatrix<ElemType>::GetRows() const
{
	return rows;
}

template <class ElemType>
int TriSparseMatrix<ElemType>::GetCols() const
{
	return cols;
}

template <class ElemType>
int TriSparseMatrix<ElemType>::GetNum() const
{
	return num;
}

template <class ElemType>
Status TriSparseMatrix<ElemType>::SetElem(int r, int c, const ElemType &v)
{
	if (r >= rows || c >= cols || r < 0 || c < 0)
		return RANGE_ERROR;
	
	int i, j;
	for (j = num - 1; j >= 0 && (r < triElems[j].row || r == triElems[j].row && c < triElems[j].col); j--)
		;

	if (j >= 0 && triElems[j].row == r && triElems[j].col == c)	{
		if (v == 0)	{
			for (i = j + 1; i < num; i++)
				triElems[i - 1] = triElems[i];
			num--;
		}
		else
			triElems[j].value = v;
		return SUCCESS;
	}
	else if (v != 0){	
		if (num < maxSize){
			for (i = num - 1; i > j; i--)
				triElems[i + 1] = triElems[i];
			
			triElems[j + 1].row = r;
			triElems[j + 1].col = c;
			triElems[j + 1].value = v;
			num++;
			return SUCCESS;
		}
		else return OVER_FLOW;
	}
	return SUCCESS;
}

template <class ElemType>
Status TriSparseMatrix<ElemType>::GetElem(int r, int c, ElemType &v)
{
	int j;
	if (r >= rows || c >= cols || r < 0 || c < 0)
		return RANGE_ERROR;
	for (j = num - 1; j >= 0 && (r < triElems[j].row || r == triElems[j].row && c < triElems[j].col); j--)
		;
	
	if (j >= 0 && triElems[j].row == r && triElems[j].col == c)
		v = triElems[j].value;
	else v = 0;
	return SUCCESS;
}

template <class ElemType>
TriSparseMatrix<ElemType>::TriSparseMatrix(const TriSparseMatrix<ElemType> &copy)
{
	maxSize = copy.maxSize;
	triElems = new Triple<ElemType>[maxSize];
	rows = copy.rows;
	cols = copy.cols;
	num = copy.num;
	triElems = new Triple<ElemType>[maxSize];
	for (int i = 0; i < num; i++)
		triElems[i] = copy.triElems[i];
}

template <class ElemType>
TriSparseMatrix<ElemType> &TriSparseMatrix<ElemType>::operator =(const TriSparseMatrix<ElemType> &copy)
{
	if (&copy != this)	{
		maxSize = copy.maxSize;
		if (triElems != NULL) delete []triElems;
		triElems = new Triple<ElemType>[maxSize];
		rows = copy.rows;
		cols = copy.cols;
		num = copy.num;

		for (int i = 0; i < num; i++)
			triElems[i] = copy.triElems[i];
	}
	return *this;
}

template <class ElemType>
TriSparseMatrix<ElemType>& TriSparseMatrix<ElemType>::operator +(TriSparseMatrix<ElemType> &a)
{
	int i, j, va, vb;
	for (i = 0; i < this->rows; i++)
	{
		for (j = 0; j < this->cols; j++)
		{
			this->GetElem(i, j, vb);
			a.GetElem(i, j, va);
			if (va == 0 && vb == 0) continue;
			a.SetElem(i, j, va + vb);
		}
	}
	return a;
}


#endif
