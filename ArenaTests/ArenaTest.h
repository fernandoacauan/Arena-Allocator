//-----------------------------------------------------------------------------
// File: ArenaTest.h
//
// Desc: Arena Allocator Test class definition.
//
// Copyright (C) Fernando A. All Rights Reserved.
//-----------------------------------------------------------------------------
#pragma once
#include "gtest/gtest.h"
#include "../Arena Allocator/Arena.h"

class CArenaTest : public ::testing::Test
{
protected:
	virtual void		TearDown( void );
};