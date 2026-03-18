# Minishell TODO

## Core Display & Execution (`src/shell/`, `src/commands/`)
- [x] Display a prompt when waiting for a new command
- [x] Have a working history
- [ ] Search and launch the right executable (PATH, relative, absolute)

## Signal Handling & Globals (`src/main.c`)
- [ ] Use at most one global variable for signal numbers only
- [ ] Handle `ctrl-C` (display new prompt on a new line)
- [ ] Handle `ctrl-D` (exit the shell)
- [ ] Handle `ctrl-\` (do nothing)

## Quotes & Parsing (`src/token_handler.c`, `src/commands/`)
- [ ] Do not interpret unclosed quotes
- [ ] Do not interpret unnecessary special characters (e.g., `\`, `;`)
- [ ] Handle `'` (single quote) - no meta-character interpretation inside
- [ ] Handle `"` (double quote) - will interpret only `$`, ignore everything else

## Variables & Expansion (`src/commands/`)
- [ ] Handle environment variables (`$VAR` -> value)
- [ ] Handle `$?` (exit status of the latest foreground pipeline)

## Redirections (`src/commands/`, `src/builtin/`)
- [ ] `<` redirect input
- [ ] `>` redirect output
- [ ] `<<` here-document (read until delimiter, no history update)
- [ ] `>>` redirect output in append mode

## Pipelines (`src/commands/`)
- [ ] Implement `|` (output of command N connected to input of command N+1)

## Built-ins (`src/builtin/`)
- [ ] `echo` with option `-n`
- [ ] `cd` (relative/absolute path)
- [ ] `pwd` (no options)
- [ ] `export` (no options)
- [ ] `unset` (no options)
- [ ] `env` (no options or arguments)
- [ ] `exit` (no options)

## Memory Management (Overall)
- [ ] Ensure no memory leaks in personal code
