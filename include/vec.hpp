#pragma once

using vec = std::array<float, 3>;

const float vecLength(const vec a);
const vec normalize(const vec a);
const vec stlToVec(const float* stlVec);
const vec vecPlus(const vec a, const vec b);
const vec vecMinus(const vec a, const vec b);
const vec vecTimes(const float a, const vec b);
const float scalarProduct(const vec a, const vec b);
