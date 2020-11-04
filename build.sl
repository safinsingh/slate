# !dep()

$style = gcc

!type($style)
!src([
    src/main.c
])

main(
    !build,
    src
)