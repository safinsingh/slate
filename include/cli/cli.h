#ifndef CLI_CLI_H
#define CLI_CLI_H

#ifndef SLATE_VERSION
#define SLATE_VERSION "0.0.0"
#endif

#define DEFAULT_CONFIG "build.rock"

struct Opts* parse_args(int argc, char** argv);

struct Opts {
    char* config;
};

#endif