# an example slate
# build configuration

# !dep([xlib])

$runner = gcc

!run($runner)
!src([
    src/main.c,
    src/util.c,
    src/util.h,
    lang/lex.c,
    lang/lex.h
])

main([
    !build,
    src
])

# !include(cli)
# !include(lang)