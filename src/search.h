#pragma once
#include "board.h"
#include "evaluation.h"
#include "killers.h"
#include <stdint.h>

/**
 * @const int INF The maximum value that can be achieved.
 */
constexpr int INF = 99999;

typedef int Depth;

/**
 * Check to see if the has table has a killer move.
 *
 * @param unint64_t                posHash   The current board hash.
 * @param std::map<uint64_t, Move> hashTable The hashtable to lookup.
 *
 * @return bool Returns true if the killer move exists and false if not.
 */
bool inline hasKiller(uint64_t posHash, std::map<uint64_t, Move> hashTable)
{
	return hashTable.find(posHash) != hashTable.end() ? true : false;
};

/**
 * Get the killer move from the hashtable.
 *
 * @param unint64_t                posHash   The current board hash.
 * @param std::map<uint64_t, Move> hashTable The hashtable to lookup.
 *
 * @return Move Returns the killer move found.
 */
Move inline getKiller(uint64_t posHash, std::map<uint64_t, Move> hashTable)
{
	return hashTable[posHash];
};

struct Entry
{
	Move bestMove;
	int bestScore;
	Depth searchedAt;
	Bound flag;
};

enum Bound
{
	UPPER,
	LOWER,
	EXACT,
};

/**
 * Get the current relative score for a player.
 *
 * @param int    curScore        The current score of the position.
 * @param Player curPlayerToMove The current player to move.
 * 
 * @return int Returns the relative score.
 */
int inline getRelativeScore(int curScore, Player curPlayerToMove)
{
	return curPlayerToMove == WHITE ? curScore : -curScore;
};
