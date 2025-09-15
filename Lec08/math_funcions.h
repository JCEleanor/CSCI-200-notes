#ifndef MATH_FUNCTION_H
#define MATH_FUNCTION_H

/**
 * @brief sums two doubles
 *
 * @param LHS left hand side value to add
 * @param RHS right hand side value to add
 * @return double sum of left and right hand sides
 */
double add(const double LHS, const double RHS);

/**
 * @brief subtracts two doubles
 *
 * @param LHS left hand side value to subtract
 * @param RHS right hand side value to subtract
 * @return double difference of left and right hand sides
 */
double sub(const double LHS, const double RHS);

/**
 * @brief multiplies two doubles
 *
 * @param LHS left hand side value to multiply
 * @param RHS right hand side value to multiply
 * @return double product of left and right hand sides
 */
double mult(const double LHS, const double RHS);

/**
 * @brief divides two doubles
 *
 * @param LHS numerator
 * @param RHS denominator
 * @return double quotient of numerator divided by denominator
 */
double div(const double LHS, const double RHS);

/**
 * @brief implements floating point modulus operator
 *
 * @param LHS numerator
 * @param RHS denominator
 * @return double remainder leftover of numerator / denominator
 */
double mod(const double LHS, const double RHS);

#endif