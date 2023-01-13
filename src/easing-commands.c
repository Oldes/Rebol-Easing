//
// This is free and unencumbered software released into the public domain.
//
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software, either in source code form or as a compiled
// binary, for any purpose, commercial or non-commercial, and by any
// means.
//
// In jurisdictions that recognize copyright laws, the author or authors
// of this software dedicate any and all copyright interest in the
// software to the public domain. We make this dedication for the benefit
// of the public at large and to the detriment of our heirs and
// successors. We intend this dedication to be an overt act of
// relinquishment in perpetuity of all present and future rights to this
// software under copyright law.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//
//
// For more information, please refer to <https://unlicense.org>
//

#include "easing-rebol-extension.h"

#define COMMAND        int
#define ARG_Double(n)  RXA_DEC64(frm,n)


COMMAND cmd_linear(RXIFRM *frm, void *ctx) {
	return RXR_VALUE;
}

COMMAND cmd_in_quad(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = QuadraticEaseIn(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_out_quad(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = QuadraticEaseOut(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_in_out_quad(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = QuadraticEaseInOut(ARG_Double(1));
	return RXR_VALUE;
}

COMMAND cmd_in_cubic(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = CubicEaseIn(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_out_cubic(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = CubicEaseOut(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_in_out_cubic(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = CubicEaseInOut(ARG_Double(1));
	return RXR_VALUE;
}

COMMAND cmd_in_quart(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = QuarticEaseIn(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_out_quart(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = QuarticEaseOut(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_in_out_quart(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = QuarticEaseInOut(ARG_Double(1));
	return RXR_VALUE;
}

COMMAND cmd_in_quint(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = QuinticEaseIn(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_out_quint(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = QuinticEaseOut(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_in_out_quint(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = QuinticEaseInOut(ARG_Double(1));
	return RXR_VALUE;
}

COMMAND cmd_in_sine(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = SineEaseIn(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_out_sine(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = SineEaseOut(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_in_out_sine(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = SineEaseInOut(ARG_Double(1));
	return RXR_VALUE;
}

COMMAND cmd_in_circ(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = CircularEaseIn(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_out_circ(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = CircularEaseOut(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_in_out_circ(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = CircularEaseInOut(ARG_Double(1));
	return RXR_VALUE;
}

COMMAND cmd_in_expo(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = ExponentialEaseIn(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_out_expo(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = ExponentialEaseOut(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_in_out_expo(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = ExponentialEaseInOut(ARG_Double(1));
	return RXR_VALUE;
}

COMMAND cmd_in_elastic(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = ElasticEaseIn(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_out_elastic(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = ElasticEaseOut(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_in_out_elastic(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = ElasticEaseInOut(ARG_Double(1));
	return RXR_VALUE;
}

COMMAND cmd_in_back(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = BackEaseIn(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_out_back(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = BackEaseOut(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_in_out_back(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = BackEaseInOut(ARG_Double(1));
	return RXR_VALUE;
}

COMMAND cmd_in_bounce(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = BounceEaseIn(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_out_bounce(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = BounceEaseOut(ARG_Double(1));
	return RXR_VALUE;
}
COMMAND cmd_in_out_bounce(RXIFRM *frm, void *ctx) {
	RXA_DEC64(frm, 1) = BounceEaseInOut(ARG_Double(1));
	return RXR_VALUE;
}
