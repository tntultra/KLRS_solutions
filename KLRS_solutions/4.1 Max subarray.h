#pragma once

#include "boost/optional/optional.hpp"

#include <tuple>
#include <vector>

//functions return type
using RESULT = std::tuple<size_t, size_t, LONG>;//start, end, sum
using RET_TYPE = boost::optional<RESULT>;

RET_TYPE find_max_subarray_linear(std::vector<LONG>* v, size_t start, size_t end);
