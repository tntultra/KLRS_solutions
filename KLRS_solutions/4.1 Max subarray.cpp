#include "stdafx.h"

#include "4.1 Max subarray.h"

#include <iostream>

RET_TYPE find_max_subarray_linear(std::vector<LONG>* v, size_t start, size_t end)
{
	if (end < start || end > v->size()-1) {
		return {};
	}
	//max sum finishing at the last checked integer
	RESULT res{ start, start, v->at(start) };
	auto& resultingSum = std::get<2>(res);
	auto trailingSum = resultingSum;
	auto trailingSumStart = start;
	
	for (size_t pos = start + 1; pos <= end; ++pos) {
		auto val = v->at(pos);
		auto newSum = trailingSum + val;
			if (val > 0) {
				trailingSum = newSum;
			}
			else {
				if (trailingSum > 0) {//still greatest sum
					trailingSum = newSum;
				}
				else {
					trailingSum = val;
					trailingSumStart = pos;
				}
			}
			if (trailingSum > resultingSum) {
				res = { trailingSumStart, pos, trailingSum };
			}
		}
	}
	return res;
}

int main() {
	//std::vector<LONG> values{ 1, 3, 5, -4, 10, 12, -14, 6, 17, -1 };
	std::vector<LONG> values{ -5, 3, -1, -7, -8 };
	auto result = find_max_subarray_linear(&values, 0, values.size() - 1);
	std::cout << "start = " << std::get<0>(*result) <<
		"\nend = " << std::get<1>(*result) <<
		"\nsum = " << std::get<2>(*result) << std::endl;
	return 0;
}