Rebol [
    title: "Rebol/Easing extension CI test"
]

;; register build directory as a location with existing modules...
supplement system/options/module-paths to-real-file %./build/

;; print content of the module...
ease: import 'easing
? ease

;; try all available easing functions...
easings: [
    linear
    in-quad
    in-cubic
    in-quart
    in-sine
    in-circ
    in-expo
    in-elastic
    in-back
    in-bounce
    out-quad
    out-cubic
    out-quart
    out-sine
    out-circ
    out-expo
    out-elastic
    out-back
    out-bounce
    in-out-quad
    in-out-cubic
    in-out-quart
    in-out-sine
    in-out-circ
    in-out-expo
    in-out-elastic
    in-out-back
    in-out-bounce
]

printf [18 10 10 10 10 10][
    "type      values:"
    0.0 0.25 0.5 0.75 1.0
]
foreach type easings [
    printf [$33 18 $32 10 10 10 10 10] reduce [
        type
        round/to ease/:type 0.0  0.0001
        round/to ease/:type 0.25 0.0001
        round/to ease/:type 0.5  0.0001
        round/to ease/:type 0.75 0.0001
        round/to ease/:type 1.0  0.0001
    ]
]
