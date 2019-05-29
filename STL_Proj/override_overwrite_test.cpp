#include "pch.h"

#include "override_overwrite_test.h"

using namespace STL_Test;

void Base::Open(int dev, int num)
{

}

void Base::Close(int dev, int num)
{

}

void Base::Run(int dev, int num)
{

}

void Derive::Open(int dev, int num)
{

}

void Derive::Close(int dev, int num)
{

}


void Derive::Run(int dev, int num)
{

}