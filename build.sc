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

!exec([
    !cmd("echo test"),
    !build(!src),
])

# !include(cli)
# !include(lang)