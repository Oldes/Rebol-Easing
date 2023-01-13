
//
// auto-generated file, do not modify!
//

#include "common.h"
#include "easing.h"

#define MIN_REBOL_VER 3
#define MIN_REBOL_REV 5
#define MIN_REBOL_UPD 4
#define VERSION(a, b, c) (a << 16) + (b << 8) + c
#define MIN_REBOL_VERSION VERSION(MIN_REBOL_VER, MIN_REBOL_REV, MIN_REBOL_UPD)

enum ext_commands {
	CMD_EASING_LINEAR,
	CMD_EASING_IN_QUAD,
	CMD_EASING_IN_CUBIC,
	CMD_EASING_IN_QUART,
	CMD_EASING_IN_QUINT,
	CMD_EASING_IN_SINE,
	CMD_EASING_IN_CIRC,
	CMD_EASING_IN_EXPO,
	CMD_EASING_IN_ELASTIC,
	CMD_EASING_IN_BACK,
	CMD_EASING_IN_BOUNCE,
	CMD_EASING_OUT_QUAD,
	CMD_EASING_OUT_CUBIC,
	CMD_EASING_OUT_QUART,
	CMD_EASING_OUT_QUINT,
	CMD_EASING_OUT_SINE,
	CMD_EASING_OUT_CIRC,
	CMD_EASING_OUT_EXPO,
	CMD_EASING_OUT_ELASTIC,
	CMD_EASING_OUT_BACK,
	CMD_EASING_OUT_BOUNCE,
	CMD_EASING_IN_OUT_QUAD,
	CMD_EASING_IN_OUT_CUBIC,
	CMD_EASING_IN_OUT_QUART,
	CMD_EASING_IN_OUT_SINE,
	CMD_EASING_IN_OUT_CIRC,
	CMD_EASING_IN_OUT_EXPO,
	CMD_EASING_IN_OUT_ELASTIC,
	CMD_EASING_IN_OUT_BACK,
	CMD_EASING_IN_OUT_BOUNCE,
};


int cmd_linear(RXIFRM *frm, void *ctx);
int cmd_in_quad(RXIFRM *frm, void *ctx);
int cmd_in_cubic(RXIFRM *frm, void *ctx);
int cmd_in_quart(RXIFRM *frm, void *ctx);
int cmd_in_quint(RXIFRM *frm, void *ctx);
int cmd_in_sine(RXIFRM *frm, void *ctx);
int cmd_in_circ(RXIFRM *frm, void *ctx);
int cmd_in_expo(RXIFRM *frm, void *ctx);
int cmd_in_elastic(RXIFRM *frm, void *ctx);
int cmd_in_back(RXIFRM *frm, void *ctx);
int cmd_in_bounce(RXIFRM *frm, void *ctx);
int cmd_out_quad(RXIFRM *frm, void *ctx);
int cmd_out_cubic(RXIFRM *frm, void *ctx);
int cmd_out_quart(RXIFRM *frm, void *ctx);
int cmd_out_quint(RXIFRM *frm, void *ctx);
int cmd_out_sine(RXIFRM *frm, void *ctx);
int cmd_out_circ(RXIFRM *frm, void *ctx);
int cmd_out_expo(RXIFRM *frm, void *ctx);
int cmd_out_elastic(RXIFRM *frm, void *ctx);
int cmd_out_back(RXIFRM *frm, void *ctx);
int cmd_out_bounce(RXIFRM *frm, void *ctx);
int cmd_in_out_quad(RXIFRM *frm, void *ctx);
int cmd_in_out_cubic(RXIFRM *frm, void *ctx);
int cmd_in_out_quart(RXIFRM *frm, void *ctx);
int cmd_in_out_sine(RXIFRM *frm, void *ctx);
int cmd_in_out_circ(RXIFRM *frm, void *ctx);
int cmd_in_out_expo(RXIFRM *frm, void *ctx);
int cmd_in_out_elastic(RXIFRM *frm, void *ctx);
int cmd_in_out_back(RXIFRM *frm, void *ctx);
int cmd_in_out_bounce(RXIFRM *frm, void *ctx);

typedef int (*MyCommandPointer)(RXIFRM *frm, void *ctx);

#define EASING_EXT_INIT_CODE \
	"REBOL [Title: {Rebol Easing Extension} Type: module Exports: [tween]]\n"\
	"linear: command [\"Modeled after the line     y = x\" x [decimal!]]\n"\
	"in-quad: command [\"Modeled after the parabola y = x^^2\" x [decimal!]]\n"\
	"in-cubic: command [\"Modeled after the cubic    y = x^^3\" x [decimal!]]\n"\
	"in-quart: command [\"Modeled after the quartic  y = x^^4\" x [decimal!]]\n"\
	"in-quint: command [\"Modeled after the quintic  y = x^^5\" x [decimal!]]\n"\
	"in-sine: command [\"Modeled after quarter-cycle of sine wave\" x [decimal!]]\n"\
	"in-circ: command [\"Modeled after shifted quadrant IV of unit circle\" x [decimal!]]\n"\
	"in-expo: command [{Modeled after the exponential function y = 2^^(10(x - 1))} x [decimal!]]\n"\
	"in-elastic: command [{Modeled after the damped sine wave y = sin(13pi/2*x)*pow(2, 10 * (x - 1))} x [decimal!]]\n"\
	"in-back: command [{Modeled after the overshooting cubic y = x^^3-x*sin(x*pi)} x [decimal!]]\n"\
	"in-bounce: command [\"\" x [decimal!]]\n"\
	"out-quad: command [\"Modeled after the parabola y = -x^^2 + 2x\" x [decimal!]]\n"\
	"out-cubic: command [\"Modeled after the cubic    y = (x - 1)^^3 + 1\" x [decimal!]]\n"\
	"out-quart: command [\"Modeled after the quartic  y = 1 - (x - 1)^^4\" x [decimal!]]\n"\
	"out-quint: command [\"Modeled after the quintic  y = (x - 1)^^5 + 1\" x [decimal!]]\n"\
	"out-sine: command [{Modeled after quarter-cycle of sine wave (different phase)} x [decimal!]]\n"\
	"out-circ: command [\"Modeled after shifted quadrant II of unit circle\" x [decimal!]]\n"\
	"out-expo: command [{Modeled after the exponential function y = -2^^(-10x) + 1} x [decimal!]]\n"\
	"out-elastic: command [{Modeled after the damped sine wave y = sin(-13pi/2*(x + 1))*pow(2, -10x) + 1} x [decimal!]]\n"\
	"out-back: command [{Modeled after the overshooting cubic y = 1-((1-x)^^3-(1-x)*sin((1-x)*pi))} x [decimal!]]\n"\
	"out-bounce: command [\"\" x [decimal!]]\n"\
	"in-out-quad: command [{Modeled after the piecewise parabola  y = (1/2)((2x)^^2) for x [0, 0.5) and y = -(1/2)((2x-1)*(2x-3) - 1) for x [0.5, 1]} x [decimal!]]\n"\
	"in-out-cubic: command [{Modeled after the piecewise cubic     y = (1/2)((2x)^^3) for x [0, 0.5) and y = (1/2)((2x-2)^^3 + 2) for x [0.5, 1]} x [decimal!]]\n"\
	"in-out-quart: command [{Modeled after the piecewise quadratic y = (1/2)((2x)^^4) for x [0, 0.5) and y = (1/2)((2x-2)^^4 + 2) for x [0.5, 1]} x [decimal!]]\n"\
	"in-out-sine: command [\"Modeled after half sine wave\" x [decimal!]]\n"\
	"in-out-circ: command [{Modeled after the piecewise circular function y = (1/2)(1 - sqrt(1 - 4x^^2)) for x [0, 0.5) and y = (1/2)(sqrt(-(2x - 3)*(2x - 1)) + 1) for x [0.5, 1]} x [decimal!]]\n"\
	"in-out-expo: command [{Modeled after the piecewise exponential y = (1/2)2^^(10(2x - 1)) for x [0, 0.5) and y = y = -(1/2)*2^^(-10(2x - 1))) + 1 for x [0.5, 1]} x [decimal!]]\n"\
	"in-out-elastic: command [{Modeled after the piecewise exponentially-damped sine wave y = (1/2)*sin(13pi/2*(2*x))*pow(2, 10 * ((2*x) - 1)) for x [0, 0.5) and y = (1/2)*(sin(-13pi/2*((2x-1)+1))*pow(2,-10(2*x-1)) + 2) for x [0.5, 1]} x [decimal!]]\n"\
	"in-out-back: command [{Modeled after the piecewise overshooting cubic function y = (1/2)*((2x)3-(2x)*sin(2*x*pi)) for x [0, 0.5) and y = (1/2)*(1-((1-x)3-(1-x)*sin((1-x)*pi))+1) for x [0.5, 1]} x [decimal!]]\n"\
	"in-out-bounce: command [\"\" x [decimal!]]\n"\
	"tween: func [\n"\
	"    {Interpolates a value at t using easing function}\n"\
	"    val1     [number! pair! tuple!] \"Value to interpolate from\"\n"\
	"    val2     [number! pair! tuple!] \"Value to interpolate to\"\n"\
	"    t        [decimal!]             \"Value from 0.0 to 1.0\"\n"\
	"    ease     [any-word!]            \"Easing function\"\n"\
	"][\n"\
	"    t: self/:ease t\n"\
	"    to val1 add val1 * (1 - t) val2 * t\n"\
	"]\n"
