#ifndef __TRIPLE_H__
#define __TRIPLE_H__

template<class ElemType>
struct Triple
{
	Triple() = default;
	Triple(int r, int c, ElemType v);

	int row, col;
	ElemType value;
};

template<class ElemType>
Triple<ElemType>::Triple(int r, int c, ElemType v)
{
	row = r;
	col = c;
	value = v;
}

#endif

