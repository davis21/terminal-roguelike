#pragma once

// Platform-specific terminal input. Only this file and Terminal.cpp
// know how keys are read, so switching platforms means changing only Terminal.cpp.

// Waits for a single key press and returns it, without needing Enter.
char readKey();