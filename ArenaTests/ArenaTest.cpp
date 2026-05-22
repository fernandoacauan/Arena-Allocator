//-----------------------------------------------------------------------------
// File: ArenaTest.cpp
//
// Desc: Arena Allocator tests.
//
// Copyright (C) Fernando A. All Rights Reserved.
//-----------------------------------------------------------------------------
#include "pch.h"
#include "ArenaTest.h"

void CArenaTest::TearDown( void )
{
	CArena::Free( 0 );
	CArena::Free( 1 );
	CArena::Free( 2 );
}

TEST_F( CArenaTest, AllocReturnsValidPointer )
{
	char *ptr = CArena::Alloc( 100, 0 );
	EXPECT_NE( ptr, nullptr );
}

TEST_F( CArenaTest, ArenaProperlyAligned )
{
	char *	ptr = CArena::Alloc( 3, 0 );
	size_t	address;

	EXPECT_NE( ptr, nullptr );

	address = (size_t)ptr;

	EXPECT_EQ( address % sizeof(void *), 0 );
}