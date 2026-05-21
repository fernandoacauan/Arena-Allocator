//-----------------------------------------------------------------------------
// File: main.cpp
//
// Desc: Arena Allocator example.
//
// Copyright (C) Fernando A. All Rights Reserved.
//-----------------------------------------------------------------------------
#include "Arena.h"
#include <stdio.h>

static constexpr size_t ARENA_ZERO	= 0;
static constexpr size_t LIST_SIZE	= 10;

typedef struct node_s
{
	int				data;
	struct node_s *	next;
} node_t;

class CLinkedList
{
	node_t *	m_head;
	node_t *	m_tail;
	int			m_count;
public:
				CLinkedList( void );

	void		Push( const int data );
	void		Print( void ) const;
};

CLinkedList::CLinkedList( void )
:
	m_head( nullptr ),
	m_tail( nullptr ),
	m_count( 0 )
{
}

void CLinkedList::Push( const int data )
{
	node_t *node = (node_t *)CArena::Alloc( sizeof(node_t), ARENA_ZERO );

	node->data	= data;
	node->next	= nullptr;
	
	if( !m_head ) {
		m_head = node;
		m_tail = node;
		++m_count;
		return;
	}

	m_tail->next	= node;
	m_tail			= node;

	++m_count;
}

void CLinkedList::Print( void ) const
{
	node_t *current = m_head;

	while ( current ) {
		printf( "%d ", current->data );
		current = current->next;
	}

	printf( "\nCount: %d\n", m_count );
}

int main( void )
{
	CLinkedList *linked = new ( CArena::Alloc(sizeof(CLinkedList), ARENA_ZERO) ) CLinkedList();
	
	for ( int idx = 1; idx <= LIST_SIZE; ++idx ) {
		linked->Push( idx );
	}

	printf( "List: ");

	linked->Print();

	CArena::Free( ARENA_ZERO );

	return 0;
}
