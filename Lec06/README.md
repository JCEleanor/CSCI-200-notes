### Pseudocode

- First step in the design process

### Compiling Your Program

source code (main.cpp)
</br>
->
</br>
<b>compiler</b>
</br>
->
</br>
object file (main.cpp.obj/main.o)
</br>
->
</br>
<b>linker</b> (load inlcuded libs)
</br>
->
</br>
executable (a.out (machine code in RAM))
</br>

#### C++ build process

1. human readable code on Disk
2. object (machine) code on Disk (compiler & linker)
   - compile
   - static linking
3. operating system
   - load & dynamic linking
   - executable program

### Debugging

#### Error types

1. Syntax Errors

- Program will not compile
- Compiler gives you message and line #

2.  Linker Errors

- program will not link
- linker gives you messages

3. Runtime & Logic Errors

- program runs & quits unexpectedly (runtime)
- program runs & produces wrong output (logic, then this is your fault)

#### Compiler Warnings

- NOT compiler errors

  - Nothing wrong syntactically with code
  - Flow, values, etc. not being used correctly
  - Hint that something could go wrong at runtime

• Enable with compiler flags `–Wall -Wextra`

Turns on ALL warnings
`g++ -Wall -Wextra -o main.o -c main.cpp`

#### Print Lines

use `cout` to debug -> might get messy in the future

#### Debugger

- window: gdb
- os: lldb
- run through terminal (need to compile with `-g` to generate debug info)
  `g++ -Wall -Wextra -g -o main.o -c main.cpp`
- add this to your Makefile

```Makefile
CXX = g++
CXXFLAGS_DEBUG = -g
CXXFLAGS_WARN = -Wall -Wextra -Wconversion -Wdouble-promotion -Wunreachable-code -Wshadow -Wpedantic
CPPVERSION = -std=c++17

...

.cpp.o:
	$(CXX) $(CPPVERSION) $(CXXFLAGS_DEBUG) $(CXXFLAGS_WARN) -o $@ -c $<
```

##### <mark>Running Debugger</mark>

# C++ Debugger Commands Reference

| Command            | GDB           | LLDB          | Description                                    |
| ------------------ | ------------- | ------------- | ---------------------------------------------- |
| Set breakpoint     | `b <#>`       | `b <#>`       | Set a breakpoint at line number                |
| Run program        | `run`         | `run`         | Start executing the program                    |
| Print variable     | `print <var>` | `print <var>` | Display the value of a variable                |
| Show breakpoints   | `info b`      | `br l`        | List all current breakpoints                   |
| Step into          | `step`        | `step`        | Execute next line, stepping into functions     |
| Continue execution | `continue`    | `continue`    | Resume program execution until next breakpoint |
| Terminate program  | `kill`        | `kill`        | Stop the currently running program             |
| Quit debugger      | `q`           | `q`           | Exit the debugger                              |

## Additional Notes

- Use `help <command>` in either debugger to get more information about specific commands
- Breakpoints can also be set by function name: `b function_name`

- ==don't== ==use== `goto`
- syntx error, linker error, runtime/logic error (debugged by us)

- use new MakeFile (turns on all warnings)

- run `lldb` or `gdb in windows` to debug
