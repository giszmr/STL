#include <string>
#pragma once


namespace STL_Test
{
	class Base
	{
	public:
		Base(int dev, int num):m_dev(dev),m_num(num) {}
		~Base() {}
		virtual void Open(int dev, int num);
		virtual void Close(int dev, int num);
		virtual void Run(int dev, int num);
	private:
		int m_dev;
		int m_num;

	};



	class Derive :Base
	{
		Derive(int dev, int num, int length, int width, int height)
			:Base(dev, num),
			m_length(length),
			m_width(width),
			m_height(height)
		{}
		~Derive() {}
		void Open(int dev, int num);
		void Close(int dev, int num);
		void Run(int dev, int num);
	private:
		int m_length;
		int m_width;
		int m_height;

	};


	/*
(1) If functions of class Base are not virtual
	notice: in this case, there is no vftable.

1>class STL_Test::Derive	size(20):
1>	+---
1> 0	| +--- (base class STL_Test::Base)
1> 0	| | m_dev
1> 4	| | m_num
1>	| +---
1> 8	| m_length
1>12	| m_width
1>16	| m_height
1>	+---
	


(2) If functions of class Base are virtual
	notice: no matter how many virtual function are there in vftable, size of vfptr of class Derive is still 4.

1>class STL_Test::Derive	size(24):
1>	+---
1> 0	| +--- (base class STL_Test::Base)
1> 0	| | {vfptr}
1> 4	| | m_dev
1> 8	| | m_num
1>	| +---
1>12	| m_length
1>16	| m_width
1>20	| m_height
1>	+---
1>
1>STL_Test::Derive::$vftable@:
1>	| &Derive_meta
1>	|  0
1> 0	| &STL_Test::Derive::Open
1> 1	| &STL_Test::Derive::Close
1> 2	| &STL_Test::Derive::Run
1>

	*/




}