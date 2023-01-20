Rebol [
    Title: "Easing graph images generator"
    File:  %gen-graphs.r3
]

ease: import 'easing
b2d:  import 'blend2d

;@@ https://github.com/Oldes/Rebol-issues/issues/884
cfor: func [
    "General loop based on an initial state, test, and per-loop change."
    init [block! object!] "Words & initial values as object spec (local)"
    test [block!] "Continue if condition is true"  ; "true", not "TRUE", since it's conditionally truthy
    bump [block!] "Move to the next step in the loop"
    body [block!] "Block to evaluate each time"
    /local ret
][
    if block? init [init: make object! init]
    test: bind/copy test init
    body: bind/copy body init
    bump: bind/copy bump init
    while test [set/any 'ret do body do bump get/any 'ret]
]

;; So far Blen2D extension does not support font lookup functions
;; As I'm using this script on macOS, I use this system font hardcoded.
helvetica: b2d/font %/System/Library/Fonts/Helvetica.ttc


draw-ease-graph: function[
    img    [image!]
    type   [word!]
    offset [pair!]
][
    points: clear []
    label: form type

    cfor [p: 0x0][p/x <= 150][p: p + 2x0][
        p/y: 100 - (100 * ease/:type (p/x / 150))
        append points p
    ]

    draw img compose [
        ;; graph position
        translate :offset
        ;; axis
        line-width 1 pen black
        translate 10.5x40.5     ;; using half pixel to have a pixel perfect axis lines
        line 0x0 0x100 150x100  ;; axis
        ;; graph
        line-width 2 pen red
        line (points)
        ;; label
        pen off fill 255.255.255.140
        box 0x105 70x20
        fill black
        font :helvetica
        text 0x120 14 :label
    ]
]

n: 0
foreach [name type] [
    "quadratic"   quad
    "cubic"       cubic
    "quartic"     quart
    "sine"        sine
    "circular"    circ
    "exponential" expo
    "elastic"     elastic
    "back"        back
    "bounce"      bounce
][
    ++ n
    img: make image! 580x180
    draw-ease-graph img to word! join "in-" type 0x0
    draw-ease-graph img to word! join "out-" type 200x0
    draw-ease-graph img to word! join "in-out-" type 400x0
    file: as file! ajoin [n %_ease_ type %.png]

    print ajoin ["### Easing " name]
    print ajoin ["![" name "](https://raw.githubusercontent.com/Oldes/Rebol-Easing/main/.github/" file ")"]

    save file img
]

