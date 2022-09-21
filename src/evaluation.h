#pragma once
#include "search.h"

/**
 * @const int MOBILITY_WT Determines how important mobility should count.
 */
constexpr int MOBILITY_WT = 2;

/**
 * @const int MOBILITY_PER_SQ How much is each square worth mobility wise.
 */
constexpr int MOBILITY_PER_SQ = 1;

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

/**
 * Calculate the mobility of the current position.
 *
 * @param size_t whitesMoveCount The number of avaliable moves for white.
 * @param size_t whitesMoveCount The number of avaliable moves for black.
 *
 * @return int Returns the mobility score.
 */
int inline evaluateMobility(size_t whitesMoveCount, size_t blacksMoveCount)
{
  int score = 0;
  for (size_t o; o < whitesMoveCount; ++o) score += MOBILITY_PER_SQ * MOBILITY_WT;
  for (size_t o; o < blacksMoveCount; ++o) score -= MOBILITY_PER_SQ * MOBILITY_WT;
  return score;
}
