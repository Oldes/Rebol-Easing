REBOL [
	title:  "Rebol/Easing module builder"
	type:    module
	date:    13-Jan-2023
	home:    https://github.com/Oldes/Rebol-Easing
	version: 1.0.0
	author: @Oldes
]

;- all extension command specifications ----------------------------------------
;; all commands expects input value in the range 0.0 - 1.0 (no validation!)
commands: [
	linear:         ["Modeled after the line     y = x"    x [decimal!]]
	in-quad:        ["Modeled after the parabola y = x^^2" x [decimal!]]
	in-cubic:       ["Modeled after the cubic    y = x^^3" x [decimal!]]
	in-quart:       ["Modeled after the quartic  y = x^^4" x [decimal!]]
	in-quint:       ["Modeled after the quintic  y = x^^5" x [decimal!]]
	in-sine:        ["Modeled after quarter-cycle of sine wave" x [decimal!]]
	in-circ:        ["Modeled after shifted quadrant IV of unit circle" x [decimal!]]
	in-expo:        ["Modeled after the exponential function y = 2^^(10(x - 1))" x [decimal!]]
	in-elastic:     ["Modeled after the damped sine wave y = sin(13pi/2*x)*pow(2, 10 * (x - 1))" x [decimal!]]
	in-back:        ["Modeled after the overshooting cubic y = x^^3-x*sin(x*pi)" x [decimal!]]
	in-bounce:      ["" x [decimal!]]
	out-quad:       ["Modeled after the parabola y = -x^^2 + 2x"     x [decimal!]]
	out-cubic:      ["Modeled after the cubic    y = (x - 1)^^3 + 1" x [decimal!]]
	out-quart:      ["Modeled after the quartic  y = 1 - (x - 1)^^4" x [decimal!]]
	out-quint:      ["Modeled after the quintic  y = (x - 1)^^5 + 1" x [decimal!]]
	out-sine:       ["Modeled after quarter-cycle of sine wave (different phase)" x [decimal!]]
	out-circ:       ["Modeled after shifted quadrant II of unit circle" x [decimal!]]
	out-expo:       ["Modeled after the exponential function y = -2^^(-10x) + 1" x [decimal!]]
	out-elastic:    ["Modeled after the damped sine wave y = sin(-13pi/2*(x + 1))*pow(2, -10x) + 1" x [decimal!]]
	out-back:       ["Modeled after the overshooting cubic y = 1-((1-x)^^3-(1-x)*sin((1-x)*pi))" x [decimal!]]
	out-bounce:     ["" x [decimal!]]
	in-out-quad:    [{Modeled after the piecewise parabola  y = (1/2)((2x)^^2) for x [0, 0.5) and y = -(1/2)((2x-1)*(2x-3) - 1) for x [0.5, 1]} x [decimal!]]
	in-out-cubic:   [{Modeled after the piecewise cubic     y = (1/2)((2x)^^3) for x [0, 0.5) and y = (1/2)((2x-2)^^3 + 2) for x [0.5, 1]} x [decimal!]]
	in-out-quart:   [{Modeled after the piecewise quadratic y = (1/2)((2x)^^4) for x [0, 0.5) and y = (1/2)((2x-2)^^4 + 2) for x [0.5, 1]} x [decimal!]]
	in-out-sine:    [{Modeled after half sine wave} x [decimal!]]
	in-out-circ:    [{Modeled after the piecewise circular function y = (1/2)(1 - sqrt(1 - 4x^^2)) for x [0, 0.5) and y = (1/2)(sqrt(-(2x - 3)*(2x - 1)) + 1) for x [0.5, 1]} x [decimal!]]
	in-out-expo:    [{Modeled after the piecewise exponential y = (1/2)2^^(10(2x - 1)) for x [0, 0.5) and y = y = -(1/2)*2^^(-10(2x - 1))) + 1 for x [0.5, 1]}x [decimal!]]
	in-out-elastic: [{Modeled after the piecewise exponentially-damped sine wave y = (1/2)*sin(13pi/2*(2*x))*pow(2, 10 * ((2*x) - 1)) for x [0, 0.5) and y = (1/2)*(sin(-13pi/2*((2x-1)+1))*pow(2,-10(2*x-1)) + 2) for x [0.5, 1]} x [decimal!]]
	in-out-back:    [{Modeled after the piecewise overshooting cubic function y = (1/2)*((2x)^3-(2x)*sin(2*x*pi)) for x [0, 0.5) and y = (1/2)*(1-((1-x)^3-(1-x)*sin((1-x)*pi))+1) for x [0.5, 1]} x [decimal!]]
	in-out-bounce:  ["" x [decimal!]]
]

;-------------------------------------- ----------------------------------------
reb-code: {REBOL [Title: {Rebol Easing Extension} Type: module Exports: [tween]]}
enu-commands:  "" ;; command name enumerations
cmd-declares:  "" ;; command function declarations
cmd-dispatch:  "" ;; command functionm dispatcher

;- generate C and Rebol code from the command specifications -------------------
foreach [name spec] commands [
	append reb-code ajoin [lf name ": command "]
	new-line/all spec false
	append/only reb-code mold spec

	name: form name
	replace/all name #"-" #"_"
	
	append enu-commands ajoin ["^/^-CMD_EASING_" uppercase copy name #","]

	append cmd-declares ajoin ["^/int cmd_" name "(RXIFRM *frm, void *ctx);"]
	append cmd-dispatch ajoin ["^-cmd_" name ",^/"]
]

;- additional Rebol initialization code ----------------------------------------
append reb-code {
tween: func [
    {Interpolates a value at t using easing function}
    val1     [number! pair! tuple!] "Value to interpolate from"
    val2     [number! pair! tuple!] "Value to interpolate to"
    t        [decimal!]             "Value from 0.0 to 1.0"
    ease     [any-word!]            "Easing function"
][
    t: self/:ease t
    to val1 add val1 * (1 - t) val2 * t
]}

;print reb-code

;- convert Rebol code to C-string ----------------------------------------------
init-code: copy ""
foreach line split reb-code lf [
	replace/all line #"^"" {\"}
	append init-code ajoin [{\^/^-"} line {\n"}] 
]

;-- C file templates -----------------------------------------------------------
header: {
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

enum ext_commands {$enu-commands
};

$cmd-declares

typedef int (*MyCommandPointer)(RXIFRM *frm, void *ctx);

#define EASING_EXT_INIT_CODE $init-code
}
;;------------------------------------------------------------------------------
ctable: {
//
// auto-generated file, do not modify!
//
#include "easing-rebol-extension.h"
MyCommandPointer Command[] = {
$cmd-dispatch};
}

;- output generated files ------------------------------------------------------
write %easing-rebol-extension.h reword :header self
write %easing-commands-table.c  reword :ctable self

