#pragma once
#include "search.h";

/**
 * Calculate the final score and return the position score.
 *
 * @param int scores[2] White and blacks chip counts.
 * @param int curPly    The current ply the game is at.
 *
 * @return int Returns the final positons score.
 */
int inline calculateScores(int scores[2], Player curPlayerToMove, int curPly)
{
  if (scores[0] == scores[1])
  {
    return 0;
  }
  return scores[0] > scores[1] ? INF - curPly : -INF + curPly;
};
