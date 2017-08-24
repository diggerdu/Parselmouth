/*
 * Copyright (C) 2017  Yannick Jadoul
 *
 * This file is part of Parselmouth.
 *
 * Parselmouth is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Parselmouth is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Parselmouth.  If not, see <http://www.gnu.org/licenses/>
 */

#include "Parselmouth.h"
#include "TimeClassAspects.h"

#include "utils/SignatureCast.h"
#include "utils/pybind11/NumericPredicates.h"

namespace py = pybind11;
using namespace py::literals;

namespace parselmouth {

void Binding<Formant>::init() {
	using signature_cast_placeholder::_;

	initTimeFrameSampled(*this);

	def("get_value_at_time", // TODO Enum for Hertz vs. Bark?
	    signature_cast<_ (_, Positive<int>, _, bool)>(Formant_getValueAtTime),
		"formant_number"_a, "time"_a, "bark"_a = false);

	def("get_bandwidth_at_time",
	    signature_cast<_ (_, Positive<int>, _, bool)>(Formant_getBandwidthAtTime),
	    "formant_number"_a, "time"_a, "bark"_a = false);
}

} // namespace parselmouth