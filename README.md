[![Rebol-Easing CI](https://github.com/Oldes/Rebol-Easing/actions/workflows/main.yml/badge.svg)](https://github.com/Oldes/Rebol-Easing/actions/workflows/main.yml)

# Rebol/Easing

Collection of easing functions for [Rebol3](https://github.com/Oldes/Rebol3).
Based on Warren Moore's code: https://github.com/warrenm/AHEasing

## Usage
```rebol
ease: import 'easing

;; Using helper `tween` function
;; getting values between 100 and 200 with an in-elastic easing
t: 0.0 loop 21 [
    print [t tab tween 100 200 t 'in-cubic]
    t: t + 0.05
]
;; getting values between black and red colors with an out-elastic easing
t: 0.0 loop 21 [
    print [t tab tween 0.0.0 255.0.0 t 'out-elastic]
    t: t + 0.05
]

;; Using easing natives directly:
probe ease/in-out-quad 0.4
```
