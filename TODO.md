# Minishell TODO

## Core Display & Execution
- [x] Display a prompt when waiting for a new command
- [ ] Have a working history
- [ ] Search and launch the right executable (PATH, relative, absolute)

## Signal Handling & Globals
- [ ] Use at most one global variable for signal numbers only
- [ ] Handle `ctrl-C` (display new prompt on a new line)
- [ ] Handle `ctrl-D` (exit the shell)
- [ ] Handle `ctrl-\` (do nothing)

## Quotes & Parsing
- [ ] Do not interpret unclosed quotes
- [ ] Do not interpret unnecessary special characters (e.g., `\`, `;`)
- [ ] Handle `'` (single quote) - no meta-character interpretation inside
- [ ] Handle `"` (double quote) - will interpret only `$`, ignore everything else

## Variables & Expansion
- [ ] Handle environment variables (`$VAR` -> value)
- [ ] Handle `$?` (exit status of the latest foreground pipeline)

## Redirections
- [ ] `<` redirect input
- [ ] `>` redirect output
- [ ] `<<` here-document (read until delimiter, no history update)
- [ ] `>>` redirect output in append mode

## Pipelines
- [ ] Implement `|` (output of command N connected to input of command N+1)

## Built-ins
- [ ] `echo` with option `-n`
- [ ] `cd` (relative/absolute path)
- [ ] `pwd` (no options)
- [ ] `export` (no options)
- [ ] `unset` (no options)
- [ ] `env` (no options or arguments)
- [ ] `exit` (no options)

## Memory Management
- [ ] Ensure no memory leaks in personal code
